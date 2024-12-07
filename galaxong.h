#include "graphito.h"

using namespace graphito;

class galaxong {
private:
    int x, y, angulo; // coordenadas de la nave y ángulo de apuntado hacia el centro
    int puntos;                // Puntuación actual
    int disparos;              // Número de disparos realizados
    int enemigos;              // Número de enemigos
    int cant_bloques; // Cantidad de bloques a dibujar en el círculo
    int x_campo, y_campo, radio_campo; // coordenadas y radio del campo
    int borde_campo_cl; // color del borde del campo

    struct Boton {
        int xIzq, yArr, xDer, yAba; // Coordenadas del botón
        const char* texto;          // Texto del botón

        Boton(int _xIzq, int _yArr, int _xDer, int _yAba, const char* _texto)
            : xIzq(_xIzq), yArr(_yArr), xDer(_xDer), yAba(_yAba), texto(_texto) {}
    };

    Boton botonPausar;     // Botón "Pausar"
    Boton botonReiniciar;  // Botón "Reiniciar"
    Boton botonSalir;      // Botón "Salir"
    bool pausado;          // Estado de pausa

public:
    // Constructor
     galaxong(int _x = 400, int _y = 250, int _angulo = 0,
             int _x_campo = 400, int _y_campo = 250,
             int _radio_campo = 200, int _borde_campo_cl = CL_BLANCO);

    void nuevo_juego();                               // Reinicia el juego
    void rotar(int deltaAngulo);                      // Método para rotar la nave
    void actualizar_puntuacion(int puntos_obtenidos); // Actualiza la puntuación
    void dibujar_puntuacion();                        // Dibuja la puntuación en pantalla
    void dibujar_botones();                           // Dibuja los botones
    void manejar_eventos(int xMouse, int yMouse, bool clicIzq); // Maneja clics en botones
    bool esta_pausado() const;                        // Verifica si el juego está pausado
    void pausar();                                    // Pausa el juego
    void reiniciar();                                 // Reinicia la nave
    void actualizar();                                // actualiza los botones
};
