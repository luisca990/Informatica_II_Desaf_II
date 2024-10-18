#ifndef COMBUSTIBLE_H
#define COMBUSTIBLE_H

#include <string>

class Combustible {
private:
    std::string tipo;
    float capacidad;
    float precioPorLitro;

public:
    Combustible(std::string tipo, float capacidad, float precio);
    void ajustarCapacidad(float cantidad);
    std::string obtenerTipo() const;
    float obtenerCapacidad() const;
    float obtenerPrecio() const;
};

#endif // COMBUSTIBLE_H
