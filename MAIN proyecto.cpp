#include <iostream>
#include <iomanip>
#include "Sistema.hpp"

int main() {
    //estrella posicionada en el origen
    Estrella sol("Sol", 1000.0, Vector2D(0.0, 0.0), Vector2D(0.0, 0.0));
    Sistema sis(0.01, sol);   // dt = 0.01

    //planetas
    sis.agregarPlaneta(
        Planeta("Tierra", 1.0, Vector2D(1.0, 0.0), Vector2D(0.0, 1.0))
    );
    sis.agregarPlaneta(
        Planeta("Mercurio", 0.055, Vector2D(0.4, 0.0), Vector2D(0.0, 1.6))
    );
    //numero de pasos de integracion y cada cuantos pasos se desea imprimir (modificable)
    const int pasosTotales = 5000; 
    const int imprimirCada = 500;  

    std::cout << std::fixed << std::setprecision(3);

    for (int i = 0; i < pasosTotales; ++i) {
        sis.paso();

        if ((i + 1) % imprimirCada == 0) {
            double t = (i + 1) * sis.dt;
            std::cout << "t = " << t << "\n";
            sis.mostrar();
        }
    }

    std::cout << "Simulacion terminada \n";
    return 0;
}
