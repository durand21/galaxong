
#include "graphito.h"
#include "nave.h"
using namespace graphito;

nave::nave(int _x,int _y,int _angulo,int _color ){
    x = _x;
    y = _y;
    color = _color;
    visible = false;
    dibujar_nave();
}

void nave::dibujar_nave() {
    if (!visible) {
        FormatoBorde(EB_CONTINUO, 5, color);
        int base = 10;
        int altura = 20;

        // Coordenadas de los vertices del triangulo
        int x1 = x;
        int y1 = y - altura / 2;
        int x2 = x - base / 2;
        int y2 = y + altura / 2;
        int x3 = x + base / 2;
        int y3 = y + altura / 2;

        // Dibuja el triangulo usando lineas
        Linea(x1, y1, x2, y2);
        Linea(x2, y2, x3, y3);
        Linea(x3, y3, x1, y1);
        visible = true;
    }
}

void nave::ocultar(){
    if(visible){
        int colortmp = color;
        color = CL_NEGRO;
        visible = false;
        dibujar_nave();
        visible = false;
        color = colortmp;
    }
}

void nave::mover(int _x, int _y) {
    ocultar();
    x += _x;
    y += _y;
    dibujar_nave();
}

