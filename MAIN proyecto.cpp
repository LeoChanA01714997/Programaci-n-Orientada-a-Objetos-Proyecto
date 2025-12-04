#include "Sistema.hpp"

int main(){
    Estrella sol("Sol", 1000, Vector2D(0,0), Vector2D(0,0));
    Sistema sis(0.01, sol);

    sis.agregarPlaneta( Planeta("Tierra", 1.0, Vector2D(1,0), Vector2D(0,1.0)) );
    sis.agregarPlaneta( Planeta("Mercurio", 0.055, Vector2D(0.4,0), Vector2D(0,1.6)) );

    for(int i=0;i<300;++i) sis.paso();
    sis.mostrar();
    return 0;
}

