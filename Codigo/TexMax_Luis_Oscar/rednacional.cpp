#include "rednacional.h"
#include <iostream>

RedNacional::RedNacional() : estaciones(nullptr), cantidadEstaciones(0) {}

void RedNacional::agregarEstacion(EstacionServicio* estacion) {
    EstacionServicio** nuevo = new EstacionServicio*[cantidadEstaciones + 1];
    for (int i = 0; i < cantidadEstaciones; ++i) {
        nuevo[i] = estaciones[i];
    }
    nuevo[cantidadEstaciones] = estacion;
    delete[] estaciones;
    estaciones = nuevo;
    cantidadEstaciones++;
}

void RedNacional::simularVenta(const std::string& codigoEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->obtenerCodigo() == codigoEstacion) {
            estaciones[i]->simularVenta();
            return;
        }
    }
    std::cout << "Estación no encontrada.\n";
}

bool RedNacional::verificarFugaCombustible(const std::string& codigoEstacion) {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        if (estaciones[i]->obtenerCodigo() == codigoEstacion) {
            return estaciones[i]->verificarCapacidad();
        }
    }
    std::cout << "Estación no encontrada.\n";
    return false;
}

void RedNacional::mostrarEstaciones() const {
    std::cout << "Estaciones de servicio en la red:\n";
    for (int i = 0; i < cantidadEstaciones; ++i) {
        std::cout << "Código: " << estaciones[i]->obtenerCodigo()
                  << ", Nombre: " << estaciones[i]->obtenerNombre()
                  << ", Gerente: " << estaciones[i]->obtenerGerente()
                  << ", Región: " << estaciones[i]->obtenerRegion() << "\n";
    }
}

EstacionServicio** RedNacional::getEstaciones(){
    return estaciones;
}

int RedNacional::getCantidadEstaciones(){
    return cantidadEstaciones;
}

RedNacional::~RedNacional() {
    for (int i = 0; i < cantidadEstaciones; ++i) {
        delete estaciones[i];
    }
    delete[] estaciones;
}

