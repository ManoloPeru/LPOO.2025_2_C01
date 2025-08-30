# LPOO.2025_2_C01 - Sistema de Control de Sensores de Temperatura
Descripción del Proyecto
En un laboratorio de ingeniería mecatrónica se desea llevar el control de sensores de temperatura instalados en diferentes estaciones de una línea de producción. Cada estación registra valores de temperatura (en °C) que deben ser almacenados en un arreglo.

Funcionalidades del Sistema
El sistema permite las siguientes operaciones:

✅ Registrar las temperaturas de cada estación

✅ Calcular métricas básicas como temperatura promedio, máxima y mínima

✅ Mostrar alertas si alguna estación supera un umbral de temperatura crítica

✅ Consultar y actualizar valores de temperatura


Características Técnicas
Datos del Sistema

✅ 10 estaciones de trabajo, cada una con un sensor de temperatura

✅ Los datos se almacenan en un arreglo unidimensional de 10 enteros (int)

✅ Umbral de temperatura crítica: 70 °C

Funciones Implementadas

✅ registrarTemperaturas() - Permite ingresar las 10 temperaturas iniciales

✅ mostrarTemperaturas() - Muestra todas las temperaturas registradas

✅ calcularPromedio() - Retorna la temperatura promedio

✅ obtenerMaxima() - Retorna la temperatura máxima registrada

✅ obtenerMinima() - Retorna la temperatura mínima registrada

✅ verificarAlertas() - Muestra alertas para temperaturas superiores a 70°C

✅ actualizarTemperatura() - Permite actualizar temperatura de una estación específica

Menú de Opciones

(1) Registrar temperaturas

(2) Mostrar temperaturas

(3) Calcular promedio

(4) Mostrar máxima y mínima

(5) Verificar alertas

(6) Actualizar temperatura

(Q) Salir

Validaciones Implementadas

✅ No se permiten temperaturas negativas

✅ Validación de rango de estaciones (1-10)

✅ Verificación de datos existentes antes de operaciones

Tecnologías Utilizadas

✅ Lenguaje: C++/CLI

✅ Entorno: Visual Studio 2022

✅ Tipo de proyecto: Aplicación de consola

✅ Estructuras de datos: Arreglos unidimensionales

Caso de Prueba

Condición inicial:

✅ El arreglo de temperaturas se encuentra vacío.

✅ Entrada de prueba:

  ✅ Temperaturas: 45, 52, 60, 71, 55, 68, 40, 75, 49, 62

  ✅ Operaciones: Mostrar, promedio, máxima/mínima, alertas, actualizar estación 4 a 65

Resultados esperados:

✅ Promedio inicial: 57.7 °C

✅ Máxima: 75 °C, Mínima: 40 °C

✅ Alertas: Estación 4 (71°C) y Estación 8 (75°C)

Después de actualizar: Estación 4 ya no genera alerta

Requisitos Cumplidos

✅ Uso de arreglos unidimensionales

✅ Implementación de todas las funciones solicitadas

✅ Menú interactivo por consola

✅ Validaciones de entrada

✅ Estructuras de control selectivas e iterativas

✅ Manejo de tipos de datos adecuados

Este proyecto demuestra el uso de arreglos y estructuras de control en C++/CLI para el monitoreo y control de sensores en un entorno industrial.
