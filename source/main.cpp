#include "../headers/rlutil.h"
#include "../headers/funcionesEstilo.h"
#include "../headers/funciones.h"
#include "../headers/algoritmoPuntos.h"
#include "../headers/dosJugadores.h"
#include "../headers/unJugador.h"
#include "../headers/highscore.h"


int main() {
    //PARA PUNTERO
    int posY = 5;
    int posX = 8;
    // »
    int caracter = 175;

    //PARA MOV. PUNTERO
    int posY_Inicial = 5;
    int posY_Final = 11;
    int salto = 2;

    //BANDERA DE CLS
    //evita hacer cls siempre que cambie de opcion
    int condicionCls=0;

    //DATOS DE JUGADORES
    char jugadores[2][35];
    char apellidos[2][35];
    int puntaje[2];
    int ronda;
    //inicializa el puntaje en 0
    vecZero(puntaje, 2);

    //ESTILO DE LA CONSOLA
    rlutil::setBackgroundColor(rlutil::LIGHTBLUE);
    rlutil::setColor(rlutil::WHITE);
    rlutil::cls();
    bordeMenu();

    //HG
    //generales
    bool bandHg = true;
    bool bVisualHg = false;
    int ganadorHg;
    int ganadorHgMin;
    int rondasMin;
    //nombre jugador
    int tam=1;
    int *punteroTam = &tam;
    char jugadorMinCpy[tam];
    //apellido jugador
    int tam2=1;
    int *punteroTam2 = &tam2;
    char apellidoMinCpy[tam2];

    while (true) {
        rlutil::hidecursor();

        antiCls(condicionCls);
        ronda=0;
        vecZero(puntaje, 2);

        bordeMenu();
        label("UN JUGADOR", 10, 5);
        label("DOS JUGADORES", 10, 7);
        label("PUNTUACION MAS ALTA", 10, 9);
        label("SALIR", 10, 11);

        labelInt(caracter, posX, posY);

        int key = rlutil::getkey();
        //up    14
        //down  15
        //enter 1

        switch (key) {
            case 14:
                punteroArriba(posX, posY, caracter, posY_Inicial, salto);
                break;
            case 15:
                punteroAbajo(posX, posY, caracter, posY_Final, salto);
                break;
            case 1:
                switch (posY) {
                    case 5:
                        petNombre(jugadores, apellidos, 1);
                        ganadorHg = unJugador(condicionCls, jugadores, apellidos, 1, puntaje, ronda);
                        cargarHG(bandHg, ganadorHgMin, ganadorHg, jugadores, punteroTam, jugadorMinCpy, rondasMin, ronda, bVisualHg, punteroTam2, apellidoMinCpy, apellidos);
                        break;
                    case 7:
                        petNombre(jugadores, apellidos, 2);
                        ganadorHg = dosJugadores(condicionCls, jugadores, apellidos, 2, puntaje, ronda);
                        cargarHG(bandHg, ganadorHgMin, ganadorHg, jugadores, punteroTam, jugadorMinCpy, rondasMin, ronda, bVisualHg, punteroTam2, apellidoMinCpy, apellidos);
                        break;
                    case 9:
                        mostrarPuntuacion(condicionCls, bVisualHg, tam, jugadorMinCpy, tam2, apellidoMinCpy, rondasMin);
                        break;
                    case 11:
                        //SALIR
                        return 0;
                    default:
                        break;
                }
            default:
                break;
        }
    }
}