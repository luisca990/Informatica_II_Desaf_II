#include "constantes.h"
#include "termaxgestionestacion.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{

    int opcion, submenuOpcion,IdEstacion=1, totalEstaciones=0, region=0;
    TermaxGestionEstacion empresa;

    string nombreEstacion="",gerente="";
    float latitud,longitud;
    EstacionServicio nuevaEstacion;
    EstacionServicio* estaciones;

    Region** regiones;

    do {
        menuPrincipal();
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            do {
                menuGestionRed();
                scanf("%d", &submenuOpcion);
                switch (submenuOpcion) {
                case 1:
                    printf("Opción seleccionada: Agregar estaciones de servicio.\n");
                    nombreEstacion=leerString("Ingrese el nombre de la estación: ");
                    nuevaEstacion.setNombre(nombreEstacion);
                    nuevaEstacion.setIdEstacion(std::to_string(IdEstacion));
                    gerente=leerString(("Ingrese el nombre del gerente para la estación "+nombreEstacion+": ").c_str());
                    nuevaEstacion.setGerente(gerente);
                    latitud=leerFloat(("Ingrese la latitud para la estación "+nombreEstacion+": ").c_str());
                    nuevaEstacion.setLatitud(latitud);
                    longitud=leerFloat(("Ingrese la longitud para la estación "+nombreEstacion+": ").c_str());
                    nuevaEstacion.setLongitud(longitud);
                    empresa.agregarEstacion(&nuevaEstacion);
                    empresa.getDevolverEstaciones();
                    std::cout <<empresa.getDevolverEstaciones()[0].getIdEstacion();
                    break;
                case 2:
                    printf("Opción seleccionada: Eliminar una E/S de la red nacional.\n");
                    empresa.eliminarEstacion(leerString("Ingrese el id de la estación a eliminar: "));
                    empresa.getDevolverEstaciones();
                    std::cout <<empresa.getDevolverEstaciones()[0].getIdEstacion();
                    break;
                case 3:
                    printf("Opción seleccionada: Calcular el monto total de las ventas.\n");
                    // Aquí iría la lógica para calcular las ventas
                    break;
                case 4:
                    printf("Opción seleccionada: Fijar precios del combustible.\n");
                    regiones=inicializarCombustiblesRegiones();
                    empresa.getDevolverEstaciones();
                    totalEstaciones=empresa.getNumEstaciones();
                    for (int i=0;i<totalEstaciones;i++) {
                        region=leerEntero("Ingresar Region: 1. Centro. 2. Norte. 3. Sur: ");
                        estaciones[i].setRegion(regiones[region-1]);
                    }
                    std::cout<<estaciones[0].getRegion()->getNombre();
                    break;
                case 5:
                    printf("Volviendo al menú principal.\n");
                    break;
                default:
                    printf("Opción inválida. Intente de nuevo.\n");
                }
            } while (submenuOpcion != 5);
            break;

        case 2:
            do {
                menuGestionEstacion();
                scanf("%d", &submenuOpcion);
                switch (submenuOpcion) {
                case 1:
                    printf("Opción seleccionada: Agregar un surtidor a una E/S.\n");
                    // Aquí iría la lógica para agregar un surtidor
                    break;
                case 2:
                    printf("Opción seleccionada: Eliminar un surtidor de una E/S.\n");
                    // Aquí iría la lógica para eliminar un surtidor
                    break;
                case 3:
                    printf("Opción seleccionada: Activar un surtidor.\n");
                    // Aquí iría la lógica para activar un surtidor
                    break;
                case 4:
                    printf("Opción seleccionada: Desactivar un surtidor.\n");
                    // Aquí iría la lógica para desactivar un surtidor
                    break;
                case 5:
                    printf("Opción seleccionada: Consultar histórico de transacciones.\n");
                    // Aquí iría la lógica para consultar histórico
                    break;
                case 6:
                    printf("Opción seleccionada: Reportar litros vendidos.\n");
                    // Aquí iría la lógica para reportar litros
                    break;
                case 7:
                    printf("Opción seleccionada: Simular una venta de combustible.\n");
                    // Aquí iría la lógica para simular una venta
                    break;
                case 8:
                    printf("Opción seleccionada: Asignar capacidad del tanque de suministro.\n");
                    // Aquí iría la lógica para asignar capacidad
                    break;
                case 9:
                    printf("Volviendo al menú principal.\n");
                    break;
                default:
                    printf("Opción inválida. Intente de nuevo.\n");
                }
            } while (submenuOpcion != 9);
            break;

        case 3:
            printf("Saliendo del sistema...\n");
            break;

        default:
            printf("Opción inválida. Intente de nuevo.\n");
        }
    } while (opcion != 3);
}
