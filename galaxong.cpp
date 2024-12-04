#include "graphito.h"
#include "galaxong.h"
using namespace graphito;

galaxong::galaxong(int _x, int _y, int _angulo, int _x_campo, int _y_campo, int _radio_campo, int _borde_campo_cl) {
    x = _x;
    y = _y;
    angulo = _angulo;
    puntos = 0;
    cant_bloques = 0;

    x_campo = _x_campo;
    y_campo = _y_campo;
    radio_campo = _radio_campo;
    borde_campo_cl = _borde_campo_cl;

    nuevo_juego();
}

void galaxong::nuevo_juego() {
    // Establece el color del borde del campo
    graphito::FormatoBorde(EB_CONTINUO, 1, borde_campo_cl);

    // Dibuja el campo circular
    graphito::Circulo(x_campo, y_campo, radio_campo);
}

void galaxong::mover(int deltaX, int deltaY) {
    x += deltaX;
}

void galaxong::rotar(int deltaAngulo) {
    angulo += deltaAngulo;
}

void galaxong::dibujar_nave() {
    // Suponiendo que la nave es un triángulo
    int base = 10; // Base del triángulo
    int altura = 20; // Altura del triángulo

    // Coordenadas de los vértices del triángulo
    int x1 = x;
    int y1 = y - altura / 2; // Vértice superior
    int x2 = x - base / 2;
    int y2 = y + altura / 2; // Vértice inferior izquierdo
    int x3 = x + base / 2;
    int y3 = y + altura / 2; // Vértice inferior derecho

    // Dibuja el triángulo usando líneas
    graphito::Linea(x1, y1, x2, y2);
    graphito::Linea(x2, y2, x3, y3);
    graphito::Linea(x3, y3, x1, y1);
}
