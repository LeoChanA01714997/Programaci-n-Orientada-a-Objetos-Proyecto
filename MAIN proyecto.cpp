#include "Sistema.hpp"

int main(){
    Sistema sis(0.01);

    sis.agregarEstrella( Estrella("Sol",    1000, Vector2D(0,0),   Vector2D(0,0)) );
    sis.agregarPlaneta ( Planeta ("Tierra", 1.0,  Vector2D(1,0),   Vector2D(0,1)) );
    sis.agregarSatelite( Satelite("Luna",   0.01, Vector2D(1.2,0), Vector2D(0,1.2)) );

    Planeta mercurio("Mercurio", 0.055, Vector2D(0.4,0), Vector2D(0,1.6));
    sis.agregarExterno(&mercurio);

    for(int i=0;i<300;++i) sis.paso();
    sis.mostrar();
    return 0;
}


