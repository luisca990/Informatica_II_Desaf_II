#include "Archivo.h"
#include "venta.h"
#include <iomanip>
#include <iostream>

// Método para guardar una venta en un archivo
void Archivo::guardarVenta(const Venta& venta, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo append
    if (archivo.is_open()) {
        // Escribir los datos de la venta en el archivo
       // archivo << "Fecha: " << std::put_time(&venta.getFechaHora(), "%Y-%m-%d %H:%M:%S") << "\n";
        archivo << "Tipo de Combustible: " << venta.getTipoCombustible().getTipoCombustible() << "\n";
        archivo << "Cantidad: " << venta.getCantidadCombustible() << "\n";
        archivo << "Método de Pago: " << venta.getMetodoPago() << "\n";
        archivo << "ID Cliente: " << venta.getIdCliente() << "\n";
        archivo << "Dinero: " << venta.getDinero() << "\n";
        archivo << "--------------------------\n";
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar la venta.\n";
    }
}

// Método para guardar un combustible en un archivo
void Archivo::guardarCombustible(const Combustible& combustible, const std::string& nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo append
    if (archivo.is_open()) {
        // Escribir los datos del combustible en el archivo
        archivo << "Tipo de Combustible: " << combustible.getTipoCombustible() << "\n";
        archivo << "Precio: " << combustible.getPrecioCombustible() << "\n";
        archivo << "--------------------------\n";
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para guardar el combustible.\n";
    }
}

// Método para leer ventas desde un archivo
void Archivo::leerVentas(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para leer las ventas.\n";
    }
}

// Método para leer combustibles desde un archivo
void Archivo::leerCombustibles(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (archivo.is_open()) {
        std::string linea;
        while (std::getline(archivo, linea)) {
            std::cout << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para leer los combustibles.\n";
    }
}
