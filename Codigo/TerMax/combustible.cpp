#include "Combustible.h"

// Constructor
Combustible::Combustible(std::string tipo, float precio) : tipoCombustible(tipo), precioCombustible(precio) {}

// Getters
std::string Combustible::getTipoCombustible() const {
    return tipoCombustible;
}

float Combustible::getPrecioCombustible() const {
    return precioCombustible;
}

// Setters
void Combustible::setTipoCombustible(std::string tipo) {
    tipoCombustible = tipo;
}

void Combustible::setPrecioCombustible(float precio) {
    precioCombustible = precio;
}
