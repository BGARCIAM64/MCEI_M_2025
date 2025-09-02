
#include <iostream>   // Librería estándar para imprimir en pantalla (cout, endl)
#include <iomanip>    // Librería para manipular formato de salida (setprecision)
#include <cmath>      // Librería matemática (aquí usamos abs)

// ------------------------------------------------------
// Función: pasoEuler
// Calcula la velocidad en el siguiente paso usando
// el método de Euler aplicado a dv/dt = g - (c/m)*v
// ------------------------------------------------------
double pasoEuler(double v_ant, double m, double c, double dt) {
    const double g = 9.8;  // Aceleración de la gravedad (m/s^2)
    
    // Fórmula de Euler:
    // v_{n+1} = v_n + dt * (g - (c/m) * v_n)
    return v_ant + dt * (g - (c/m) * v_ant);
}

int main() {
    // -------------------------
    // Parámetros físicos
    // -------------------------
    const double m = 68.1;   // Masa del paracaidista en kg
    const double c = 12.5;   // Coeficiente de resistencia del aire (kg/s)
    const double dt = 2.0;   // Paso de tiempo (s)

    // -------------------------
    // Variables del estado
    // -------------------------
    double t = 0.0;      // Tiempo inicial en segundos
    double v = 0.0;      // Velocidad inicial (el paracaidista arranca en reposo)
    double v_prev;       // Variable para guardar la velocidad anterior

    // -------------------------
    // Configuración de salida
    // -------------------------
    std::cout << std::fixed               // Usamos notación decimal fija
              << std::setprecision(6);    // Mostramos 6 decimales
    
    // Imprimimos el estado inicial (t = 0, v = 0)
    std::cout << "t = " << t 
              << " s\tvel = " << v << " m/s\n";

    // -------------------------
    // Iteración con Euler
    // -------------------------
    // Calculamos la velocidad en cada paso de tiempo dt
    // hasta que la diferencia entre dos pasos consecutivos
    // sea muy pequeña (es decir, ya llegó a la velocidad terminal).
    do {
        v_prev = v;                          // Guardamos velocidad anterior
        v = pasoEuler(v_prev, m, c, dt);     // Calculamos nueva velocidad con Euler
        t += dt;                             // Aumentamos el tiempo en dt segundos
        
        // Imprimimos el tiempo y la velocidad calculada en este paso
        std::cout << "t = " << t 
                  << " s\tvel = " << v << " m/s\n";

    } while (std::abs(v - v_prev) > 1e-4);   // Paramos cuando el cambio es < 0.0001 m/s

    return 0; // Fin del programa
}



