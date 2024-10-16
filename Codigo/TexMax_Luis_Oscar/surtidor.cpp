#include "Surtidor.h"
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
    Transaccion* t = new Transaccion("2024-10-15", litros, tipo, "Efectivo", "Cliente123", monto);
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


Surtidor::~Surtidor() {
    for (int i = 0; i < cantidadTransacciones; ++i) {
        delete transacciones[i];
    }
    delete[] transacciones;
}
