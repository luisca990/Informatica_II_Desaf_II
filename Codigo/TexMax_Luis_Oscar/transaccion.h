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

    std::string getFecha() const;
    float getLitros() const;
    std::string getTipoCombustible() const;
    std::string getMetodoPago() const;
    std::string getCliente() const;
    float getMonto() const;
};

#endif // TRANSACCION_H
