#include "estacionservicio.h"

EstacionServicio::EstacionServicio(std::string nombre, std::string idEstacion, std::string gerente, Region region,
                                   float latitud, float longitud, Tanque tanque, Isla** islas, int cantidadIslas)
    : nombre(nombre), idEstacion(idEstacion), gerente(gerente), region(region), latitud(latitud), longitud(longitud),
    tanque(tanque), numIslas(cantidadIslas) {

    this->islas = new Isla*[cantidadIslas];
    for (int i = 0; i < cantidadIslas; ++i) {
        this->islas[i] = islas[i];
    }
}

EstacionServicio::~EstacionServicio() {
    for (int i = 0; i < numIslas; ++i) {
        delete islas[i];  // Libera cada isla
    }
    delete[] islas;  // Libera el arreglo dinámico
}

std::string EstacionServicio::getIdEstacion() const {
    return idEstacion;
}

std::string EstacionServicio::getNombre() const {
    return nombre;
}

Region EstacionServicio::getRegion() const {
    return region;
}

float EstacionServicio::getLatitud() const {
    return latitud;
}

float EstacionServicio::getLongitud() const {
    return longitud;
}

Tanque EstacionServicio::getTanque() const {
    return tanque;
}

Isla** EstacionServicio::getIslas(int &cantidadIslas) const {
    cantidadIslas = numIslas;
    return islas;
}

