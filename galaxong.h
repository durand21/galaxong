#include "graphito.h"
using namespace graphito;

class galaxong {
private:
    int x, y, angulo; // coordenadas de la nave y angulo de apuntado hacia el centro
    int puntos;
    int cant_bloques; // Cantidad de bloques a dibujar en el circulo
    int x_campo, y_campo, radio_campo; // coordenadas y radio del campo
    int borde_campo_cl; // color del borde del campo

public:
    // Constructor
    galaxong(int _x = 400, int _y = 250, int _angulo = 0, int _x_campo = 400, int _y_campo = 250, int _radio_campo = 200, int _borde_campo_cl = CL_BLANCO);

    // Metodos
    void nuevo_juego();
    void rotar(int deltaAngulo); // Metodo para rotar la nave

};
