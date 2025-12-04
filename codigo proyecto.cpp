#ifndef VECTOR2D_H
#define VECTOR2D_H

#include <iostream>
#include <cmath>

class Vector2D {
private:
    double x;
    double y;

public:
    Vector2D(double x = 0.0, double y = 0.0)
        : x(x), y(y) {}

    double getX() const { return x; }
    double getY() const { return y; }

    void setX(double px) { x = px; }
    void setY(double py) { y = py; }

    double magnitud() const {
        return std::sqrt(x * x + y * y);
    }

    Vector2D sumar(const Vector2D& v) const {
        return Vector2D(x + v.x, y + v.y);
    }

    Vector2D escalar(double k) const {
        return Vector2D(x * k, y * k);
    }

    void imprimir() const {
        std::cout << "Vector(" << x << ", " << y << ")\n";
    }
};

#endif


#ifndef CUERPOCELESTE_H
#define CUERPOCELESTE_H

#include <iostream>
#include <string>
#include "Vector2D.h"

class CuerpoCeleste {
private:
    std::string nombre;
    double masa;
    Vector2D posicion;
    Vector2D velocidad;

public:
    CuerpoCeleste(const std::string& nombre, double masa,
                  const Vector2D& pos, const Vector2D& vel)
        : nombre(nombre), masa(masa), posicion(pos), velocidad(vel) {}

    void mover(double dx, double dy) {
        posicion.setX(posicion.getX() + dx);
        posicion.setY(posicion.getY() + dy);
    }

    void actualizarVelocidad(const Vector2D& aceleracion, double dt) {
        velocidad = velocidad.sumar(aceleracion.escalar(dt));
    }

    void actualizarPosicion(double dt) {
        posicion = posicion.sumar(velocidad.escalar(dt));
    }

    void imprimirDatos() const {
        std::cout << "\n[Cuerpo Celeste]\n";
        std::cout << "Nombre: " << nombre << "\n";
        std::cout << "Masa: " << masa << " kg\n";
        std::cout << "Posicion: ";
        posicion.imprimir();
        std::cout << "Velocidad: ";
        velocidad.imprimir();
    }
};

#endif

#ifndef RENDERCONFIG_H
#define RENDERCONFIG_H

#include <iostream>
#include <utility>
#include "Vector2D.h"

class RenderConfig {
private:
    int ancho;
    int alto;
    double escala;

public:
    RenderConfig(int ancho, int alto, double escala)
        : ancho(ancho), alto(alto), escala(escala) {}

    std::pair<int, int> convertir(const Vector2D& pos) const {
        int sx = ancho / 2 + static_cast<int>(pos.getX() / escala);
        int sy = alto / 2 - static_cast<int>(pos.getY() / escala);
        return {sx, sy};
    }

    void imprimir() const {
        std::cout << "\n[RenderConfig]\n";
        std::cout << "Ancho: " << ancho
                  << "  Alto: " << alto
                  << "  Escala: " << escala << "\n";
    }
};

#endif
