#include "graphito.h"
using namespace graphito;

class nave{
private:
    int x, y, angulo; // coordenadas de la nave y �ngulo de apuntado hacia el centro
    int color;
    bool visible;
public:
    nave(int  _x = 0,int _y = 0,int _angulo =0 , int _borde_campo_cl = CL_BLANCO);
    void dibujar_nave(); // M�todo para dibujar la nave
    void ocultar();
    void mover(int deltaX, int deltaY); // M�todo para mover la nave
};
