#include "Combustible.h"
#include "EstacionServicio.h"
#include "archivo.h"
#include "rednacional.h"
#include "surtidor.h"
#include "transaccion.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Clase Combustible
/*class Combustible {
private:
    std::string tipo;
    float capacidad;
    float precioPorLitro;

public:
    Combustible(std::string tipo, float capacidad, float precio)
        : tipo(tipo), capacidad(capacidad), precioPorLitro(precio) {}

    void ajustarCapacidad(float cantidad) {
        capacidad -= cantidad;
    }

    std::string obtenerTipo() const {
        return tipo;
    }

    float obtenerCapacidad() const {
        return capacidad;
    }
};

// Clase Transaccion
class Transaccion {
private:
    std::string fecha;
    float litros;
    std::string tipoCombustible;
    std::string metodoPago;
    std::string cliente;
    float monto;

public:
    Transaccion(std::string fecha, float litros, std::string tipoCombustible,
                std::string metodoPago, std::string cliente, float monto)
        : fecha(fecha), litros(litros), tipoCombustible(tipoCombustible),
        metodoPago(metodoPago), cliente(cliente), monto(monto) {}

    std::string obtenerDatos() const {
        return "Fecha: " + fecha + ", Litros: " + std::to_string(litros) +
               ", Tipo: " + tipoCombustible + ", Cliente: " + cliente +
               ", Monto: " + std::to_string(monto);
    }
};

// Clase Surtidor
class Surtidor {
private:
    static int generadorCodigo;
    int codigo;
    std::string modelo;
    bool activo;
    Transaccion** transacciones;
    int cantidadTransacciones;

public:
    Surtidor(std::string modelo)
        : codigo(++generadorCodigo), modelo(modelo), activo(true),
        transacciones(nullptr), cantidadTransacciones(0) {}

    void registrarVenta(Transaccion* transaccion) {
        Transaccion** nuevo = new Transaccion*[cantidadTransacciones + 1];
        for (int i = 0; i < cantidadTransacciones; ++i) {
            nuevo[i] = transacciones[i];
        }
        nuevo[cantidadTransacciones] = transaccion;
        delete[] transacciones;
        transacciones = nuevo;
        cantidadTransacciones++;
    }

    Transaccion* simularVenta(float litros, std::string tipo) {
        float monto = calcularMonto(litros, tipo);
        Transaccion* t = new Transaccion("2024-10-15", litros, tipo,
                                         "Efectivo", "Cliente123", monto);
        registrarVenta(t);
        return t;
    }

    float calcularMonto(float litros, std::string tipo) {
        return litros * 5000.0f; // Precio temporal
    }

    bool estaActivo() const {
        return activo;
    }

    void actualizarEstado(bool estado) {
        activo = estado;
    }

    int obtenerCodigo() const {
        return codigo;
    }

    ~Surtidor() {
        for (int i = 0; i < cantidadTransacciones; ++i) {
            delete transacciones[i];
        }
        delete[] transacciones;
    }
};

int Surtidor::generadorCodigo = 0; // Inicialización de la variable estática

// Clase EstacionServicio
class EstacionServicio {
private:
    static int generadorCodigoEstacion;
    std::string codigo;  // Cambiado a string para incluir prefijo
    std::string nombre;
    std::string gerente;
    std::string region;
    Combustible* tanques[3];
    Surtidor** surtidores;
    int cantidadSurtidores;

    // Función para generar código único
    std::string generarCodigo() {
        return "E-" + std::to_string(++generadorCodigoEstacion);
    }

public:
    EstacionServicio(std::string nombre, std::string gerente, std::string region)
        : codigo(generarCodigo()), nombre(nombre), gerente(gerente),
        region(region), surtidores(nullptr), cantidadSurtidores(0) {
        tanques[0] = new Combustible("Regular", 5000, 150);
        tanques[1] = new Combustible("Premium", 7000, 100);
        tanques[2] = new Combustible("EcoExtra", 6000, 120);
    }

    void agregarSurtidor(Surtidor* surtidor) {
        Surtidor** nuevo = new Surtidor*[cantidadSurtidores + 1];
        for (int i = 0; i < cantidadSurtidores; ++i) {
            nuevo[i] = surtidores[i];
        }
        nuevo[cantidadSurtidores] = surtidor;
        delete[] surtidores;
        surtidores = nuevo;
        cantidadSurtidores++;
    }

    void simularVenta() {
        if (cantidadSurtidores == 0) {
            std::cout << "No hay surtidores en la estación.\n";
            return;
        }

        Surtidor* surtidorActivo = nullptr;
        while (!surtidorActivo) {
            int indice = rand() % cantidadSurtidores;
            if (surtidores[indice]->estaActivo()) {
                surtidorActivo = surtidores[indice];
            }
        }

        int tipoCombustible = rand() % 3;
        float litrosSolicitados = 3 + (rand() % 18);

        Transaccion* transaccion = surtidorActivo->simularVenta(litrosSolicitados,
                                                                tanques[tipoCombustible]->obtenerTipo());
        tanques[tipoCombustible]->ajustarCapacidad(litrosSolicitados);

        std::cout << "Venta simulada: " << transaccion->obtenerDatos() << "\n";
    }

    bool verificarCapacidad() const {
        float capacidadActual = tanques[0]->obtenerCapacidad() +
                                tanques[1]->obtenerCapacidad() +
                                tanques[2]->obtenerCapacidad();
        return (capacidadActual / (5000 + 7000 + 6000)) >= 0.95; // 95% de capacidad
    }

    std::string obtenerCodigo() const {
        return codigo; // Devuelve el código único de la estación
    }

    std::string obtenerNombre() const {
        return nombre; // Devuelve el nombre de la estación
    }

    std::string obtenerGerente() const {
        return gerente; // Devuelve el nombre del gerente
    }

    std::string obtenerRegion() const {
        return region; // Devuelve la región de la estación
    }

    Surtidor** getSurtidores(){
        return surtidores;
    }

    ~EstacionServicio() {
        delete tanques[0];
        delete tanques[1];
        delete tanques[2];
        for (int i = 0; i < cantidadSurtidores; ++i) {
            delete surtidores[i];
        }
        delete[] surtidores;
    }
};

int EstacionServicio::generadorCodigoEstacion = 1000; // Inicialización de la variable estática

// Clase RedNacional
class RedNacional {
private:
    EstacionServicio** estaciones;
    int cantidadEstaciones;

public:
    RedNacional() : estaciones(nullptr), cantidadEstaciones(0) {}

    void agregarEstacion(EstacionServicio* estacion) {
        EstacionServicio** nuevo = new EstacionServicio*[cantidadEstaciones + 1];
        for (int i = 0; i < cantidadEstaciones; ++i) {
            nuevo[i] = estaciones[i];
        }
        nuevo[cantidadEstaciones] = estacion;
        delete[] estaciones;
        estaciones = nuevo;
        cantidadEstaciones++;
    }

    void simularVenta(const std::string& codigoEstacion) {
        for (int i = 0; i < cantidadEstaciones; ++i) {
            if (estaciones[i]->obtenerCodigo() == codigoEstacion) {
                estaciones[i]->simularVenta();
                return;
            }
        }
        std::cout << "Estación no encontrada.\n";
    }

    bool verificarFugaCombustible(const std::string& codigoEstacion) {
        for (int i = 0; i < cantidadEstaciones; ++i) {
            if (estaciones[i]->obtenerCodigo() == codigoEstacion) {
                return estaciones[i]->verificarCapacidad();
            }
        }
        std::cout << "Estación no encontrada.\n";
        return false;
    }

    void mostrarEstaciones() const {
        std::cout << "Estaciones de servicio en la red:\n";
        for (int i = 0; i < cantidadEstaciones; ++i) {
            std::cout << "Código: " << estaciones[i]->obtenerCodigo()
                      << ", Nombre: " << estaciones[i]->obtenerNombre()
                      << ", Gerente: " << estaciones[i]->obtenerGerente()
                      << ", Región: " << estaciones[i]->obtenerRegion() << "\n";
        }
    }

    EstacionServicio** getEstaciones(){
        return estaciones;
    }

    int getCantidadEstaciones(){
        return cantidadEstaciones;
    }

    ~RedNacional() {
        for (int i = 0; i < cantidadEstaciones; ++i) {
            delete estaciones[i];
        }
        delete[] estaciones;
    }
};
*/
// Funciones del menú
void mostrarMenu() {
    std::cout << "==============================\n";
    std::cout << "       *** MENU PRINCIPAL ***       \n";
    std::cout << "==============================\n";
    std::cout << "1.  Agregar estación de servicio\n";
    std::cout << "2.  Mostrar estaciones de servicio\n";
    std::cout << "3.  Simular venta de combustible\n";
    std::cout << "4.  Verificar fuga de combustible\n";
    std::cout << "5.  Agregar surtidor\n";
    std::cout << "6.  Calcular el monto total de las ventas por categoría a nivel nacional\n";
    std::cout << "7.  Histórico de transacciones por surtidor\n";
    std::cout << "8.  Litros vendidos por categoría\n";
    std::cout << "9.  Cambiar estado de un surtidor\n";
    std::cout << "10. Mostrar surtidores\n";
    std::cout << "11. Salir\n";
    std::cout << "==============================\n";
    std::cout << "Ingrese su opción: ";
}

void agregarEstacion(RedNacional& red) {
    std::string nombre, gerente, region;
    std::cout << "Ingrese el nombre de la estación: ";
    std::cin.ignore();
    std::getline(std::cin, nombre);
    std::cout << "Ingrese el nombre del gerente: ";
    std::getline(std::cin, gerente);
    std::cout << "Ingrese la región (Norte/Centro/Sur): ";
    std::getline(std::cin, region);

    EstacionServicio* nuevaEstacion = new EstacionServicio(nombre, gerente, region);
    red.agregarEstacion(nuevaEstacion);
    std::cout << "Estación agregada con éxito.\n";
}

void simularVenta(RedNacional& red) {
    std::string codigo;
    std::cout << "Ingrese el código de la estación para simular una venta: ";
    std::cin >> codigo;
    red.simularVenta(codigo);
}

void verificarFuga(RedNacional& red) {
    std::string codigo;
    std::cout << "Ingrese el código de la estación para verificar fugas: ";
    std::cin >> codigo;
    bool hayFuga = red.verificarFugaCombustible(codigo);
    if (hayFuga) {
        std::cout << "No se detectaron fugas de combustible.\n";
    } else {
        std::cout << "¡Alerta! Se detectó una posible fuga de combustible.\n";
    }
}


void agregarSurtidor(RedNacional& red) {
    std::string modelo,codigo;
    std::cout << "Ingrese el modelo de la estación: ";
    std::cin.ignore();
    std::getline(std::cin, modelo);
    std::cout << "Ingrese el código de la estación para agregar un surtidor: ";
    std::cin >> codigo;

    EstacionServicio** estacionesTemp= red.getEstaciones();
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        if(estacionesTemp[var]->obtenerCodigo()==codigo){
            estacionesTemp[var]->agregarSurtidor(new Surtidor(codigo));
            //std::cout <<estacionesTemp[var]->getSurtidores()[0]->obtenerCodigo();
        }
    }
    //delete [] estacionesTemp;
    std::cout << "Surtidor agregado con éxito.\n";
}

void obtenerVentasXEstacionCategoria(RedNacional& red) {
    EstacionServicio** estacionesTemp= red.getEstaciones();
    float ventasTotales[3]={0.0,0.0,0.0};
    ventasCategoria tmpVentas;
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        Surtidor ** surtidores=estacionesTemp[var]->getSurtidores();
        int cantidadSurtidores=estacionesTemp[var]->getCantidadSurtidores();
        for (int i=0;i<cantidadSurtidores;i++){
            tmpVentas=surtidores[i]->getVentasEstacion();
            ventasTotales[0]=tmpVentas.Regular;
            ventasTotales[1]=tmpVentas.Premium;
            ventasTotales[2]=tmpVentas.EcoExtra;
        }

    }
    //delete [] estacionesTemp;
    printf("El monto total de las ventas en la categoria de combustible Regular fueron: %f\n",ventasTotales[0]);
    printf("El monto total de las ventas en la categoria de combustible Premium fueron: %f\n",ventasTotales[1]);
    printf("El monto total de las ventas en la categoria de combustible EcoExtra fueron: %f\n",ventasTotales[2]);
}

void obtenerVentasXSurtidor(RedNacional& red) {
    EstacionServicio** estacionesTemp= red.getEstaciones();
    Archivo arch;
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        Surtidor ** surtidores=estacionesTemp[var]->getSurtidores();
        int cantidadSurtidores=estacionesTemp[var]->getCantidadSurtidores();
        for (int i=0;i<cantidadSurtidores;i++){
            std::cout << "Las ventas que se muestran corresponden a la estacion: "+estacionesTemp[var]->obtenerCodigo()+". Y al surtidor: "+std::to_string(surtidores[i]->obtenerCodigo())<<std::endl;
            arch.leerVentas("Surtidor "+estacionesTemp[var]->obtenerCodigo()+"_"+std::to_string(surtidores[i]->obtenerCodigo())+".txt");
        }

    }
    //delete [] estacionesTemp;
}

void obtenerVentasXEstacionCategoriaLitros(RedNacional& red) {
    EstacionServicio** estacionesTemp= red.getEstaciones();
    float ventasTotales[3]={0.0,0.0,0.0};
    ventasCategoria tmpVentas;
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        Surtidor ** surtidores=estacionesTemp[var]->getSurtidores();
        int cantidadSurtidores=estacionesTemp[var]->getCantidadSurtidores();
        for (int i=0;i<cantidadSurtidores;i++){
            tmpVentas=surtidores[i]->getVentasEstacionLitros();
            ventasTotales[0]=tmpVentas.Regular;
            ventasTotales[1]=tmpVentas.Premium;
            ventasTotales[2]=tmpVentas.EcoExtra;
        }

    }

    printf("La cantidad total de litros vendidios en la categoria de combustible Regular fueron: %f\n",ventasTotales[0]);
    printf("La cantidad total de litros vendidios en la categoria de combustible Premium fueron: %f\n",ventasTotales[1]);
    printf("La cantidad total de litros vendidios en la categoria de combustible EcoExtra fueron: %f\n",ventasTotales[2]);
}

void cambiarEstadoSurtidor(RedNacional& red) {
    EstacionServicio** estacionesTemp= red.getEstaciones();
    ventasCategoria tmpVentas;
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        std::string estacionSel=leerString("Ingrese el código de la estación donde está el surtidor a activar o desactivar: ");
        if(estacionesTemp[var]->obtenerCodigo()==estacionSel){
            int surtidSe=leerEntero("Ingrese el código (número entero) del surtidor a cambiar el estado:");
            Surtidor ** surtidores=estacionesTemp[var]->getSurtidores();
            int cantidadSurtidores=estacionesTemp[var]->getCantidadSurtidores();
            for (int i=0;i<cantidadSurtidores;i++){
                if(surtidores[i]->obtenerCodigo()==surtidSe){
                    surtidores[i]->actualizarEstado(surtidores[i]->estaActivo()==true?false:true);
                    printf("Estado cambiado correctamente\n");
                }
            }
        }


    }
}

void mostrarSurtidores(RedNacional& red) {
    EstacionServicio** estacionesTemp= red.getEstaciones();
    ventasCategoria tmpVentas;
    int totalEstaciones=red.getCantidadEstaciones();
    for (int var = 0; var < totalEstaciones; ++var) {
        std::string estacionSel=leerString("Ingrese el código de la estación de la que desea mostrar los surtidores: ");
        if(estacionesTemp[var]->obtenerCodigo()==estacionSel){
            estacionesTemp[var]->mostrarSurtidores();
        }

    }

}
int main() {
    srand(time(0));  // Inicializar la semilla para números aleatorios
    RedNacional redNacional;
    int opcion;

    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            agregarEstacion(redNacional);
            break;
        case 2:
            redNacional.mostrarEstaciones();
            break;
        case 3:
            simularVenta(redNacional);
            break;
        case 4:
            verificarFuga(redNacional);
            break;
        case 5:
            agregarSurtidor(redNacional);
            break;
        case 6:
            obtenerVentasXEstacionCategoria(redNacional);
            break;
        case 7:
            obtenerVentasXSurtidor(redNacional);
            break;
        case 8:
            obtenerVentasXEstacionCategoriaLitros(redNacional);
            break;
        case 9:
            cambiarEstadoSurtidor(redNacional);
            break;
        case 10:
            mostrarSurtidores(redNacional);
            break;
        case 11:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opción no válida. Intente de nuevo.\n";
        }
    } while (opcion != 11);

    return 0;
}
