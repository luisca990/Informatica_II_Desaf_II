#ifndef REGION_H
#define REGION_H

#include "combustible.h"
#include <string>
class Region {
private:
    std::string nombre;
    Combustible** tiposCombustibles;  // Arreglo dinámico de punteros a Combustible
    int numCombustibles;

public:
    Region(std::string, Combustible** tipos, int cantidad);
    ~Region();  // Destructor para liberar memoria
    std::string getNombre() const;
    Combustible** getTiposCombustibles(int &cantidadCombustibles) const;
    void setNombre(std::string nombre);
    void setTiposCombustibles(Combustible** combustibles, int cantidad);
    void definirCombustible(short indice, Combustible* combustible);
};


#endif // REGION_H
