#include "archivo.h"

// Método para guardar una venta en un archivo
void Archivo::guardarTransaccion(Transaccion *venta, std::string nombreArchivo) {
    std::ofstream archivo(nombreArchivo, std::ios::app); // Abrir en modo append
    if (archivo.is_open()) {
        // Escribir los datos de la venta en el archivo
        archivo << "Fecha: " << venta->getFecha() << "\n";
        archivo << "Tipo de Combustible: " << venta->getTipoCombustible()<< "\n";
        archivo << "Cantidad: " << std::to_string(venta->getLitros()) << "\n";
        archivo << "Método de Pago: " << venta->getMetodoPago() << "\n";
        archivo << "ID Cliente: " << venta->getCliente() << "\n";
        archivo << "Dinero: " << std::to_string(venta->getMonto()) << "\n";
        archivo << "--------------------------\n";
        archivo.close();

    } else {
        std::cerr << "No se pudo abrir el archivo para guardar la venta.\n";
    }
}


// Método para leer ventas desde un archivo
void Archivo::leerVentas(const std::string nombreArchivo) {
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
