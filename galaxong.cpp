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
void galaxong::actualizar_disparos(int puntos_obtenidos) {
    puntos += puntos_obtenidos; // Incrementa la puntuaci�n
}
void galaxong::actualizar_enemigos(int puntos_obtenidos) {
    puntos += puntos_obtenidos; // Incrementa la puntuaci�n
}

void galaxong::dibujar_puntuacion() {
    // Limpiar el área de texto antes de dibujar los nuevos valores
    TFormato("Times New Roman", 32,0 ,FT_NEGRITA, CL_NEGRO);  // Fondo blanco para limpiar
    TMostrar(810, 80, 360, 50, "Puntos: ");  // Borrar texto previo
    TMostrar(810, 140, 360, 50, "Disparos: ");
    TMostrar(810, 200, 360, 50, "Enemigos: ");

    // Mostrar solo los valores mayores que 0
    if (puntos > 0) {
        TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO);  // Color blanco para el texto
        TMostrar(940, 80, 360, 50, std::to_string(puntos).c_str()); // Puntos
    }

    if (disparos > 0) {
        TFormato("Times New Roman", 32, 0, FT_NEGRITA, CL_NEGRO);  // Color blanco para el texto
        TMostrar(940, 140, 360, 50, std::to_string(disparos).c_str()); // Disparos
    }

    if (enemigos > 0) {
        TFormato("Times New Roman", 32, 0,FT_NEGRITA, CL_NEGRO);  // Color blanco para el texto
        TMostrar(940, 200, 360, 50, std::to_string(enemigos).c_str()); // Enemigos
    }
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
        if (Pregunta("Quieres reanudar el juego?")) {
            pausado = false;  // Reanuda el juego
            Mensaje("Juego reanudado");
        }
    } else {
        pausado = true;
        Mensaje("Juego pausado");
    }
}

void galaxong::manejar_eventos(int xMouse, int yMouse, bool clicIzq, nave& nav, std::vector<bicho>& _bichos) {
    // Si el juego está pausado, permitir que los botones sean interactivos, pero no otros eventos
    if (esta_pausado()) {
        // Detecta si el mouse está dentro de un botón y si se ha hecho clic
        if (clicIzq) {
            // Pausar (reanudando)
            if (xMouse >= botonPausar.xIzq && xMouse <= botonPausar.xDer &&
                yMouse >= botonPausar.yArr && yMouse <= botonPausar.yAba) {
                pausar();
            }
            // Reiniciar
            if (xMouse >= botonReiniciar.xIzq && xMouse <= botonReiniciar.xDer &&
                yMouse >= botonReiniciar.yArr && yMouse <= botonReiniciar.yAba) {
                if (Pregunta("Quieres reiniciar el juego?")) {
                    reiniciar_juego();
                }
            }
            // Salir
            if (xMouse >= botonSalir.xIzq && xMouse <= botonSalir.xDer &&
                yMouse >= botonSalir.yArr && yMouse <= botonSalir.yAba) {
                if (Pregunta("Quieres salir del juego?")) {
                    VCierra();  // Cierra la ventana
                }
            }
        }
        return;  // Si está pausado, no seguir procesando otras interacciones
    }

    // Si no está pausado, permitir que las demás interacciones continúen normalmente
    if (clicIzq) {
        // Pausar
        if (xMouse >= botonPausar.xIzq && xMouse <= botonPausar.xDer &&
            yMouse >= botonPausar.yArr && yMouse <= botonPausar.yAba) {
            pausar();
        }
        // Reiniciar
        if (xMouse >= botonReiniciar.xIzq && xMouse <= botonReiniciar.xDer &&
            yMouse >= botonReiniciar.yArr && yMouse <= botonReiniciar.yAba) {
            if (Pregunta("Quieres reiniciar el juego?")) {
                reiniciar_juego();
            }
        }
        // Salir
        if (xMouse >= botonSalir.xIzq && xMouse <= botonSalir.xDer &&
            yMouse >= botonSalir.yArr && yMouse <= botonSalir.yAba) {
            if (Pregunta("Quieres salir del juego?")) {
                VCierra();  // Cierra la ventana
            }
        }

        // Disparo (solo se permite si el juego no está pausado)
        nav.disparar(5, borde_campo_cl, x_campo, y_campo, radio_campo, _bichos, puntos, disparos, enemigos);
    }
}

void galaxong::reiniciar_juego() {
    main();    // Llama al programa desde cero
    Mensaje("El juego se ha reiniciado correctamente"); // Mensaje informativo
}

bool galaxong::esta_pausado() const {
    return pausado;
}

void galaxong::actualizar() {
    if (esta_pausado()) {
        return;
    }
}

void galaxong::disparar(nave& nav, std::vector<bicho>& _bichos) {
    if (!pausado) { // Solo dispara si el juego no está pausado
        nav.disparar(5, borde_campo_cl, x_campo, y_campo, radio_campo, _bichos, puntos, disparos, enemigos);
        return;
    }
}
