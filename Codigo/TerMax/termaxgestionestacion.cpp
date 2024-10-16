#include "termaxgestionestacion.h"
#include <iostream>

TermaxGestionEstacion::TermaxGestionEstacion() : numEstaciones(0), capacidad(10) {
    estaciones = new EstacionServicio[capacidad];  // Máximo 10 estaciones inicialmente
}

TermaxGestionEstacion::~TermaxGestionEstacion() {
    delete[] estaciones;  // Libera el arreglo dinámico
}

void TermaxGestionEstacion::redimensionar() {
    // Duplicar la capacidad cuando se alcanza el límite
    capacidad *= 2;
    EstacionServicio* nuevoArreglo = new EstacionServicio[capacidad];

    // Copiar los datos del arreglo antiguo al nuevo
    for (int i = 0; i < numEstaciones; ++i) {
        nuevoArreglo[i] = estaciones[i];
    }

    // Liberar la memoria del arreglo antiguo
    delete[] estaciones;

    // Asignar el nuevo arreglo al puntero
    estaciones = nuevoArreglo;
}

void TermaxGestionEstacion::agregarEstacion(EstacionServicio *estacion) {
    if (numEstaciones >= capacidad) {
        redimensionar();  // Si llegamos al límite, redimensionar el arreglo
    }
    estaciones[numEstaciones++] = *estacion;  // Agrega la estación
}

void TermaxGestionEstacion::eliminarEstacion(std::string idEstacion) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i].getIdEstacion() == idEstacion) {
            estaciones[i] = estaciones[--numEstaciones];  // Rellena el hueco
            break;
        }
    }
}

EstacionServicio* TermaxGestionEstacion::buscarEstacionPorId(std::string idEstacion) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i].getIdEstacion() == idEstacion) {
            return &estaciones[i];  // Retorna un puntero a la estación encontrada
        }
    }
    return nullptr;  // Si no se encuentra la estación, retorna nullptr
}

EstacionServicio* TermaxGestionEstacion::getDevolverEstaciones() {
    return estaciones;
}

int TermaxGestionEstacion::getNumEstaciones(){
    return numEstaciones;
}
