# Orbita Newtoniana (F=G m1 m2/r^2) 
# utilizando Euler-Cromer, y usando la estrella en el centro  

# (unico requisito es instalar la librería pygame)
# Orbita Newtoniana usando Pygame y método Euler–Cromer
#importat librerías 
import math
import pygame

# Constantes 
G = 6.67430e-11         # constante de gravitación universal (newton) en N m^2/kg^2
M = 2.44e29             # kg masa de la estrella (en este caso Próxima Centauri ~0.122 masas solares, pero se puede cambiar)
AU = 1.496e11           # m   (una unidad astronómica, (la distancia del sol a la tierra) equivalente a 149,597,870,700 m )


# Condiciones iniciales 
r = [1.0*AU, 0.0]                      # posición 
v_circ = math.sqrt(G * M / (1.0*AU))
v = [0.0, v_circ]                      # velocidad 

# Simulación
DT = 3600.0            # s   (1 frame equivale a 1 hora )
Escala = 1e9            # m/px (1 px = 1e9 m)

# se inicia pygame 
pygame.init()
Ancho, Alto = 800, 800 # tamaño de la ventana, ancho y alto
screen = pygame.display.set_mode((Ancho, Alto))
pygame.display.set_caption("Orbitas Modificables")
clock = pygame.time.Clock() #frame rate en pygame 

# colores de los elementos 
ByG = (12, 14, 18)
estrella = (255, 210, 40)
planeta = (120, 170, 255)
recorrido = [] 
paused = False

def acel(x, y): # la Fuerza Central Gravitatoria (F=(-GMm/r^2)r), 
      #la aceleración = F/m= (-GM/r^3)r, y r= sqrt(x^2+y^2)
    d2 = x*x + y*y
    d = math.sqrt(d2)
    if d == 0:  
        return 0.0, 0.0
    f = -G * M / (d**3)
    return f*x, f*y

def pantalla(x, y):
    sx = Ancho//2 + int(x / Escala)
    sy = Alto//2 - int(y / Escala)
    return sx, sy

running = True
while running:
    for e in pygame.event.get():
        if e.type == pygame.QUIT:
            running = False
        elif e.type == pygame.KEYDOWN and e.key == pygame.K_SPACE:
            paused = not paused

    # Calculos físicos aplicando el método de euler-cromer (calcula a, luego actualiza la velocidad y después la posición utilizando esa velocidad)
    # el intervalo de tiempo DT= 1h
    if not paused:
        ax, ay = acel(r[0], r[1])
        v[0] += ax * DT
        v[1] += ay * DT
        r[0] += v[0] * DT 
        r[1] += v[1] * DT
        recorrido.append(pantalla(r[0], r[1]))
        if len(recorrido) > 1500:
            recorrido.pop(0)

    # dibujo 
    screen.fill(ByG)
    # se pone la estrella en el centro
    pygame.draw.circle(screen, estrella, (Ancho//2, Alto//2), 6)
    # estela
    if len(recorrido) > 1:
        pygame.draw.lines(screen, planeta, False, recorrido, 2)
    # planeta
    pygame.draw.circle(screen, planeta, pantalla(r[0], r[1]), 4)

    pygame.display.flip()
    clock.tick(60)

pygame.quit()
