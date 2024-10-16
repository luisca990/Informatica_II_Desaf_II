#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

// Clase Combustible
class Combustible {
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
    static int generadorCodigo;
    int codigo;
    std::string nombre;
    std::string gerente;
    std::string region;
    Combustible* tanques[3];
    Surtidor** surtidores;
    int cantidadSurtidores;

public:
    EstacionServicio(std::string nombre, std::string gerente, std::string region)
        : codigo(++generadorCodigo), nombre(nombre), gerente(gerente),
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

    int obtenerCodigo() const {
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

int EstacionServicio::generadorCodigo = 0; // Inicialización de la variable estática

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

    void simularVenta(int codigoEstacion) {
        for (int i = 0; i < cantidadEstaciones; ++i) {
            if (estaciones[i]->obtenerCodigo() == codigoEstacion) {
                estaciones[i]->simularVenta();
                return;
            }
        }
        std::cout << "Estación no encontrada.\n";
    }

    bool verificarFugaCombustible(int codigoEstacion) {
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

    ~RedNacional() {
        for (int i = 0; i < cantidadEstaciones; ++i) {
            delete estaciones[i];
        }
        delete[] estaciones;
    }
};

// Funciones del menú
void mostrarMenu() {
    std::cout << "----- Menu Principal -----\n";
    std::cout << "1. Agregar estación de servicio\n";
    std::cout << "2. Simular venta en una estación\n";
    std::cout << "3. Verificar fuga de combustible en una estación\n"
    std::cout << "4. Mostrar estaciones de servicio\n";
    std::cout << "5. Salir\n";
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Inicializar la semilla para rand
    RedNacional red;

    int opcion;
    do {
        mostrarMenu();
        std::cout << "Seleccione una opción: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1: {
                std::string nombre, gerente, region;
                std::cout << "Ingrese el nombre de la estación: ";
                std::cin >> nombre;
                std::cout << "Ingrese el nombre del gerente: ";
                std::cin >> gerente;
                std::cout << "Ingrese la región: ";
                std::cin >> region;

                EstacionServicio* estacion = new EstacionServicio(nombre, gerente, region);
                red.agregarEstacion(estacion);
                std::cout << "Estación de servicio agregada.\n";
                break;
            }
            case 2: {
                int codigoEstacion;
                std::cout << "Ingrese el código de la estación: ";
                std::cin >> codigoEstacion;
                red.simularVenta(codigoEstacion);
                break;
            }
            case 3: {
                int codigoEstacion;
                std::cout << "Ingrese el código de la estación: ";
                std::cin >> codigoEstacion;
                if (red.verificarFugaCombustible(codigoEstacion)) {
                    std::cout << "No hay fuga de combustible en la estación.\n";
                } else {
                    std::cout << "Hay fuga de combustible en la estación.\n";
                }
                break;
            }
            case 4: {
                red.mostrarEstaciones();
                break;
            }
            case 5:
                std::cout << "Saliendo del programa...\n";
                break;
            default:
                std::cout << "Opción no válida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 5);

    return 0;
}
