#include "graphito.h"
#include "galaxong.h"
#include "nave.h"
using namespace graphito;

galaxong::galaxong(int _x, int _y, int _angulo, int _x_campo, int _y_campo, int _radio_campo, int _borde_campo_cl)
    : x(_x), y(_y), angulo(_angulo), puntos(0), disparos(0), enemigos(0),
      x_campo(_x_campo), y_campo(_y_campo), radio_campo(_radio_campo),
      borde_campo_cl(_borde_campo_cl), pausado(false),
      botonPausar(780, 280, 985, 340, "Pausar"),
      botonReiniciar(780, 350, 985, 405, "Reiniciar"),
      botonSalir(780, 415, 985, 470, "Salir") {
    nuevo_juego();
}

void galaxong::nuevo_juego() {
    puntos = 0;
    disparos = 0;
    enemigos = 0;
    pausado = false;
    Mensaje("Bienvenidos al juego de galaxong");
    //Esperar asi mejora rendimiento
    Espera(500);
    // Establece el color del borde del campo
    FormatoBorde(EB_CONTINUO, 5, borde_campo_cl);
    FormatoRelleno(ER_NORELLENO);
    Circulo(x_campo, y_campo, radio_campo);
}

void galaxong::rotar(int deltaAngulo) {
    angulo += deltaAngulo;
}


void galaxong::actualizar_puntuacion(int puntos_obtenidos) {
    puntos += puntos_obtenidos; // Incrementa la puntuaci�n
}

void galaxong::dibujar_puntuacion() {
     // Da tiempo a renderizar
        Espera(90);
    TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO);
    TMostrar(810, 80, 360, 50, ("Puntos: " + std::to_string(puntos)).c_str());
    TMostrar(810, 140, 360, 50, ("Disparos: " + std::to_string(disparos)).c_str());
    TMostrar(810, 200, 360, 50, ("Enemigos: " + std::to_string(enemigos)).c_str());
}

void galaxong::dibujar_botones() {
         // Da tiempo a renderizar
        Espera(20);
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    RectanguloRedondeado(botonPausar.xIzq, botonPausar.yArr, botonPausar.xDer, botonPausar.yAba, 10);
    RectanguloRedondeado(botonReiniciar.xIzq, botonReiniciar.yArr, botonReiniciar.xDer, botonReiniciar.yAba, 10);
    RectanguloRedondeado(botonSalir.xIzq, botonSalir.yArr, botonSalir.xDer, botonSalir.yAba, 10);

    TFormato("Times New Roman", 27, 0, FT_NEGRITA, CL_BLANCO);
    TMostrar(850, 307, 125, 45, botonPausar.texto);
    TMostrar(840, 375, 120, 35, botonReiniciar.texto);
    TMostrar(860, 445, 120, 35, botonSalir.texto);
         // Da tiempo a renderizar
        Espera(90);
}

void galaxong::pausar() {
    if (pausado) {
        // Si el juego ya est� pausado, pregunta si desea reanudar
        if (Pregunta("�Quieres reanudar el juego?")) {
            pausado = false;  // Reanuda el juego
            Mensaje("Juego reanudado");
        }
    } else {
        // Si el juego no est� pausado, lo pausa
        pausado = true;
        Mensaje("Juego pausado");
    }
}

void galaxong::manejar_eventos(int xMouse, int yMouse, bool clicIzq, nave& nav, std::vector<bicho>& _bichos ) {
    // Detecta si el mouse est� dentro de un bot�n y si se ha hecho clic
    if (clicIzq) {
        // Pausar
        if (xMouse >= botonPausar.xIzq && xMouse <= botonPausar.xDer &&
            yMouse >= botonPausar.yArr && yMouse <= botonPausar.yAba) {
            pausar();
            return;
        }
        // Reiniciar
        if (xMouse >= botonReiniciar.xIzq && xMouse <= botonReiniciar.xDer &&
            yMouse >= botonReiniciar.yArr && yMouse <= botonReiniciar.yAba) {
            if (Pregunta("�Quieres reiniciar el juego?")) {
                reiniciar();
                return;
            }
            return;
        }
        // Salir
        if (xMouse >= botonSalir.xIzq && xMouse <= botonSalir.xDer &&
            yMouse >= botonSalir.yArr && yMouse <= botonSalir.yAba) {
            if (Pregunta("�Quieres salir del juego?")) {
                VCierra();  // Cierra la ventana
            }
        }
        //Disparo
        nav.disparar(5, borde_campo_cl, x_campo, y_campo, radio_campo, _bichos, puntos, disparos);
    }
}

void galaxong::reiniciar() {
    x = 400;  // Posici�n inicial de la nave (en el centro del campo)
    y = 250;
    angulo = 0;  // Restablece el �ngulo
    puntos = 0;  // Reinicia los puntos

}

bool galaxong::esta_pausado() const {
    return pausado;
}

void galaxong::actualizar() {
    if (esta_pausado()) {
        return;
    }
}
