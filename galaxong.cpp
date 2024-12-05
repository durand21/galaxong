#include "graphito.h"
#include "galaxong.h"
#include "nave.h"
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
    FormatoBorde(EB_CONTINUO, 5, borde_campo_cl);
    FormatoRelleno(ER_NORELLENO);
    Circulo(x_campo, y_campo, radio_campo);
}



void galaxong::rotar(int deltaAngulo) {
    angulo += deltaAngulo;
}


void galaxong::actualizar_puntuacion(int puntos_obtenidos) {
    puntos += puntos_obtenidos; // Incrementa la puntuación
}

