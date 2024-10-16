#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <string>
#include "Transaccion.h"

class Surtidor {
private:
    static int generadorCodigo;
    int codigo;
    std::string modelo;
    bool activo;
    Transaccion** transacciones;
    int cantidadTransacciones;

public:
    Surtidor(std::string modelo);
    void registrarVenta(Transaccion* transaccion);
    Transaccion* simularVenta(float litros, std::string tipo);
    float calcularMonto(float litros, std::string tipo);
    bool estaActivo() const;
    void actualizarEstado(bool estado);
    int obtenerCodigo() const;
    ~Surtidor();
};

#endif // SURTIDOR_H
