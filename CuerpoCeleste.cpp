#include "CuerpoCeleste.hpp"
#include <sstream>

CuerpoCeleste::CuerpoCeleste(std::string n,double m,Vector2D p,Vector2D v)
: nombre(std::move(n)), masa(m), pos(p), vel(v) {}

void CuerpoCeleste::acelerar(double ax,double ay,double dt){
    vel = vel + Vector2D(ax*dt, ay*dt);
}
void CuerpoCeleste::integrar(double dt){
    pos = pos + vel*dt;
}
std::string CuerpoCeleste::info() const {
    std::ostringstream os;
    os << nombre << " m=" << masa
       << " r=(" << r().x() << "," << r().y() << ")"
       << " v=(" << vel.x() << "," << vel.y() << ")";
    return os.str();
}
