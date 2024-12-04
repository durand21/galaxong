#ifndef GALAXONG_H // Para evitar inclusiones m�ltiples
#define GALAXONG_H

#include "graphito.h"
using namespace graphito;

class galaxong {
private:
    int x, y, angulo; // coordenadas de la nave y �ngulo de apuntado hacia el centro
    int puntos;
    int cant_bloques; // Cantidad de bloques a dibujar en el c�rculo
    int x_campo, y_campo, radio_campo; // coordenadas y radio del campo
    int borde_campo_cl; // color del borde del campo

public:
    // Constructor
    galaxong(int _x = 400, int _y = 250, int _angulo = 0, int _x_campo = 400, int _y_campo = 250, int _radio_campo = 50, int _borde_campo_cl = CL_BLANCO);

    // M�todos
    void nuevo_juego();
    void mover(int deltaX, int deltaY); // M�todo para mover la nave
    void rotar(int deltaAngulo); // M�todo para rotar la nave
    void dibujar_nave(); // M�todo para dibujar la nave
};

#endif // GALAXONG_H
