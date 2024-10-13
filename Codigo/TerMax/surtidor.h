#ifndef SURTIDOR_H
#define SURTIDOR_H

#include "venta.h"
#include <string>

class Surtidor {
private:
    std::string codigo;
    std::string modeloMaquina;
    bool estado;
    Venta** ventas;   // Arreglo dinámico de punteros a Ventas
    int numVentas;

public:
    Surtidor(std::string, std::string, bool);
    ~Surtidor();  // Destructor para liberar memoria
    std::string getCodigo() const;
    std::string getModeloMaquina() const;
    bool getEstadoSurtidor() const;
    void setCodigo(std::string codigo);
    void setModeloMaquina(std::string modelo);
    void setEstadoSurtidor(bool estado);
    void registrarVenta(Venta* venta);  // Recibe puntero a venta
    Venta** consultarTransacciones(int &cantidadVentas) const;
};


#endif // SURTIDOR_H
