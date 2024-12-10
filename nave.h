#include "graphito.h"
using namespace graphito;

class nave{
private:
    int x, y, angulo; // coordenadas de la nave y ángulo de apuntado hacia el centro
    int color, color_alas;
    bool visible;
    std::vector<std::array <int,2>> coordenadas_alas_nave;
    std::vector<std::array <int,2>> coordenadas_body_nave;
public:
    nave(int  _x = 0,int _y = 0,int _angulo =0 , int _color_alas = CL_ROJO, int _color = CL_AZUL);
    void dibujar_nave(); // Método para dibujar la nave
    void ocultar();
    void mover(int deltaX, int deltaY); // Método para mover la nave
};
