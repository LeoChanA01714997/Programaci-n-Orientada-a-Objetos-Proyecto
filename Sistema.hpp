#pragma once
#include <vector>
#include <iostream>
#include "Planeta.hpp"
#include "Estrella.hpp"

class Sistema {
public:
    double dt;
    Estrella sol;
    std::vector<Planeta> planetas;

    Sistema(double paso, const Estrella& estrella);
    void agregarPlaneta(const Planeta& p);
    void paso();
    void mostrar() const;
};
