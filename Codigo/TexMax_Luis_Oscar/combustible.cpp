#include "Combustible.h"

Combustible::Combustible(std::string tipo, float capacidad, float precio)
    : tipo(tipo), capacidad(capacidad), precioPorLitro(precio) {}

void Combustible::ajustarCapacidad(float cantidad) {
    capacidad -= cantidad;
}

std::string Combustible::obtenerTipo() const {
    return tipo;
}

float Combustible::obtenerCapacidad() const {
    return capacidad;
}

float Combustible::obtenerPrecio() const{
    return precioPorLitro;
}
