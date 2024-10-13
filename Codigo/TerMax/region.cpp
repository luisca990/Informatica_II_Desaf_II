#include "region.h"

Region::Region(std::string nombre, Combustible** tipos, int cantidad) : nombre(nombre), numCombustibles(cantidad) {
    tiposCombustibles = new Combustible*[numCombustibles];
    for (int i = 0; i < numCombustibles; ++i) {
        tiposCombustibles[i] = tipos[i];
    }
}

Region::~Region() {
    for (int i = 0; i < numCombustibles; ++i) {
        delete tiposCombustibles[i];  // Libera cada Combustible
    }
    delete[] tiposCombustibles;  // Libera el arreglo dinámico
}

std::string Region::getNombre() const {
    return nombre;
}

Combustible** Region::getTiposCombustibles(int &cantidadCombustibles) const {
    cantidadCombustibles = numCombustibles;
    return tiposCombustibles;
}

void Region::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Region::setTiposCombustibles(Combustible** combustibles, int cantidad) {
    for (int i = 0; i < numCombustibles; ++i) {
        delete tiposCombustibles[i];
    }
    delete[] tiposCombustibles;

    numCombustibles = cantidad;
    tiposCombustibles = new Combustible*[numCombustibles];
    for (int i = 0; i < numCombustibles; ++i) {
        tiposCombustibles[i] = combustibles[i];
    }
}

void Region::definirCombustible(short indice, Combustible* combustible) {
    if (indice >= 0 && indice < numCombustibles) {
        tiposCombustibles[indice] = combustible;
    }
}
