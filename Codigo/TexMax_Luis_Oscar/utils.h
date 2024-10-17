#ifndef UTILS_H
#define UTILS_H


#include <string>

struct ventasCategoria {
    float Regular=0.0;
    float Premium=0.0;
    float EcoExtra=0.0;
};
const std::string opcionesPago[] = { "Efectivo", "TDebito", "TCredito" };
short generarNumeroAleatorio(short inicio, short fin);
std::string leerString(const char* mensaje);

float leerFloat(const char* mensaje);

int leerEntero(const char* mensaje);
std::string obtenerFechaActual();

#endif // UTILS_H
