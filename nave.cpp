#include "graphito.h"
#include "nave.h"
#include "galaxong.h"
#include <vector>
#include <cmath>
#include <utility>
using namespace graphito;

nave::nave(int _x,int _y,int _angulo, int _color_alas,int _color){
    x = _x;
    y = _y;
    x_centroide = 395, y_centroide = 258;
    color = _color;
    color_alas = _color_alas;
    visible = false, bala_visible = false;
    angulo_acumulado =0;
    color_balas = CL_BLANCO, ancho_balas = 5;
    init_coordenadas(coordenadas_alas_nave, coordenadas_body_nave);
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
    angulo_acumulado = (angulo_acumulado + (_angulo_mover));
//---- calcula la rotacion de la nave
    ocultar();
    Espera(30);
    rotar_figura(coordenadas_alas_nave, coordenadas_body_nave, x_centroide, y_centroide, _angulo_mover);
    if (angulo_acumulado == 0 || angulo_acumulado == 360)
        init_coordenadas(coordenadas_alas_nave,coordenadas_body_nave);
    dibujar_nave();
}

// Función para calcular rotacion de una figura alrededor de su centroide
void nave::rotar_figura(std::vector<std::array <int,2>>& coordenadas_alas, std::vector<std::array <int,2>>& coordenadas_cuerpo,
                  double _x_centroide, double _y_centroide, double angulo) {
    // Convertir el ángulo a radianes
    double angulo_radianes = angulo * M_PI / 180;

    // Calcular seno y coseno una sola vez para optimizar
    double cos_theta = cos(angulo_radianes);
    double sin_theta = sin(angulo_radianes);

    // Rotar las alas
    for (auto& punto : coordenadas_alas) {
        // Calcular las coordenadas relativas al centroide
        double x_relativo = punto[0] - _x_centroide;
        double y_relativo = punto[1] - _y_centroide;

        // Aplicar la matriz de rotación
        double x_rotado = (x_relativo * cos_theta - y_relativo * sin_theta) + _x_centroide;
        double y_rotado = (x_relativo * sin_theta + y_relativo * cos_theta) + _y_centroide;

        // Actualizar las coordenadas del punto
        punto[0] = static_cast<int>((x_rotado));
        punto[1] = static_cast<int>((y_rotado));
    }

    // Rotar el cuerpo
    for (auto& punto : coordenadas_cuerpo) {
        // Calcular las coordenadas relativas al centroide
        double x_relativo = punto[0] - _x_centroide;
        double y_relativo = punto[1] - _y_centroide;

        // Aplicar la matriz de rotación
        double x_rotado = x_relativo * cos_theta - y_relativo * sin_theta + _x_centroide;
        double y_rotado = x_relativo * sin_theta + y_relativo * cos_theta + _y_centroide;

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
void dibuja_bala(const int _color_balas,const int& _ancho_bala, const std::array<int,2>& punta_nave, bool& _bala_visible){
    if (!_bala_visible){
        FormatoRelleno(ER_SOLIDO,_color_balas);
        FormatoBorde(EB_CONTINUO,0,CL_NEGRO);
        Circulo(punta_nave[0],punta_nave[1], _ancho_bala);
        _bala_visible = true;
    }
}
void oculta_bala(const int& _ancho_bala, const std::array<int,2>& punta_nave, bool& _bala_visible ){
    if(_bala_visible){
        _bala_visible = false;
        dibuja_bala(CL_NEGRO, _ancho_bala, punta_nave, _bala_visible);
        _bala_visible = false;
    }
}

void nave::disparar(int paso, int _color_borde_circulo, int _x_circulo, int _y_circulo, int _radio_campo,
                    std::vector<bicho>& _bichos, int& _puntos, int& _disparos, int& _enemigos) {
    // paso es cada cuantos píxeles avanza
    punta_nave = coordenadas_body_nave[2];
    float x = punta_nave[0], y = punta_nave[1];
    float dx = x_centroide - x, dy = y_centroide - y;
    float magnitud = 0.00, direccion_x = 0.00, direccion_y = 0.00;

    while (fabs(x - x_centroide) > paso || fabs(y - y_centroide) > paso) {
        oculta_bala(ancho_balas, punta_nave, bala_visible);
        dx = x_centroide - x;
        dy = y_centroide - y;
        magnitud = sqrt(dx * dx + dy * dy);
        direccion_x = dx / magnitud;
        direccion_y = dy / magnitud;

        // Mover el punto
        punta_nave[0] += direccion_x * paso;
        punta_nave[1] += direccion_y * paso;

        // Validar límites del círculo en X y Y
        if (punta_nave[0] >= _x_circulo + _radio_campo || punta_nave[0] <= _x_circulo - _radio_campo) {
            oculta_bala(ancho_balas, punta_nave, bala_visible);
            FormatoBorde(EB_CONTINUO, 5, _color_borde_circulo);
            FormatoRelleno(ER_NORELLENO);
            Circulo(_x_circulo, _y_circulo, _radio_campo);
            Espera(100);
            _disparos++; // Incrementar disparos cuando la bala sale del campo
            return;
        }
        if (punta_nave[1] >= _y_circulo + _radio_campo || punta_nave[1] <= _y_circulo - _radio_campo) {
            oculta_bala(ancho_balas, punta_nave, bala_visible);
            FormatoBorde(EB_CONTINUO, 5, _color_borde_circulo);
            FormatoRelleno(ER_NORELLENO);
            Circulo(_x_circulo, _y_circulo, _radio_campo);
            Espera(100);
            _disparos++; // Incrementar disparos cuando la bala sale del campo
            return;
        }

        dibuja_bala(color_balas, ancho_balas, punta_nave, bala_visible);
        j++;
        Espera(30);

        // Validar si le da a un bicho
        if (_bichos.empty()) {
            Mensaje("¡Felicidades, el juego terminó!");
            VCierra();  // Cierra la ventana
        }

        for (int i = 0; i < _bichos.size(); i++) {
            if ((punta_nave[0] > _bichos[i].x - _bichos[i].ancho_bicho &&
                 punta_nave[0] < _bichos[i].x + _bichos[i].ancho_bicho) &&
                (punta_nave[1] > _bichos[i].y - _bichos[i].ancho_bicho &&
                 punta_nave[1] < _bichos[i].y + _bichos[i].ancho_bicho)) {
                oculta_bala(ancho_balas, punta_nave, bala_visible);
                _bichos[i].ocultar();  // Ocultar el bicho
                _bichos.erase(_bichos.begin() + i);  // Eliminar bicho del vector
                _puntos += 10;       // Sumar puntos
                _enemigos++;         // Incrementar enemigos eliminados
                _disparos++;         // Incrementar número de disparos realizados
                return;
            }
        }
        Espera(30);
    }
    _puntos -= 3; // Penalización por no acertar
    _disparos++;  // Incrementar disparos al final
}

