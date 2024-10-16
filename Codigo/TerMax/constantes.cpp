#include "constantes.h"
#include <cstdlib>  // Para rand() y srand()
#include <ctime>
#include <iostream>


Region** regiones= new Region*[3];
Combustible** tiposRegionCentro = new Combustible*[3];
Combustible** tiposRegionNorte = new Combustible*[3];
Combustible** tiposRegionSur = new Combustible*[3];


std::string leerString(const char* mensaje) {
    char input[100];              // Espacio para almacenar el string temporalmente
    printf("%s", mensaje);         // Mostrar mensaje
    scanf("%s", input);            // Leer el input como char array
    return std::string(input);     // Convertir char[] a std::string y devolverlo
}

float leerFloat(const char* mensaje) {
    float valor;
    printf("%s", mensaje);  // Mostrar mensaje
    scanf("%f", &valor);    // Leer float
    return valor;           // Retornar el valor leído
}

int leerEntero(const char* mensaje) {
    int valor;
    printf("%s", mensaje);  // Mostrar mensaje
    scanf("%d", &valor);    // Leer float
    return valor;           // Retornar el valor leído
}

Region** inicializarCombustiblesRegiones(){

    //---------------Inicio precios combustibles para la región centro---------------------
    Combustible* regularRegionCentroR = new Combustible("Regular", leerFloat("Asignar precio del combustible Regular de la Región Centro: "));
    Combustible* regularRegionCentroP = new Combustible("Premium", leerFloat("Asignar precio del combustible Premium de la Región Centro: "));
    Combustible* regularRegionCentroE = new Combustible("EcoExtra", leerFloat("Asignar precio del combustible EcoExtra de la Región Centro: "));
    //---------------Fin precios combustibles para la región centro-----------------------

    //---------------Inicio precios combustibles para la región Norte--------------------
    Combustible* regularRegionNorteR = new Combustible("Regular", leerFloat("Asignar precio del combustible Regular de la Región Norte: "));
    Combustible* regularRegionNorteP = new Combustible("Premium", leerFloat("Asignar precio del combustible Premium de la Región Norte: "));
    Combustible* regularRegionNorteE = new Combustible("EcoExtra", leerFloat("Asignar precio del combustible EcoExtra de la Región Norte: "));
    //---------------Fin precios combustibles para la región Norte----------------------

    //---------------Inicio precios combustibles para la región Sur--------------------
    Combustible* regularRegionSurR = new Combustible("Regular", leerFloat("Asignar precio del combustible Regular de la Región Sur: "));
    Combustible* regularRegionSurP = new Combustible("Premium", leerFloat("Asignar precio del combustible Premium de la Región Sur: "));
    Combustible* regularRegionSurE = new Combustible("EcoExtra", leerFloat("Asignar precio del combustible EcoExtra de la Región Sur: "));
    //---------------Fin precios combustibles para la región Sur----------------------

    //------------------Inicio instancia objetos Región Centro---------------
    tiposRegionCentro[0] = regularRegionCentroR;
    tiposRegionCentro[1] = regularRegionCentroP;
    tiposRegionCentro[2] = regularRegionCentroE;

    Region* regionCentro = new Region("Región Centro", tiposRegionCentro, 3);
    //------------------Fin instancia objetos Región Centro---------------

    //------------------Inicio instancia objetos Región Norte---------------
    tiposRegionNorte[0] = regularRegionNorteR;
    tiposRegionNorte[1] = regularRegionNorteP;
    tiposRegionNorte[2] = regularRegionNorteE;

    Region* regionNorte = new Region("Región Norte", tiposRegionNorte, 3);
    //------------------Fin instancia objetos Región Norte---------------

    //------------------Inicio instancia objetos Región Sur---------------
    tiposRegionSur[0] = regularRegionSurR;
    tiposRegionSur[1] = regularRegionSurP;
    tiposRegionSur[2] = regularRegionSurE;

    Region* regionSur = new Region("Región Sur", tiposRegionSur, 3);
    //------------------Fin instancia objetos Región Sur---------------

    // Asignar las regiones a un arreglo de punteros
    regiones[0] = regionCentro;
    regiones[1] = regionNorte;
    regiones[2] = regionSur;

    // Retornar el arreglo de punteros a regiones
    return regiones;

}

void limpiarMemoriaDin(){
        delete[] regiones;
        delete[] tiposRegionCentro;
        delete[] tiposRegionNorte;
        delete[] tiposRegionSur;
}

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

short generarNumeroAleatorio(short inicio, short fin){
    srand(time(0));
    return inicio + rand() % (inicio - fin + 1);
}
