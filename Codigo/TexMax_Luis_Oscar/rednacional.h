#ifndef REDNACIONAL_H
#define REDNACIONAL_H

#include "EstacionServicio.h"
class RedNacional
{
private:
    EstacionServicio** estaciones;
    int cantidadEstaciones;
public:
    RedNacional();
    void agregarEstacion(EstacionServicio* estacion);
    void simularVenta(const std::string& codigoEstacion);
    bool verificarFugaCombustible(const std::string& codigoEstacion);
    void mostrarEstaciones () const;
    EstacionServicio** getEstaciones();
    int getCantidadEstaciones();
    ~RedNacional();
};

#endif // REDNACIONAL_H
