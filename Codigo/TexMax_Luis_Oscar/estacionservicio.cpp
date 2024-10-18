#include "EstacionServicio.h"
#include "archivo.h"
#include "utils.h"
#include <cstdlib>
#include <iostream>

int EstacionServicio::generadorCodigoEstacion = 1000;

EstacionServicio::EstacionServicio(std::string nombre, std::string gerente, std::string region)
    : codigo(generarCodigo()), nombre(nombre), gerente(gerente), region(region), surtidores(nullptr), cantidadSurtidores(0) {
    capacidadInicialTanque[0]=generarNumeroAleatorio(100,200);
    capacidadInicialTanque[1]=generarNumeroAleatorio(100,200);
    capacidadInicialTanque[2]=generarNumeroAleatorio(100,200);
    tanques[0] = new Combustible("Regular",capacidadInicialTanque[0] , leerFloat("Ingrese el precio para combustible Regular: "));
    tanques[1] = new Combustible("Premium", capacidadInicialTanque[1], leerFloat("Ingrese el precio para combustible Premium: "));
    tanques[2] = new Combustible("EcoExtra", capacidadInicialTanque[2], leerFloat("Ingrese el precio para combustible EcoExtra: "));
}

std::string EstacionServicio::generarCodigo() {
    return "E-" + std::to_string(++generadorCodigoEstacion);
}

void EstacionServicio::agregarSurtidor(Surtidor* surtidor) {
    Surtidor** nuevo = new Surtidor*[cantidadSurtidores + 1];
    for (int i = 0; i < cantidadSurtidores; ++i) {
        nuevo[i] = surtidores[i];
    }
    nuevo[cantidadSurtidores] = surtidor;
    delete[] surtidores;
    surtidores = nuevo;
    cantidadSurtidores++;
}

void EstacionServicio::simularVenta() {
    if (cantidadSurtidores == 0) {
        std::cout << "No hay surtidores en la estación.\n";
        return;
    }

    Surtidor* surtidorActivo = nullptr;
    while (!surtidorActivo) {
        int indice = rand() % cantidadSurtidores;
        if (surtidores[indice]->estaActivo()) {
            surtidorActivo = surtidores[indice];
        }
    }


    int tipoCombustible = rand() % 3;
    float litrosSolicitados =generarNumeroAleatorio(3,20);

    Transaccion* transaccion = surtidorActivo->simularVenta(litrosSolicitados,
                                                            tanques[tipoCombustible]->obtenerTipo(),tanques[tipoCombustible]->obtenerPrecio());
    tanques[tipoCombustible]->ajustarCapacidad(litrosSolicitados);

    std::cout << "Venta simulada: " << transaccion->obtenerDatos() << "\n";
    Archivo archivo;
    archivo.guardarTransaccion(transaccion, "Surtidor "+codigo+"_"+std::to_string(surtidorActivo->obtenerCodigo())+".txt");


}

bool EstacionServicio::verificarCapacidad() const {
    float capacidadActual = tanques[0]->obtenerCapacidad() +
                            tanques[1]->obtenerCapacidad() +
                            tanques[2]->obtenerCapacidad();
    return (capacidadActual / (capacidadInicialTanque[0] + capacidadInicialTanque[1] + capacidadInicialTanque[
    2])) >= 0.95;
}

std::string EstacionServicio::obtenerCodigo() const {
    return codigo;
}

std::string EstacionServicio::obtenerNombre() const {
    return nombre;
}

std::string EstacionServicio::obtenerGerente() const {
    return gerente;
}

std::string EstacionServicio::obtenerRegion() const {
    return region;
}
Surtidor** EstacionServicio::getSurtidores(){
    return surtidores;
}

int EstacionServicio::getCantidadSurtidores(){
    return cantidadSurtidores;
}

void EstacionServicio::mostrarSurtidores() const {
    std::cout << "surtidores de la estación de servicio:\n";
    for (int i = 0; i < cantidadSurtidores; ++i) {
        std::cout << "Código: " << surtidores[i]->obtenerCodigo()
                  << ", Modelo: " << surtidores[i]->getModelo()
                  << ", Estado: " << surtidores[i]->estaActivo()<< "\n";
    }

}
EstacionServicio::~EstacionServicio() {
    delete tanques[0];
    delete tanques[1];
    delete tanques[2];
    for (int i = 0; i < cantidadSurtidores; ++i) {
        delete surtidores[i];
    }
    delete[] surtidores;
}
