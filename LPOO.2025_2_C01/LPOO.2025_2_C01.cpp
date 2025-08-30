#include "pch.h"
using namespace System;

// Función para registrar temperaturas
void registrarTemperaturas(array<int>^ sensores) {
    for (int i = 0; i < sensores->Length; i++) {
		// Recibir temperatura en cada elemento del arreglo: "sensores"
        int temp;
        do {
            Console::Write("Ingrese temperatura para estación {0}: ", i + 1);
			temp = Convert::ToInt32(Console::ReadLine()); //Convertir la entrada a entero

            // Validar que no sea negativa
            if (temp < 0) {
                Console::WriteLine("Error: La temperatura no puede ser negativa. Intente nuevamente.");
            }
        } while (temp < 0);

        sensores[i] = temp;
    }
    Console::WriteLine("Temperaturas registradas exitosamente.");
}

// Función para mostrar todas las temperaturas
void mostrarTemperaturas(array<int>^ sensores) {
    Console::WriteLine("\nTemperaturas registradas:");
    for (int i = 0; i < sensores->Length; i++) {
        Console::WriteLine("Estación {0}: {1} °C", i + 1, sensores[i]);
    }
}

// Función para calcular el promedio de temperaturas
double calcularPromedio(array<int>^ sensores) {
    int suma = 0;
    for (int i = 0; i < sensores->Length; i++) {
        suma += sensores[i];
    }
	return Convert::ToDouble(suma) / sensores->Length; // Convertir a double para obtener un promedio con decimales
}

// Función para obtener la temperatura máxima
int obtenerMaxima(array<int>^ sensores) {
    int maxima = sensores[0];
    for (int i = 1; i < sensores->Length; i++) {
        if (sensores[i] > maxima) {
			maxima = sensores[i]; // Actualizar máxima si se encuentra una mayor temperatura
        }
    }
    return maxima;
}

// Función para obtener la temperatura mínima
int obtenerMinima(array<int>^ sensores) {
    int minima = sensores[0];
    for (int i = 1; i < sensores->Length; i++) {
        if (sensores[i] < minima) {
			minima = sensores[i]; // Actualizar mínima si se encuentra una menor temperatura
        }
    }
    return minima;
}

// Función para verificar alertas de temperatura crítica (>70°C)
void verificarAlertas(array<int>^ sensores) {
	const int UMBRAL_CRITICO = 70; // Definir umbral crítico
    bool hayAlertas = false;

    for (int i = 0; i < sensores->Length; i++) {
        if (sensores[i] > UMBRAL_CRITICO) {
			Console::WriteLine("Alerta: Estación {0} supera el umbral con {1} °C", i + 1, sensores[i]); // Mostrar alerta
            hayAlertas = true;
        }
    }

    if (!hayAlertas) {
		Console::WriteLine("No hay alertas de temperatura crítica."); // Indicar que no hay alertas
    }
}

// Función para actualizar temperatura de una estación específica
void actualizarTemperatura(array<int>^ sensores, int estacion, int nuevaTemp) {
    // Validar que la estación esté en rango (1-10)
    if (estacion < 1 || estacion > sensores->Length) {
        Console::WriteLine("Error: Número de estación inválido. Debe estar entre 1 y {0}.", sensores->Length);
		return; // Salir de la función si la estación es inválida
    }
	// Si no se salio, continuamos con la validación
    // Validar que la temperatura no sea negativa
    if (nuevaTemp < 0) {
        Console::WriteLine("Error: La temperatura no puede ser negativa.");
        return;
    }

    // Actualizar la temperatura
	sensores[estacion - 1] = nuevaTemp; //recordar que el arreglo inicia en la posición 0
    Console::WriteLine("Temperatura de la estación {0} actualizada a {1} °C", estacion, nuevaTemp);
}

int main() {
    // Crear arreglo para almacenar temperaturas de 10 estaciones
    array<int>^ sensores = gcnew array<int>(10);

    // Inicializar el arreglo con -1 (indicando que no hay datos)
	// por defecto se asigna el valor 0, y este es un valor valido, por eso lo cambiamos a -1
    for (int i = 0; i < sensores->Length; i++) {
        sensores[i] = -1;
    }

    String^ opcion = "";

    while (opcion != "Q" && opcion != "q") {
        Console::WriteLine("\n--- Menú de Control de Sensores ---");
        Console::WriteLine("1. Registrar temperaturas");
        Console::WriteLine("2. Mostrar temperaturas");
        Console::WriteLine("3. Calcular promedio");
        Console::WriteLine("4. Mostrar máxima y mínima");
        Console::WriteLine("5. Verificar alertas");
        Console::WriteLine("6. Actualizar temperatura");
        Console::WriteLine("Q. Salir");
        Console::Write("Seleccione una opción: ");
        opcion = Console::ReadLine();

        // Procesar la opción seleccionada
        if (opcion == "1") {
            // Registrar temperaturas
            registrarTemperaturas(sensores);
        }
        else if (opcion == "2") {
            // Mostrar temperaturas
            if (sensores[0] == -1) {
                Console::WriteLine("Error: Primero debe registrar las temperaturas.");
            }
            else {
                mostrarTemperaturas(sensores);
            }
        }
        else if (opcion == "3") {
            // Calcular y mostrar promedio
            if (sensores[0] == -1) {
                Console::WriteLine("Error: Primero debe registrar las temperaturas.");
            }
            else {
                double promedio = calcularPromedio(sensores);
                Console::WriteLine("Temperatura promedio: {0:F1} °C", promedio);
            }
        }
        else if (opcion == "4") {
            // Mostrar máxima y mínima
            if (sensores[0] == -1) {
                Console::WriteLine("Error: Primero debe registrar las temperaturas.");
            }
            else {
                int maxima = obtenerMaxima(sensores);
                int minima = obtenerMinima(sensores);
                Console::WriteLine("Temperatura máxima: {0} °C", maxima);
                Console::WriteLine("Temperatura mínima: {0} °C", minima);
            }
        }
        else if (opcion == "5") {
            // Verificar alertas
            if (sensores[0] == -1) {
                Console::WriteLine("Error: Primero debe registrar las temperaturas.");
            }
            else {
                verificarAlertas(sensores);
            }
        }
        else if (opcion == "6") {
            // Actualizar temperatura
            if (sensores[0] == -1) {
                Console::WriteLine("Error: Primero debe registrar las temperaturas.");
            }
            else {
                int estacion;
                do {
                    Console::Write("Ingrese número de estación a actualizar (1-10): ");
                    estacion = Convert::ToInt32(Console::ReadLine());

                    if (estacion < 1 || estacion > 10) {
                        Console::WriteLine("Error: La estación debe estar entre 1 y 10.");
                    }
                } while (estacion < 1 || estacion > 10);

                int nuevaTemp;
                do {
                    Console::Write("Ingrese nueva temperatura: ");
                    nuevaTemp = Convert::ToInt32(Console::ReadLine());

                    if (nuevaTemp < 0) {
                        Console::WriteLine("Error: La temperatura no puede ser negativa.");
                    }
                } while (nuevaTemp < 0);

                actualizarTemperatura(sensores, estacion, nuevaTemp);
            }
        }
        else if (opcion != "Q" && opcion != "q") {
            Console::WriteLine("Opción no válida. Intente nuevamente.");
        }
    }

    Console::WriteLine("Programa finalizado.");
    return 0;
}