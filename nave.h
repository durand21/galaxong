#include "graphito.h"
using namespace graphito;

class nave{
private:
    int x, y, angulo; // coordenadas de la nave y ángulo de apuntado hacia el centro
    int color, color_alas;
    bool visible;
    std::vector<std::array <int,2>> coordenadas_alas_nave;
    std::vector<std::array <int,2>> coordenadas_body_nave;
    int angulo_acumulado;
    // Estructura para representar un punto
    struct Punto {
        int x, y;
    };
public:
    nave(int  _x = 0,int _y = 0,int _angulo =0 , int _color_alas = CL_ROJO, int _color = CL_AZUL);
    void init_coordenadas(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo);
    void init_coordenadas_inv(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo);
    void dibujar_nave(); // Método para dibujar la nave
    void ocultar();
    void mover(int _x, int _y, int _angulo_mover); // Método para mover la nave
    void rotar_figura(std::vector<std::array <int,2>>& coordenadas_alas,std::vector<std::array <int,2>>& coordenadas_cuerpo,
                  double x_centroide, double y_centroide, double angulo);
};
