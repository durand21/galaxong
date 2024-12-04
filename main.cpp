#include "graphito.h"
#include "galaxong.h"

using namespace graphito;

int main() {
    // Inicializa la ventana
    VDefine(800, 600, "Juego de Nave");

    // Crea una instancia de galaxong
    galaxong nave(400, 300, 0, 400, 300, 100, CL_BLANCO);

    // Bucle de eventos
    while (true) {
        // Limpia la pantalla
        VLimpia();

        // Dibuja el campo
        nave.nuevo_juego();

        // Dibuja la nave
        nave.dibujar_nave();

        // Manejo de entrada
        if (Tecla() == VK_ESCAPE) {
            break; // Salir si se presiona Escape
        }

        // Mover la nave con teclas (ejemplo: flechas)
        if (Tecla() == TC_IZQUIERDA) {
            nave.mover(-5, 0); // Mueve a la izquierda
        }
        if (Tecla() == TC_DERECHA) {
            nave.mover(5, 0); // Mueve a la derecha
        }
        if (Tecla() == TC_ARRIBA) {
            nave.mover(0, -5); // Mueve hacia arriba
        }
        if (Tecla() == TC_ABAJO) {
            nave.mover(0, 5); // Mueve hacia abajo
        }

        // Refresca la pantalla
        VRefresca();
    }
    return 0;
}
