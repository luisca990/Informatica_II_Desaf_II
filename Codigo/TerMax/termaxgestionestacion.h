#ifndef TERMAXGESTIONESTACION_H
#define TERMAXGESTIONESTACION_H

#include "estacionservicio.h"
class TermaxGestionEstacion {
private:
    EstacionServicio** estaciones;  // Arreglo dinámico de punteros a EstacionServicio
    int numEstaciones;

public:
    TermaxGestionEstacion();
    ~TermaxGestionEstacion();  // Destructor para liberar memoria
    void agregarEstacion(EstacionServicio* estacion);
    void eliminarEstacion(std::string idEstacion);
};


#endif // TERMAXGESTIONESTACION_H
