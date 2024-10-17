#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include <string>
#include "Combustible.h"
#include "Surtidor.h"

class EstacionServicio {
private:
    static int generadorCodigoEstacion;
    std::string codigo;
    std::string nombre;
    std::string gerente;
    std::string region;
    Combustible* tanques[3];
    short capacidadInicialTanque[3];
    Surtidor** surtidores;
    int cantidadSurtidores;

    std::string generarCodigo();

public:
    EstacionServicio(std::string nombre, std::string gerente, std::string region);
    void agregarSurtidor(Surtidor* surtidor);
    void simularVenta();
    bool verificarCapacidad() const;
    std::string obtenerCodigo() const;
    std::string obtenerNombre() const;
    std::string obtenerGerente() const;
    std::string obtenerRegion() const;
    Surtidor** getSurtidores();
    void mostrarSurtidores() const ;
    int getCantidadSurtidores();

    ~EstacionServicio();
};

#endif // ESTACIONSERVICIO_H
