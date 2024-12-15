#pragma once
#include "graphito.h"
using namespace graphito;

class bicho{
private:
    int x, y; // coordenadas de la nave y ángulo de apuntado hacia el centro
    int color_body, color_patas;
    bool visible;
    int ancho_bicho;
    int ancho_ojos;
    friend class nave;
public:
    bicho(int  _x = 0,int _y = 0, int _color_body = CL_ROJO, int _color_patas = CL_AMARILLO, int _ancho_bicho=10);
    void dibujar_bicho(); // Método para dibujar la nave
    void ocultar();
    void mover(int deltaX, int deltaY); // Método para mover la nave
};

