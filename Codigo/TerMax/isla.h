#ifndef ISLA_H
#define ISLA_H

#include "surtidor.h"
#include <string>
class Isla {
private:
    std::string idIsla;
    Surtidor** surtidores;  // Arreglo dinámico de punteros a Surtidor
    int numSurtidores;

public:
    Isla(std::string);
    ~Isla();  // Destructor para liberar memoria
    std::string getIdIsla() const;
    void setIdIsla(std::string id);
    Surtidor** getSurtidores(int &cantidadSurtidores) const;
    void agregarSurtidor(Surtidor* surtidor);
    void eliminarSurtidor(std::string codigo);
};


#endif // ISLA_H
