#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <string>

class Transaccion {
private:
    std::string fecha;
    float litros;
    std::string tipoCombustible;
    std::string metodoPago;
    std::string cliente;
    float monto;

public:
    Transaccion(std::string fecha, float litros, std::string tipoCombustible,
                std::string metodoPago, std::string cliente, float monto);

    std::string obtenerDatos() const;
};

#endif // TRANSACCION_H
