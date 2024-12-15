#pragma once
#include "graphito.h"
#include "bicho.h"
using namespace graphito;

class nave{
private:
    // Estructura para representar un punto
    struct Punto {
        int x, y;
    };
    // Coordenadas del cuerpo de la nave y alas
    std::vector<std::array <int,2>> coordenadas_alas_nave, coordenadas_body_nave;
    std::array<int,2> punta_nave;
    // coordenadas de la nave y ángulo de apuntado hacia el centro
    int x, y, x_centroide, y_centroide;
    int color, color_alas;
    bool visible, bala_visible;
    int angulo, angulo_acumulado;
    int color_balas, ancho_balas;
    void ocultar();
    int j;
    void dibujar_nave(); // Método para dibujar la nave
    void init_coordenadas(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo);
    void init_coordenadas_inv(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo);
    void rotar_figura(std::vector<std::array <int,2>>& coordenadas_alas,std::vector<std::array <int,2>>& coordenadas_cuerpo, double _x_centroide, double _y_centroide, double angulo);
public:
    nave(int  _x = 0,int _y = 0,int _angulo =0 , int _color_alas = CL_ROJO, int _color = CL_AZUL);
    void mover(int _x, int _y, int _angulo_mover); // Método para mover la nave
    void disparar(int paso, int _color_borde_circulo, int _x_circulo, int _y_circulo, int _radio_campo, std::vector<bicho>& _bichos
                  , int& _puntos, int&_disparos);
};
