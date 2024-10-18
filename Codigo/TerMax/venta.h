#ifndef VENTA_H
#define VENTA_H

#include "combustible.h"
#include <ctime>

class Venta {
private:
    std::tm fechaHora;
    Combustible tipoCombustible;
    float cantidadCombustible;
    std::string metodoPago;
    std::string idCliente;
    float dinero;

public:
    Venta(std::tm, Combustible, float, std::string, std::string, float);
    std::tm getFechaHora() const;
    Combustible getTipoCombustible() const;
    float getCantidadCombustible() const;
    std::string getMetodoPago() const;
    std::string getIdCliente() const;
    float getDinero() const;
    void setFechaHora(std::tm fechaHora);
    void setTipoCombustible(Combustible tipoCombustible);
    void setCantidadCombustible(float cantidadCombustible);
    void setMetodoPago(std::string metodoPago);
    void setIdCliente(std::string idCliente);
    void setDinero(float dinero);
};


#endif // VENTA_H
