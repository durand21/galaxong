#include "graphito.h"
#include "galaxong.h"
#include "nave.h"

using namespace graphito;

int main() {
    // Inicializa la ventana
    VDefine(1000, 600, "Galaxong");
    galaxong gx;
    nave nave(400,250,0,CL_BLANCO);
    int tecla = 0;
    // Bucle de eventoss
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
