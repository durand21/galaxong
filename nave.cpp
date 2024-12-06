#include "graphito.h"
#include "nave.h"
using namespace graphito;

nave::nave(int _x,int _y,int _angulo,int _color ){
    x = _x;
    y = _y;
    color = _color;
    visible = false;
    dibujar_nave();
}

void nave::dibujar_nave() {
    if (!visible) {
        // Espera a dibujar
            Espera(500);
        // Alas rojas
        FormatoBorde(EB_CONTINUO, 1, CL_ROJO);
        FormatoRelleno(ER_SOLIDO,CL_ROJO);
        PoligonoIrregular({ {435, 370},{415,360},{385,360},{365,370},{365,400},{380,390},
                          {393,390},{393,395},{407,395},{407,390},
                          {420,390},{435,400}
                        });
        // Espera a dibujar
            Espera(100);
            //Cuerpo Azul
        FormatoBorde(EB_CONTINUO, 1, color);
        FormatoRelleno(ER_SOLIDO,color);
        PoligonoIrregular({ {385, 346}, {390, 341}, {400, 341}, {410, 341},
                            {415, 346}, {415, 351}, {410, 351}, {420, 366},
                            {410, 366}, {420, 371}, {420, 401}, {400, 386},
                            {380, 401}, {380, 371}, {390, 366}, {380, 366},
                            {390, 351}, {385, 351}}
                        );
        FormatoRelleno(ER_SOLIDO,CL_ROJO);
        visible = true;
    }
}

void nave::ocultar(){
    if(visible){
        // Espera a dibujar
            Espera(100);

        int colortmp = color;
        color = CL_NEGRO;
        visible = false;
        dibujar_nave();
        visible = false;
        color = colortmp;
    }
}

void nave::mover(int _x, int _y) {
    ocultar();
    x += _x;
    y += _y;
    dibujar_nave();
}

