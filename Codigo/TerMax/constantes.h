#ifndef CONSTANTES_H
#define CONSTANTES_H

// Definir un array constante con las opciones de pago
#include "region.h"
#include "combustible.h"
#include <string>
const std::string opcionesPago[] = { "Efectivo", "TDebito", "TCredito" };
void menuGestionRed();

void menuGestionEstacion();

void menuPrincipal();

Region** inicializarCombustiblesRegiones();
void limpiarMemoriaDin();

short generarNumeroAleatorio(short inicio, short fin);

std::string leerString(const char* mensaje);

float leerFloat(const char* mensaje);
int leerEntero(const char* mensaje);
#endif // CONSTANTES_H
