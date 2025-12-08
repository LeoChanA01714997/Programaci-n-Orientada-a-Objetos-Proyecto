#pragma once
#include <string>
#include "Vector2D.hpp"

class CuerpoCeleste {
protected:
    std::string nombre;
    double masa;
    Vector2D pos;
    Vector2D vel;

public:
    CuerpoCeleste(std::string n, double m, Vector2D p, Vector2D v);
    virtual ~CuerpoCeleste() = default;

    void acelerar(double ax, double ay, double dt);
    virtual void integrar(double dt);

    std::string info() const;
    const Vector2D& r() const { return pos; }
    double getMasa() const { return masa; }

    const std::string& getNombre() const { return nombre; }
};
