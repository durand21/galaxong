#include "graphito.h"
#include "bicho.h"
using namespace graphito;

bicho::bicho(int _x,int _y, int _color_body, int _color_patas, int _ancho_bicho){
    x = _x;
    y = _y;
    color_body = _color_body;
    color_patas = _color_patas;
    ancho_bicho = _ancho_bicho;
    ancho_ojos = 3;
    visible = false;
    dibujar_bicho();
}

void bicho::dibujar_bicho() {
    if (!visible) {
        int mitad_ancho_bicho = ancho_bicho/2;
        int x_menos_radio = x-ancho_bicho, y_menos_radio = y-ancho_bicho;
        int x_mas_radio = x+ancho_bicho, y_mas_radio = y+ancho_bicho;
        // cuerpo
        FormatoBorde(EB_CONTINUO, 4, color_patas);
        FormatoRelleno(ER_SOLIDO,color_body);
        Circulo(x,y,ancho_bicho);
          Espera(30);
        //---------------- Patas
        FormatoBorde(EB_CONTINUO, 2, color_patas);
        FormatoRelleno(ER_SOLIDO, color_patas);
             //----//
        Linea(x_menos_radio,y_menos_radio,x_menos_radio-10,y_menos_radio-10);  // izquierda arriba
        Linea(x_mas_radio,y_menos_radio,x_mas_radio+10,y_menos_radio-10); // derecha arriba
         Espera(30);
        Linea(x_menos_radio,y_mas_radio,x_menos_radio-10,y_menos_radio+30);// izqquierda abajo
        Linea(x_mas_radio,y_mas_radio,x_mas_radio+10,y_menos_radio+30); // derecha. abajo
        Espera(10);
        //---------------- Ojos
        FormatoBorde(EB_CONTINUO, 3, CL_NEGRO);
        FormatoRelleno(ER_SOLIDO,CL_NEGRO);
        Circulo(x-mitad_ancho_bicho,y+mitad_ancho_bicho,ancho_ojos); // ojo izquierda
        Circulo(x+mitad_ancho_bicho,y+mitad_ancho_bicho,ancho_ojos); // ojo derecha

        visible = true;
    }
}

void bicho::ocultar(){
    if(visible){
        int colortmp_body = color_body;
        int colortmp_patas = color_patas;
        color_body = CL_NEGRO;
        color_patas = CL_NEGRO;
        visible = false;
        dibujar_bicho();
        // Espera a dibujar
            Espera(100);
        visible = false;
        color_body = colortmp_body;
        color_patas = colortmp_patas;
        x=0, y=0, ancho_bicho=0;
    }
}
