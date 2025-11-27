int main() {

    // 1. Vector2D
    Vector2D v1(3.0, 4.0);
    std::cout << "Magnitud: " << v1.magnitud() << "\n";
    v1.imprimir();

    // 2. CuerpoCeleste
    CuerpoCeleste planeta(
        "Planeta Azul",
        5.9e24,
        Vector2D(1.0e6, 2.0e6),
        Vector2D(500.0, -200.0)
    );

    planeta.imprimirDatos();
    planeta.mover(1000.0, 500.0);
    planeta.actualizarVelocidad(Vector2D(0.2, -0.1), 5.0);
    planeta.actualizarPosicion(5.0);

    std::cout << "Después de actualizar:\n";
    planeta.imprimirDatos();

    // 3. RenderConfig
    RenderConfig config(800, 800, 1e6);
    config.imprimir();

    auto pantalla = config.convertir(Vector2D(2.0e6, -1.0e6));
    std::cout << "Coordenadas convertidas: (" 
              << pantalla.first << ", " << pantalla.second << ")\n";

    return 0;
}

