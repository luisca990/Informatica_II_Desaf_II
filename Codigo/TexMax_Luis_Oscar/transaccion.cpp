#include "transaccion.h"

Transaccion::Transaccion(std::string fecha, float litros, std::string tipoCombustible,
                         std::string metodoPago, std::string cliente, float monto)
    : fecha(fecha), litros(litros), tipoCombustible(tipoCombustible),
    metodoPago(metodoPago), cliente(cliente), monto(monto) {}

std::string Transaccion::obtenerDatos() const {
    return "Fecha: " + fecha + ", Litros: " + std::to_string(litros) +
           ", Tipo: " + tipoCombustible + ", Cliente: " + cliente +
           ", Monto: " + std::to_string(monto);
}
