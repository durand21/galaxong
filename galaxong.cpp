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
    puntos += puntos_obtenidos; // Incrementa la puntuación
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
        Espera(90);
    FormatoRelleno(ER_SOLIDO, CL_NEGRO);
    RectanguloRedondeado(botonPausar.xIzq, botonPausar.yArr, botonPausar.xDer, botonPausar.yAba, 10);
    RectanguloRedondeado(botonReiniciar.xIzq, botonReiniciar.yArr, botonReiniciar.xDer, botonReiniciar.yAba, 10);
    RectanguloRedondeado(botonSalir.xIzq, botonSalir.yArr, botonSalir.xDer, botonSalir.yAba, 10);

    TFormato("Times New Roman", 27, 0, FT_NEGRITA, CL_BLANCO);
    TMostrar(850, 307, 125, 45, botonPausar.texto);
    TMostrar(840, 375, 120, 35, botonReiniciar.texto);
    TMostrar(860, 445, 120, 35, botonSalir.texto);
}
void galaxong::pausar() {
    pausado = !pausado;  // Alterna entre pausado y reanudado
    if (pausado) {
        Mensaje("Juego pausado");
    } else {
        Mensaje("Juego reanudado");
    }
}


void galaxong::manejar_eventos(int xMouse, int yMouse, bool clicIzq) {
    // Detecta si el mouse está dentro de un botón y si se ha hecho clic
    if (clicIzq) {
        // Pausar
        if (xMouse >= botonPausar.xIzq && xMouse <= botonPausar.xDer &&
            yMouse >= botonPausar.yArr && yMouse <= botonPausar.yAba) {
            if (Pregunta("¿Quieres pausar el juego?")) {
                pausar();
            }
        }

        // Reiniciar
        if (xMouse >= botonReiniciar.xIzq && xMouse <= botonReiniciar.xDer &&
            yMouse >= botonReiniciar.yArr && yMouse <= botonReiniciar.yAba) {
            if (Pregunta("¿Quieres reiniciar el juego?")) {
                reiniciar();
            }
        }

        // Salir
        if (xMouse >= botonSalir.xIzq && xMouse <= botonSalir.xDer &&
            yMouse >= botonSalir.yArr && yMouse <= botonSalir.yAba) {
            if (Pregunta("¿Quieres salir del juego?")) {
                VCierra();  // Cierra la ventana
            }
        }
    }
}


void galaxong::reiniciar() {
    x = 400;  // Coordenada inicial X de la nave (centro del círculo)
    y = 250;  // Coordenada inicial Y de la nave (centro del círculo)
    angulo = 0;  // Restablece el ángulo de la nave
    puntos = 0;  // Reinicia los puntos del jugador
    disparos = 0;  // Reinicia la cantidad de disparos
    enemigos = 0;  // Reinicia la cantidad de enemigos

    // También puedes detener cualquier movimiento en curso si es necesario
    pausado = false;  // Asegura que el juego no quede pausado al reiniciar
    Mensaje("El juego ha sido reiniciado");
}


bool galaxong::esta_pausado() const {
    return pausado;
}

void galaxong::actualizar() {
    if (esta_pausado()) {
        // Si el juego está pausado, no se actualiza nada
        return;
    }

}
