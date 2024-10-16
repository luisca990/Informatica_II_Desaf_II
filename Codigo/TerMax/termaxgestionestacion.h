#ifndef TERMAXGESTIONESTACION_H
#define TERMAXGESTIONESTACION_H

#include "estacionservicio.h"
class TermaxGestionEstacion {
private:
    EstacionServicio* estaciones;  // Arreglo dinámico de objetos EstacionServicio
    int numEstaciones;
    int capacidad;

    void redimensionar();  // Método privado para redimensionar el arreglo

public:
    TermaxGestionEstacion();
    ~TermaxGestionEstacion();  // Destructor para liberar memoria
    EstacionServicio* getDevolverEstaciones();
    void agregarEstacion(EstacionServicio* estacion);
    void eliminarEstacion(std::string idEstacion);
    EstacionServicio* buscarEstacionPorId(std::string idEstacion);
    int getNumEstaciones();
};

#endif // TERMAXGESTIONESTACION_H
