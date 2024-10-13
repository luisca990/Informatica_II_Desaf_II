#include "termaxgestionestacion.h"

TermaxGestionEstacion::TermaxGestionEstacion() : numEstaciones(0) {
    estaciones = new EstacionServicio*[10];  // Máximo 10 estaciones inicialmente
}

TermaxGestionEstacion::~TermaxGestionEstacion() {
    for (int i = 0; i < numEstaciones; ++i) {
        delete estaciones[i];  // Libera cada estación
    }
    delete[] estaciones;  // Libera el arreglo dinámico
}

void TermaxGestionEstacion::agregarEstacion(EstacionServicio* estacion) {
    estaciones[numEstaciones++] = estacion;  // Agrega una estación
}

void TermaxGestionEstacion::eliminarEstacion(std::string idEstacion) {
    for (int i = 0; i < numEstaciones; ++i) {
        if (estaciones[i]->getIdEstacion() == idEstacion) {
            delete estaciones[i];  // Libera memoria de la estación
            estaciones[i] = estaciones[--numEstaciones];  // Rellena el hueco
            break;
        }
    }
}

