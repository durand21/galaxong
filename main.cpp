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

    FormatoBorde(EB_CONTINUO, 5,CL_BLANCO);


    int tecla = 0;
    int xMouse = 0, yMouse = 0;
    bool clicIzq = false;

    // Bucle de eventos
    while (true) {
             // Obtener la posición del mouse
        Raton(xMouse, yMouse);  // Usamos la función Raton() de graphito para obtener las coordenadas del mouse

        // Detectar si el botón izquierdo está presionado
        clicIzq = RatonBotonIzq();  // Usamos la función RatonBotonIzq() para saber si el botón izquierdo está presionado

        // Maneja los eventos de los botones con el mouse
        gx.manejar_eventos(xMouse, yMouse, clicIzq);

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

        // Dibuja los botones, puntuación y actualiza la pantalla
        gx.dibujar_botones();
        gx.dibujar_puntuacion();

        // Refresca la pantalla
        VRefresca();
        Espera(50); // Controla la velocidad del bucle

    }

    return 0;
}
