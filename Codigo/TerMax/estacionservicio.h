#ifndef ESTACIONSERVICIO_H
#define ESTACIONSERVICIO_H

#include "isla.h"
#include "region.h"
#include "tanque.h"
#include <string>
class EstacionServicio {
private:
    std::string nombre;
    std::string idEstacion;
    std::string gerente;
    Region* region;
    float latitud;
    float longitud;
    Tanque tanque;
    Isla** islas;   // Arreglo dinámico de punteros a Isla
    int numIslas;

public:
    EstacionServicio();
    EstacionServicio(std::string, std::string, std::string, Region*, float, float, Tanque, Isla** islas, int cantidadIslas);
    ~EstacionServicio();  // Destructor para liberar memoria
    std::string getIdEstacion() const;
    std::string getNombre() const;
    Region* getRegion() const;
    float getLatitud() const;
    float getLongitud() const;
    Tanque getTanque() const;
    void setNombre(std::string nombreE);
    void setIdEstacion(std::string idestacion);
    void setGerente(std::string gerenteE);
    void setLatitud(float latitudE);
    void setLongitud(float longitudE);
    void setRegion(Region* region);
    Isla** getIslas(int &cantidadIslas) const;
};


#endif // ESTACIONSERVICIO_H
