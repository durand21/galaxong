#include "graphito.h"
#include "nave.h"
#include "galaxong.h"
#include <cmath>  // Para usar funciones trigonométricas
using namespace graphito;


nave::nave(int _x,int _y,int _angulo, int _color_alas,int _color){
    x = _x;
    y = _y;
    color = _color;
    color_alas = _color_alas;
    visible = false;

   /*   coordenadas_alas_nave = {
        {435, 406}, {415, 396}, {385, 396}, {365, 406}, {365, 436},
        {380, 426}, {393, 426}, {393, 431}, {407, 431}, {407, 426},
        {420, 426}, {435, 436}
    };

    coordenadas_body_nave = {
        {385, 382}, {390, 377}, {400, 377}, {410, 377},
        {415, 382}, {415, 387}, {410, 387}, {420, 402},
        {410, 402}, {420, 407}, {420, 437}, {400, 422},
        {380, 437}, {380, 407}, {390, 402}, {380, 402},
        {390, 387}, {385, 387}
    };
*/

    coordenadas_alas_nave ={
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
    };
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

void nave::mover(int _x, int _y) {
    // Verificar que la nueva posición no se salga del círculo
    for (auto& coordenada : coordenadas_alas_nave) {
        int nueva_x = coordenada[0] + _x;
        int nueva_y = coordenada[1] + _y;
        // Comprobar si la coordenada está dentro del círculo
        if ((nueva_x - 400) * (nueva_x - 400) + (nueva_y - 250) * (nueva_y - 250) > 200 * 200) {
            return; // Si alguna coordenada está fuera, no hacer el movimiento
        }
    }

    for (auto& coordenada : coordenadas_body_nave) {
        int nueva_x = coordenada[0] + _x;
        int nueva_y = coordenada[1] + _y;
        // Comprobar si la coordenada está dentro del círculo
        if ((nueva_x - 400) * (nueva_x - 400) + (nueva_y - 250) * (nueva_y - 250) > 200 * 200) {
            return; // Si alguna coordenada está fuera, no hacer el movimiento
        }
    }


    ocultar();
    // Iteración para modificar cada coordenada de la ala de la nave
    for (auto& coordenada : coordenadas_alas_nave) { // Usa referencia para modificar el vector
        coordenada[0] += _x; // Sumar deltaX a la coordenada x
        coordenada[1] += _y; // Sumar deltaY a la coordenada y
    }
    // Iteración para modificar cada coordenada del cuerpo
    for (auto& coordenada : coordenadas_body_nave) { // Usa referencia para modificar el vector
        coordenada[0] += _x; // Sumar deltaX a la coordenada x
        coordenada[1] += _y; // Sumar deltaY a la coordenada y
    }
    dibujar_nave();
}
