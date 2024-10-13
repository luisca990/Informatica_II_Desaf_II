#include "surtidor.h"
#include "venta.h"

Surtidor::Surtidor(std::string cod, std::string modelo, bool est) : codigo(cod), modeloMaquina(modelo), estado(est), numVentas(0) {
    ventas = new Venta*[100];  // Suponemos un máximo de 100 ventas, puedes ajustar según necesidad
}

Surtidor::~Surtidor() {
    for (int i = 0; i < numVentas; i++) {
        delete ventas[i];  // Libera cada venta almacenada
    }
    delete[] ventas;  // Libera el arreglo dinámico de ventas
}

void Surtidor::registrarVenta(Venta* venta) {
    ventas[numVentas++] = venta;  // Añade venta al arreglo
}

Venta** Surtidor::consultarTransacciones(int &cantidadVentas) const {
    cantidadVentas = numVentas;
    return ventas;  // Retorna el arreglo de ventas y la cantidad de ventas
}
