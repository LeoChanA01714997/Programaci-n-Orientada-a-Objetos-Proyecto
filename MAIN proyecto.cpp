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
