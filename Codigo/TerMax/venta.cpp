#include "Venta.h"

// Constructor
Venta::Venta(std::tm fechaHora, Combustible tipoCombustible, float cantidadCombustible, std::string metodoPago, std::string idCliente, float dinero)
    : fechaHora(fechaHora), tipoCombustible(tipoCombustible), cantidadCombustible(cantidadCombustible), metodoPago(metodoPago), idCliente(idCliente), dinero(dinero) {}

// Getters
std::tm Venta::getFechaHora() const {
    return fechaHora;
}

Combustible Venta::getTipoCombustible() const {
    return tipoCombustible;
}

float Venta::getCantidadCombustible() const {
    return cantidadCombustible;
}

std::string Venta::getMetodoPago() const {
    return metodoPago;
}

std::string Venta::getIdCliente() const {
    return idCliente;
}

float Venta::getDinero() const {
    return dinero;
}

// Setters
void Venta::setFechaHora(std::tm nuevaFechaHora) {
    fechaHora = nuevaFechaHora;
}

void Venta::setTipoCombustible(Combustible nuevoTipoCombustible) {
    tipoCombustible = nuevoTipoCombustible;
}

void Venta::setCantidadCombustible(float nuevaCantidad) {
    cantidadCombustible = nuevaCantidad;
}

void Venta::setMetodoPago(std::string nuevoMetodoPago) {
    metodoPago = nuevoMetodoPago;
}

void Venta::setIdCliente(std::string nuevoIdCliente) {
    idCliente = nuevoIdCliente;
}

void Venta::setDinero(float nuevoDinero) {
    dinero = nuevoDinero;
}
