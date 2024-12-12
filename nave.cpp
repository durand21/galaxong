#include "graphito.h"
#include "nave.h"
#include <vector>
#include <cmath>
#include <utility>
using namespace graphito;

nave::nave(int _x,int _y,int _angulo, int _color_alas,int _color){
    x = _x;
    y = _y;
    color = _color;
    color_alas = _color_alas;
    visible = false;
    angulo_acumulado =0;
    init_coordenadas(coordenadas_alas_nave, coordenadas_body_nave);
    /*coordenadas_alas_nave ={
        {418, 423}, {408, 418}, {392, 418}, {382, 423}, {382, 438},
        {390, 433}, {396, 433}, {396, 435}, {403, 435}, {403, 433},
        {410, 433}, {418, 438}
    };
    coordenadas_body_nave = {
        {392, 411}, {395, 409}, {400, 409}, {405, 409},
        {408, 411}, {408, 414}, {405, 414}, {410, 421},
        {405, 421}, {410, 423}, {410, 439}, {400, 431},
        {390, 439}, {390, 423}, {395, 421}, {390, 421},
        {395, 414}, {392, 414}
    };*/
    dibujar_nave();
}

void nave::dibujar_nave() {
    if (!visible) {
        // Alas rojas
        FormatoBorde(EB_CONTINUO, 1, color_alas);
        FormatoRelleno(ER_SOLIDO,color_alas);
        PoligonoIrregular(coordenadas_alas_nave);
        // Espera a dibujar
            Espera(30);
        //Cuerpo Azul
        FormatoBorde(EB_CONTINUO, 1, color);
        FormatoRelleno(ER_SOLIDO,color);
        PoligonoIrregular(coordenadas_body_nave);
        FormatoRelleno(ER_SOLIDO,CL_ROJO);
        visible = true;
    }
}

void nave::ocultar(){
    if(visible){
        int colortmp = color;
        int color_alastmp = color_alas;
        color = CL_NEGRO;
        color_alas = CL_NEGRO;
        visible = false;
        dibujar_nave();
        // Espera a dibujar
            Espera(100);
        visible = false;
        color = colortmp;
        color_alas = color_alastmp;
    }
}

void nave::mover(int _x, int _y, int _angulo_mover) {
    int x_centro_bd, y_centro_bd;
    int x_centro_ala, y_cento_ala;
    angulo_acumulado = (angulo_acumulado + (_angulo_mover));
/*------------ Calcula el centro de la nave
    calcular_centroide(coordenadas_body_nave, x_centro_bd, y_centro_bd);
    calcular_centroide(coordenadas_alas_nave, x_centro_ala, y_cento_ala);
    calcular_centroide({{x_centro_bd,y_centro_bd},{x_centro_ala,y_cento_ala}}, x_centroide, y_centroide);*/
//---- calcula la rotacion de la nave
    ocultar();
    Espera(30);
    rotar_figura(coordenadas_alas_nave, coordenadas_body_nave, 395/*x_centroide*/, 258/*y_centroide*/, _angulo_mover);
    if (angulo_acumulado == 0 || angulo_acumulado == 360)
        init_coordenadas(coordenadas_alas_nave,coordenadas_body_nave);
    dibujar_nave();
}
/*/ Funcion para promediar el centro de la nave
void nave::calcular_centroide(std::vector<std::array <int,2>> puntos, int& x_centroide, int& y_centroide) {
    int n = puntos.size();
    int suma_x = 0, suma_y = 0;

    for (const auto& punto : puntos) {
        suma_x += punto[0];
        suma_y += punto[1];
    }

    x_centroide = (suma_x / n);
    y_centroide = (suma_y / n);
}*/

/*/ Función para rotar un punto alrededor del origen
nave::Punto nave::rotar_punto(const Punto& punto, double angulo_radianes) {
    double cos_theta = cos(angulo_radianes);
    double sin_theta = sin(angulo_radianes);
    return {punto.x * cos_theta - punto.y * sin_theta,
            punto.x * sin_theta + punto.y * cos_theta};
}*/

// Función para calcular rotacion de una figura alrededor de su centroide
void nave::rotar_figura(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo,
                  double x_centroide, double y_centroide, double angulo) {
    // Convertir el ángulo a radianes
    double angulo_radianes = angulo * M_PI / 180;

    // Calcular seno y coseno una sola vez para optimizar
    double cos_theta = cos(angulo_radianes);
    double sin_theta = sin(angulo_radianes);

    // Rotar las alas
    for (auto& punto : coordenadas_alas) {
        // Calcular las coordenadas relativas al centroide
        double x_relativo = punto[0] - x_centroide;
        double y_relativo = punto[1] - y_centroide;

        // Aplicar la matriz de rotación
        double x_rotado = (x_relativo * cos_theta - y_relativo * sin_theta) + x_centroide;
        double y_rotado = (x_relativo * sin_theta + y_relativo * cos_theta) + y_centroide;

        // Actualizar las coordenadas del punto
        punto[0] = static_cast<int>((x_rotado));
        punto[1] = static_cast<int>((y_rotado));
    }

    // Rotar el cuerpo
    for (auto& punto : coordenadas_cuerpo) {
        // Calcular las coordenadas relativas al centroide
        double x_relativo = punto[0] - x_centroide;
        double y_relativo = punto[1] - y_centroide;

        // Aplicar la matriz de rotación
        double x_rotado = x_relativo * cos_theta - y_relativo * sin_theta + x_centroide;
        double y_rotado = x_relativo * sin_theta + y_relativo * cos_theta + y_centroide;

        // Actualizar las coordenadas del punto
        punto[0] = static_cast<int>((x_rotado));
        punto[1] = static_cast<int>((y_rotado));
    }
}

void nave::init_coordenadas(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo){
    coordenadas_alas ={
        {418, 423}, {408, 418}, {392, 418}, {382, 423}, {382, 438},
        {390, 433}, {396, 433}, {396, 435}, {403, 435}, {403, 433},
        {410, 433}, {418, 438}
    };
    coordenadas_cuerpo = {
        {392, 411}, {395, 409}, {400, 409}, {405, 409},
        {408, 411}, {408, 414}, {405, 414}, {410, 421},
        {405, 421}, {410, 423}, {410, 439}, {400, 431},
        {390, 439}, {390, 423}, {395, 421}, {390, 421},
        {395, 414}, {392, 414}
    };

}

void nave::init_coordenadas_inv(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo){
coordenadas_alas = {{-418, -423}, {-408, -418}, {-392, -418}, {-382, -423}, {-382, -438},
                     {-390, -433}, {-396, -433}, {-396, -435}, {-403, -435}, {-403, -433},
                     {-410, -433}, {-418, -438}};

coordenadas_cuerpo = {{-392, -411}, {-395, -409}, {-400, -409}, {-405, -409},
                      {-408, -411}, {-408, -414}, {-405, -414}, {-410, -421},
                      {-405, -421}, {-410, -423}, {-410, -439}, {-400, -431},
                      {-390, -439}, {-390, -423}, {-395, -421}, {-390, -421},
                      {-395, -414}, {-392, -414}};

}
