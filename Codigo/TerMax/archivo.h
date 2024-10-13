#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <iostream>
#include <fstream>
#include <string>
#include "Venta.h"
#include "Combustible.h"
// Incluye otros headers necesarios para las clases que se vayan a almacenar

class Archivo {
public:
    // Método para guardar una venta en un archivo
    void guardarVenta(const Venta& venta, const std::string& nombreArchivo);

    // Método para guardar un combustible en un archivo
    void guardarCombustible(const Combustible& combustible, const std::string& nombreArchivo);

    // Método para leer ventas desde un archivo
    void leerVentas(const std::string& nombreArchivo);

    // Método para leer combustibles desde un archivo
    void leerCombustibles(const std::string& nombreArchivo);
};

#endif // ARCHIVO_H
