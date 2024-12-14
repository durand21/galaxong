#include "graphito.h"
#include "galaxong.h"
#include "nave.h"
#include "bicho.h"
using namespace graphito;

int main() {
     //---------- Declaracion de Variables
    std::vector<bicho> bichos;
     int btn_dibujado = false;
    int tecla = 0, xMouse = 0, yMouse = 0;
    int modera_x_bichos = 0, modera_y_bichos = 0;
     bool clicIzq = false, clicIzquierdoProcesado = false; // Marca si el clic izquierdo ya fue procesado
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
    nave nave(400, 250, 0, CL_ROJO, CL_AZUL);
    // Crea los bichos
    for (int i=0; i <4; i++){
        bichos.push_back(bicho(385+modera_x_bichos,235+ modera_y_bichos,CL_ROJO,CL_CAFE, 10));
        modera_x_bichos += 40;
        if (i == 1){
            modera_x_bichos = 0;
            modera_y_bichos = 37;
        }
        Espera(100);
    }

    FormatoBorde(EB_CONTINUO, 5,CL_BLANCO);
    Espera(100);// espera que el juego cargue
    // Bucle de eventos
    while (true) {
             // Obtener la posición del mouse
        Raton(xMouse, yMouse);  // Usamos la función Raton() de graphito para obtener las coordenadas del mouse

        // Detectar si el botón izquierdo está presionado
        clicIzq = RatonBotonIzq();

        // Procesar el clic izquierdo solo si no ha sido procesado aún
        if (clicIzq && !clicIzquierdoProcesado) {
            gx.manejar_eventos(xMouse, yMouse, clicIzq);
            clicIzquierdoProcesado = true; // Marca el clic como procesado
        } else if (!clicIzq) {
            clicIzquierdoProcesado = false; // Restablece el estado si se suelta el botón
        }

        // Actualiza el estado del juego
        gx.actualizar(); // Actualiza la lógica del juego

        tecla = Tecla();
        // Manejo de entrada
        if (tecla == VK_ESCAPE) {
            break; // Salir si se presiona Escape
        }

        // Mover la nave con teclas
        if (!gx.esta_pausado()) { // Solo permite mover si el juego no está en pausa
        // Mover la nave con teclas
        if (tecla == TC_IZQUIERDA) {
            nave.mover(-10, 0,5); // Mueve a la izquierda
            LimpiaMemoriaTecla();
        }
        if (tecla == TC_DERECHA) {
            nave.mover(-10, 0,-5); // Mueve a la derecha
            LimpiaMemoriaTecla();
        }
        /*if (tecla == TC_ARRIBA) {
            nav.mover(0, -10); // Mueve hacia arriba
            LimpiaMemoriaTecla();
        }
        if (tecla == TC_ABAJO) {
            nav.mover(0, 10); // Mueve hacia abajo
            LimpiaMemoriaTecla();
        }*/
    }
        // Dibuja los botones, puntuación y actualiza la pantalla

        gx.dibujar_puntuacion();


        if (btn_dibujado == false){ // Dibuja los botones, puntuación y actualiza la pantalla
            Espera(30);
            gx.dibujar_botones();
            btn_dibujado = true;
            Espera(30);
        }
        // Refresca la pantalla
        VRefresca();
        Espera(50); // Controla la velocidad del bucle

    }

    return 0;
}
