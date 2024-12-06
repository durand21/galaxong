#include "graphito.h"
#include "galaxong.h"
#include "nave.h"

using namespace graphito;

int main() {
    // Inicializa la ventana
    VDefine(1000, 560, "Galaxong");
    FormatoBorde(EB_CONTINUO, 0, CL_BLANCO);
    FormatoRelleno(ER_SOLIDO, CL_GRIS);
    // Dibuja el rectángulo ajustado: más hacia la derecha y con mayor altura
    Rectangulo(1000, 0, 770, 650);
    // Iniciliaza el juego y la nave ante de renderizar el menu y los puntajes.
    galaxong gx;
    // Da tiempo a renderizar
    Espera(500);
    nave nave(400, 250, 0, CL_AZUL);
    // Da tiempo a renderizar
        Espera(90);
    FormatoBorde(EB_CONTINUO, 5,CL_BLANCO);
    // Configuración del texto
    TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO); // Fuente Time New Roman con tamaño 32
    TMostrar(810, 80, 360, 50, "Puntos: 0");
    // Da tiempo a renderizar
        Espera(90);
    TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO); // Fuente Arial con tamaño 20
    TMostrar(810, 140, 360, 50, "Disparos: 0");
    // Da tiempo a renderizar
        Espera(90);
    TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO); // Fuente Arial con tamaño 20
    TMostrar(810, 200, 360, 50, "Enemigos: 0");
    // Da tiempo a renderizar
        Espera(90);
        // Creamos nuevos botónes en la posición central entre "Pausar" y "Reiniciar Y salir"
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    RectanguloRedondeado(985, 280, 780, 340, 10);
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    RectanguloRedondeado(985, 405, 780, 350, 10);
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    RectanguloRedondeado(985, 470, 780, 415, 10);  // Ajusta la altura y la posición del rectángulo azul

    // Configura el texto para cada botón
    TFormato("Times New Roman", 27, 0, FT_NEGRITA, CL_BLANCO);
    TMostrar(850, 307, 125, 45, "Pausar");
    TMostrar(840, 375, 120, 35, "Reiniciar");
    TMostrar(860, 445, 120, 35, "Salir");

    int tecla = 0;

    // Bucle de eventos
    while (true) {
        tecla = Tecla();
        // Manejo de entrada
        if (tecla == VK_ESCAPE) {
            break; // Salir si se presiona Escape
        }

        // Mover la nave con teclas
        if (tecla == TC_IZQUIERDA) {
            nave.mover(-5, 0); // Mueve a la izquierda
            LimpiaMemoriaTecla();
        }
        if (tecla == TC_DERECHA) {
            nave.mover(5, 0); // Mueve a la derecha
            LimpiaMemoriaTecla();
        }
        if (tecla == TC_ARRIBA) {
            nave.mover(0, -5); // Mueve hacia arriba
            LimpiaMemoriaTecla();
        }
        if (tecla == TC_ABAJO) {
            nave.mover(0, 5); // Mueve hacia abajo
            LimpiaMemoriaTecla();
        }

        // Refresca la pantalla
        VRefresca();
        Espera(50); // Controla la velocidad del bucle

    }

    return 0;
}
