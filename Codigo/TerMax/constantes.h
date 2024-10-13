#ifndef CONSTANTES_H
#define CONSTANTES_H

// Definir un array constante con las opciones de pago
#include <string>
const std::string opcionesPago[] = { "Efectivo", "TDebito", "TCredito" };
void menuGestionRed() {
    printf("\n===== Gestión de la Red =====\n");
    printf("  1. Agregar estaciones de servicio.\n");
    printf("  2. Eliminar una E/S de la red nacional.\n");
    printf("  3. Calcular el monto total de las ventas en cada E/S del país.\n");
    printf("  4. Fijar los precios del combustible para toda la red.\n");
    printf("  5. Volver al menú principal.\n");
    printf("==============================\n");
    printf("Seleccione una opción: ");
}

void menuGestionEstacion() {
    printf("\n=== Gestión de Estaciones de Servicio ===\n");
    printf("  1. Agregar un surtidor a una E/S.\n");
    printf("  2. Eliminar un surtidor de una E/S.\n");
    printf("  3. Activar un surtidor de una E/S.\n");
    printf("  4. Desactivar un surtidor de una E/S.\n");
    printf("  5. Consultar el histórico de transacciones de cada surtidor.\n");
    printf("  6. Reportar la cantidad de litros vendida según cada categoría de combustible.\n");
    printf("  7. Simular una venta de combustible.\n");
    printf("  8. Asignar la capacidad del tanque de suministro aleatoriamente.\n");
    printf("  9. Volver al menú principal.\n");
    printf("=========================================\n");
    printf("Seleccione una opción: ");
}

void menuPrincipal(){
    printf("\n===== Menú Principal =====\n");
    printf("  1. Gestión de la Red.\n");
    printf("  2. Gestión de Estaciones de Servicio.\n");
    printf("  3. Salir.\n");
    printf("===========================\n");
    printf("Seleccione una opción: ");
}

#endif // CONSTANTES_H
