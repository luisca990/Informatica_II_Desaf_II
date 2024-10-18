#ifndef SURTIDOR_H
#define SURTIDOR_H

#include <string>
#include "Transaccion.h"
#include "utils.h"


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
    Transaccion* simularVenta(float litros, std::string tipo, float precio);
    float calcularMonto(float litros, std::string tipo, float precio);
    bool estaActivo() const;
    void actualizarEstado(bool estado);
    int obtenerCodigo() const;
    std::string getModelo();
    ventasCategoria getVentasEstacion();
    ventasCategoria getVentasEstacionLitros();
    ~Surtidor();
};

#endif // SURTIDOR_H
