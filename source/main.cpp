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
    bool band = true;
    bool cGeneralHG = false;
    int ganadorHG;
    int ganadorHGMin;
    int rondasMin;
    int tam=1;
    int *punteroTam = &tam;
    char jugadorMin2[tam];
    /*
    int tam2=1;
    int *punteroTam2 = &tam2;
    char apellidoMin2[tam2];
    */

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
                        ganadorHG = unJugador(condicionCls, jugadores, apellidos, 1, puntaje, ronda);
                        if (band) {
                            ganadorHGMin = ganadorHG;

                            int i = 0;
                            while (jugadores[ganadorHGMin][i]!=0) {
                                i++;
                            }
                            char jugadorMin[i+1];
                            for (int j = 0; j < i+1; ++j) {
                                jugadorMin[j] = jugadores[ganadorHGMin][j];
                            }
                            *punteroTam = i;
                            strcpy(jugadorMin2, jugadorMin);

                            rondasMin = ronda;
                            cGeneralHG = true;
                            band = false;
                        } else if (ronda < rondasMin) {
                            ganadorHGMin = ganadorHG;

                            int i = 0;
                            while (jugadores[ganadorHGMin][i]!=0) {
                                i++;
                            }
                            char jugadorMin[i+1];
                            for (int j = 0; j < i+1; ++j) {
                                jugadorMin[j] = jugadores[ganadorHGMin][j];
                            }
                            *punteroTam = i;

                            strcpy(jugadorMin2, jugadorMin);
                            rondasMin = ronda;
                        }
                        break;
                    case 7:
                        petNombre(jugadores, apellidos, 2);
                        dosJugadores(condicionCls, jugadores, apellidos, 2, puntaje, ronda);
                        band = true;
                        break;
                    case 9:
                        //mostrarPuntuacion(condicionCls, jugadorHG, apellidoHG, rondasHG, cGeneralHG);
                        rlutil::cls();
                        recuadroJuego();
                        condicionCls = 1;

                        label("PUNTAJE MAS ALTO", 55, 6);
                        label("NOMBRE: ", 44, 9);
                        label("APELLIDO: ", 44, 11);
                        label("RONDAS:", 44, 13);

                        if (cGeneralHG) {
                            int valorX = 55;
                            rlutil::locate(valorX, 9);
                            for (int i = 0; i < tam; ++i) {
                                std::cout << jugadorMin2[i];
                            }
                            rlutil::locate(55, 11);
                            //std::cout << apellidoMin;

                            rlutil::locate(55, 13);
                            std::cout << rondasMin;
                        }
                        rlutil::anykey();

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