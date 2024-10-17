#include "Surtidor.h"
#include "utils.h"
#include <cstdlib>

int Surtidor::generadorCodigo = 0;



Surtidor::Surtidor(std::string modelo)
    : codigo(++generadorCodigo), modelo(modelo), activo(true),
    transacciones(nullptr), cantidadTransacciones(0) {}

void Surtidor::registrarVenta(Transaccion* transaccion) {
    Transaccion** nuevo = new Transaccion*[cantidadTransacciones + 1];
    for (int i = 0; i < cantidadTransacciones; ++i) {
        nuevo[i] = transacciones[i];
    }
    nuevo[cantidadTransacciones] = transaccion;
    delete[] transacciones;
    transacciones = nuevo;
    cantidadTransacciones++;
}

Transaccion* Surtidor::simularVenta(float litros, std::string tipo) {
    float monto = calcularMonto(litros, tipo);
    Transaccion* t = new Transaccion(obtenerFechaActual(), litros, tipo, opcionesPago[generarNumeroAleatorio(0,2)], "Cliente "+std::to_string(generarNumeroAleatorio(0,2)), monto);
    registrarVenta(t);
    return t;
}

float Surtidor::calcularMonto(float litros, std::string tipo) {
    return litros * 5000.0f;
}

bool Surtidor::estaActivo() const {
    return activo;
}

void Surtidor::actualizarEstado(bool estado) {
    activo = estado;
}

int Surtidor::obtenerCodigo() const {
    return codigo;
}
std::string  Surtidor::getModelo(){
    return modelo;
}

ventasCategoria Surtidor::getVentasEstacion(){
    ventasCategoria ventasCat;
    for(int i=0;i<cantidadTransacciones;i++){
        if(transacciones[i]->getTipoCombustible()=="Regular"){
            ventasCat.Regular+=transacciones[i]->getMonto();
        }else if(transacciones[i]->getTipoCombustible()=="Premium"){
            ventasCat.Premium+=transacciones[i]->getMonto();
        }else{
            ventasCat.EcoExtra+=transacciones[i]->getMonto();
        }
    }
    return ventasCat;
}

ventasCategoria Surtidor::getVentasEstacionLitros(){
    ventasCategoria ventasCat;
    for(int i=0;i<cantidadTransacciones;i++){
        if(transacciones[i]->getTipoCombustible()=="Regular"){
            ventasCat.Regular+=transacciones[i]->getLitros();
        }else if(transacciones[i]->getTipoCombustible()=="Premium"){
            ventasCat.Premium+=transacciones[i]->getLitros();
        }else{
            ventasCat.EcoExtra+=transacciones[i]->getLitros();
        }
    }
    return ventasCat;
}

Surtidor::~Surtidor() {
    for (int i = 0; i < cantidadTransacciones; ++i) {
        delete transacciones[i];
    }
    delete[] transacciones;
}
