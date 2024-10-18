#include "isla.h"

Isla::Isla(std::string id) : idIsla(id), numSurtidores(0) {
    surtidores = new Surtidor*[10];  // Máximo 10 surtidores
}

Isla::~Isla() {
    for (int i = 0; i < numSurtidores; i++) {
        delete surtidores[i];  // Libera cada surtidor
    }
    delete[] surtidores;  // Libera el arreglo de surtidores
}

void Isla::agregarSurtidor(Surtidor* surtidor) {
    surtidores[numSurtidores++] = surtidor;
}

Surtidor** Isla::getSurtidores(int &cantidadSurtidores) const {
    cantidadSurtidores = numSurtidores;
    return surtidores;
}

