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

    void imprimir() const {
        std::cout << "Vector(" << x << ", " << y << ")" << std::endl;
    }
};


class CuerpoCeleste {
private:
    std::string nombre;
    double masa;
    Vector2D posicion;

public:
    CuerpoCeleste(const std::string& nombre, double masa, const Vector2D& pos)
        : nombre(nombre), masa(masa), posicion(pos) {}

    void mover(double dx, double dy) {
        posicion.setX(posicion.getX() + dx);
        posicion.setY(posicion.getY() + dy);
    }

    void imprimirDatos() const {
        std::cout << "Cuerpo: " << nombre << "\n"
                  << "Masa: " << masa << " kg\n"
                  << "Posicion: ";
        posicion.imprimir();
    }
};

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
        std::cout << "RenderConfig -> ancho: " << ancho
                  << ", alto: " << alto
                  << ", escala: " << escala << std::endl;
    }
};


int main() {

    // Vector2D
    Vector2D v1(3.0, 4.0);
    std::cout << "Magnitud del vector: " << v1.magnitud() << std::endl;
    v1.imprimir();

    //CuerpoCeleste
    CuerpoCeleste planeta("Planeta X", 5.9e24, Vector2D(1.0e6, 2.0e6));
    planeta.imprimirDatos();
    planeta.mover(1000.0, -500.0);
    std::cout << "Despues de mover:\n";
    planeta.imprimirDatos();

    //RenderConfig
    RenderConfig config(800, 800, 1e6);
    config.imprimir();

    auto coords = config.convertir(Vector2D(2.0e6, -1.0e6));
    std::cout << "Coordenadas convertidas: (" 
              << coords.first << ", " << coords.second << ")" << std::endl;

    return 0;
}
 