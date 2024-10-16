#include "EstacionServicio.h"
#include <cstdlib>
#include <iostream>

int EstacionServicio::generadorCodigoEstacion = 1000;

EstacionServicio::EstacionServicio(std::string nombre, std::string gerente, std::string region)
    : codigo(generarCodigo()), nombre(nombre), gerente(gerente), region(region), surtidores(nullptr), cantidadSurtidores(0) {
    tanques[0] = new Combustible("Regular", 5000, 150);
    tanques[1] = new Combustible("Premium", 7000, 100);
    tanques[2] = new Combustible("EcoExtra", 6000, 120);
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
    float litrosSolicitados = 3 + (rand() % 18);

    Transaccion* transaccion = surtidorActivo->simularVenta(litrosSolicitados,
                                                            tanques[tipoCombustible]->obtenerTipo());
    tanques[tipoCombustible]->ajustarCapacidad(litrosSolicitados);

    std::cout << "Venta simulada: " << transaccion->obtenerDatos() << "\n";
}

bool EstacionServicio::verificarCapacidad() const {
    float capacidadActual = tanques[0]->obtenerCapacidad() +
                            tanques[1]->obtenerCapacidad() +
                            tanques[2]->obtenerCapacidad();
    return (capacidadActual / (5000 + 7000 + 6000)) >= 0.95;
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

EstacionServicio::~EstacionServicio() {
    delete tanques[0];
    delete tanques[1];
    delete tanques[2];
    for (int i = 0; i < cantidadSurtidores; ++i) {
        delete surtidores[i];
    }
    delete[] surtidores;
}
