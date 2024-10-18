#include "transaccion.h"

Transaccion::Transaccion(std::string fecha, float litros, std::string tipoCombustible,
                         std::string metodoPago, std::string cliente, float monto)
    : fecha(fecha), litros(litros), tipoCombustible(tipoCombustible),
    metodoPago(metodoPago), cliente(cliente), monto(monto) {}

std::string Transaccion::obtenerDatos() const {
    return "Fecha: " + fecha + ", Litros: " + std::to_string(litros) +
           ", Tipo: " + tipoCombustible +", Método de pago: "+metodoPago+ ", Cliente: " + cliente +
           ", Monto: " + std::to_string(monto);
}

// Getters implementation

std::string Transaccion::getFecha() const {
    return fecha;
}

float Transaccion::getLitros() const {
    return litros;
}

std::string Transaccion::getTipoCombustible() const {
    return tipoCombustible;
}

std::string Transaccion::getMetodoPago() const {
    return metodoPago;
}

std::string Transaccion::getCliente() const {
    return cliente;
}

float Transaccion::getMonto() const {
    return monto;
}

