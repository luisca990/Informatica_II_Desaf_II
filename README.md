# Sistema de Comercialización de Combustible - TerMax

Este proyecto implementa un sistema de gestión para la red nacional de estaciones de servicio de la empresa **TerMax**. El sistema permite gestionar estaciones de servicio, surtidores, transacciones de venta de combustible y la detección de fugas de combustible, utilizando principios de **Programación Orientada a Objetos en C++**.

## Objetivos del Sistema

- **Gestión de la Red Nacional de Estaciones de Servicio**: Permitir la adición y eliminación de estaciones de servicio, así como la gestión de surtidores y el cálculo de ventas por estación.
- **Simulación de Ventas**: Simulación de ventas de combustible desde surtidores activos.
- **Verificación de Fugas de Combustible**: Detección de posibles fugas en las estaciones de servicio a través del análisis del stock de combustible.
- **Gestión de Transacciones**: Registro detallado de las ventas realizadas en cada surtidor, incluyendo datos como la cantidad de litros vendidos, método de pago y fecha de la transacción.

## Funcionalidades Clave

- **Agregar estaciones de servicio**: Permite agregar nuevas estaciones de servicio con su respectiva información (nombre, gerente, región).
- **Agregar surtidores**: Cada estación puede gestionar entre 2 y 12 surtidores para la venta de combustible.
- **Simular ventas**: Se asigna un surtidor activo aleatoriamente para realizar una venta, y se registra la transacción.
- **Verificar fugas de combustible**: Verifica que la cantidad vendida más lo almacenado en el tanque no supere un 95% de la capacidad total del tanque.
- **Consulta y reporte de ventas**: Permite ver el reporte de las transacciones realizadas y la cantidad de litros vendidos por surtidor.

## Requisitos Técnicos

- Implementado en C++ utilizando **Programación Orientada a Objetos**.
- No se utiliza la biblioteca **STL**, y se hace uso de memoria dinámica.
- Cada estación tiene un tanque con tres tipos de combustible: Regular, Premium y EcoExtra, cada uno con su capacidad y precio por litro.
- Las transacciones de cada venta se almacenan y pueden ser consultadas posteriormente.

## Equipo de Trabajo

- **Luis Carlos Romero Cárdenas** (email: luis.romero3@udea.edu.co)
- **Oscar Miguel López Peñata** (email: oscar.lopezp@udea.edu.co)

## Profesores

- **Aníbal Guerra**
- **Augusto Salazar**

## Universidad de Antioquia

- **Asignatura**: Informática 2 Teoría
- **Programa**: Ingeniería de Telecomunicaciones

Este archivo resume las funcionalidades y el objetivo del sistema, así como el equipo de trabajo involucrado en su desarrollo.

## Nota
La versión final del código se encuentra en la carpeta: codigo/TexMax_Luis_Oscar
Esto debido a cambio de grupo por cancelación de materia por parte de la estudiante Sandra Hoyos Muñoz
que hacía equipo de trabajo con Oscar Lopez. 
Solicitud de cambio de grupo documentada con envío de correo al profesor Augusto Salazar realizada
por el compañero Luis Carlos Romero Cárdenas para anexar al compañero Oscar Lopez a su grupo de desarrollo.
Las demás carpetas evidencian el proceso que se llevó para el desarrollo.

## Video de Demostración

[Enlace a la demostración de YouTube](https://www.youtube.com/watch?v=qQrqzgX8UOo)
