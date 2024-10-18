#include "utils.h"
#include <cstdlib>
#include <ctime>
#include <iomanip>



short generarNumeroAleatorio(short inicio, short fin){
    srand(time(0));
    return inicio + rand() % (inicio - fin + 1);
}

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

std::string obtenerFechaActual() {
    // Obtener el tiempo actual del sistema
    std::time_t tiempoActual = std::time(nullptr);

    // Convertir el tiempo a la estructura tm (hora local)
    std::tm* fechaLocal = std::localtime(&tiempoActual);

    // Formatear la fecha como una cadena en el formato Año-Mes-Día
    std::stringstream fechaFormateada;
    fechaFormateada << std::put_time(fechaLocal, "%Y-%m-%d");

    return fechaFormateada.str(); // Devolver la fecha formateada
}
