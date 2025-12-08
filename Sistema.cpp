#include "Sistema.hpp"

Sistema::Sistema(double paso, const Estrella& estrella)
    : dt(paso), sol(estrella) {}

void Sistema::agregarPlaneta(const Planeta& p) {
    planetas.push_back(p);
}

void Sistema::paso() {
    const double GM = 1.0 * sol.getMasa();
    for (auto& p : planetas) {
        Vector2D dr(p.r().x() - sol.r().x(),
                    p.r().y() - sol.r().y());
        double d = dr.norm();
        if (d < 1e-9) d = 1e-9;
        double k = -GM / (d * d * d);

        p.acelerar(k * dr.x(), k * dr.y(), dt);
        p.integrar(dt);
    }
}

void Sistema::mostrar() const {
    std::cout << "Estrella: " << sol.info() << "\n";
    for (const auto& p : planetas) {
        std::cout << "Planeta : " << p.info() << "\n";
    }
    std::cout << "\n";
}


