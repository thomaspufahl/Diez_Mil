//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_DOSJUGADORES_H
#define DIEZ_MIL_DOSJUGADORES_H

#endif //DIEZ_MIL_DOSJUGADORES_H
//devcomm
int dosJugadores(int &condicionCls, char jugadores[][35], char apellidos[][35], int cantidadPJ, int puntuacion[], int &rondas) {
    rlutil::cls();
    condicionCls = 1;
    int puntosXRonda;
    int puntosAux=0;
    int dados[6];
    int mostrarCaso4;
    int jugada;
    int lanzamientos;
    int ganador;
    bool band;
    int TURNO;
    int cTurno;
    do {
        TURNO = 0;
        cTurno=0;
        rondas++;

        do {
            lanzamientos=0;
            pantallaTurno(rondas, jugadores, cantidadPJ, puntuacion, TURNO);
            rlutil::cls();

            ///ESTILOS
            //CABECERA
            recuadroJuego();
            //numero de ronda
            rlutil::locate(56, 4);
            std::cout << "RONDA N" << char(248) << " " << rondas;
            lineaHorizontal(6, 196);

            //CUERPO
            //jugador
            lineaVertical(46, 179);
            rlutil::locate(21, 7);
            std::cout << "JUEGA " << strupr(jugadores[TURNO]);
            //puntaje
            rlutil::locate(10, 9);
            std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[TURNO] << " PUNTOS";
            //puntaje x ronda
            rlutil::locate(10, 10);
            std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
            //lanzamientos
            rlutil::locate(10, 12);
            std::cout << char(4) << " " << "LANZAMIENTOS: " << lanzamientos;

            ///TIRADA || JUEGO
            band = true;

            int posX = 19;
            int posY = 22;

            do {

                label("TIRAR DADOS", 21, 22);
                label("GUARDAR PUNTOS", 21, 24);

                labelInt(175, posX, posY);

                int key = rlutil::getkey();
                //up    14
                //down  15
                //enter 1

                switch (key) {
                    case 14:
                        punteroArriba(posX, posY, 175, 22, 2);
                        break;
                    case 15:
                        punteroAbajo(posX, posY, 175, 24, 2);
                        break;
                    case 1:
                        switch (posY) {
                            case 22:
                                limpiarJuego();
                                mezclar();
                                guardarDados(dados, 6);
                                mostrarDados(dados, 6);
                                lanzamientos++;
                                jugada = identificarJugada(dados, 6, puntosXRonda, mostrarCaso4);
                                mostrarJugada(jugada, mostrarCaso4);
                                puntosAux+=puntosXRonda;
                                mostrarSumaPuntaje(puntosXRonda);

                                rlutil::locate(10, 12);
                                std::cout << char(4) << " " << "LANZAMIENTOS N" << char(248) << " " << lanzamientos;

                                rlutil::locate(10, 9);
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[TURNO] << " PUNTOS";

                                if (jugada!=7) {
                                    rlutil::msleep(750);
                                    rlutil::locate(10, 10);
                                    std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
                                }

                                if (jugada==0) {
                                    rlutil::locate(10, 10);
                                    std::cout << char(4) << " " << "                     " << puntosAux << "       ";
                                    puntosAux=0;
                                    rlutil::locate(10, 10);
                                    std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
                                    label("             ", 19, 22);
                                    label("                ", 19, 24);
                                    rlutil::msleep(500);
                                    label("-PULSA UNA TECLA PARA CONTINUAR", 12, 22);
                                    rlutil::anykey();
                                    band=false;
                                }
                                if (jugada==7){
                                    //significa que saque un sexteto
                                    puntuacion[TURNO]=puntosXRonda;
                                    label("-PULSA UNA TECLA PARA CONTINUAR", 12, 22);
                                    rlutil::anykey();
                                    band = false;
                                }
                                break;
                            case 24:
                                if (puntuacion[TURNO]+puntosAux>10000){
                                    limpiarJuego();
                                    label("TE PASASTE DE LOS 10.000", 16, 22);
                                    rlutil::msleep(750);
                                } else {
                                    puntuacion[TURNO]+=puntosAux;
                                }
                                puntosAux=0;
                                rlutil::msleep(250);
                                limpiarJuego();
                                rlutil::locate(10, 9);
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[TURNO] << " PUNTOS";
                                label("-PULSA UNA TECLA PARA CONTINUAR", 12, 22);
                                rlutil::anykey();
                                band=false;
                                break;
                            default:
                                break;
                        }
                    default:
                        break;
                }
            } while (band);

            TURNO = 1;
            cTurno++;
            rlutil::cls();

        } while (cTurno!=2);


        ///PANTALLAS DE FIN DE JUEGO
        if (jugada==7) {
            //pantalla final de sexteto
            ganador = pantallaFinal("GANADOR POR COMBINACION GANADORA: SEXTETO", 40, 10, jugadores, apellidos, 2, puntuacion, rondas, false, jugada);
            rlutil::anykey();
            return ganador;
        }
        if (puntuacion[0]==10000 || puntuacion[1]==10000) {
            //pantalla final de ganador basico
            ganador = pantallaFinal("FINALIZACION POR LLEGAR A 10.000 PUNTOS", 40, 10, jugadores, apellidos, 2, puntuacion, rondas, false, jugada);
            rlutil::anykey();
            return ganador;
        }
    } while (rondas!=10);
    //pantalla final de ganador por puntos
    rondas++;
    ganador = pantallaFinal("FINALIZACION DE RONDAS, GANADOR POR PUNTAJE", 40, 10, jugadores, apellidos, 2, puntuacion, rondas,false, jugada);
    rlutil::anykey();
    return ganador;
}