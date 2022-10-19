//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_DOSJUGADORES_H
#define DIEZ_MIL_DOSJUGADORES_H

#endif //DIEZ_MIL_DOSJUGADORES_H

int dosJugadores(int &condicionCls, char jugadores[][35], char apellidos[][35], int cantidadPJ, int puntuacion[], int &rondas) {
    rlutil::cls();
    condicionCls = 1;
    int puntosXRonda;
    int puntosAux;
    int dados[6];
    int mostrarCaso4;
    int jugada;
    int lanzamientos=0;
    bool bCambioTurno=true;
    int cCambioTurno;

    do {
        if (rondas!=0) {bCambioTurno = !bCambioTurno;}
        cCambioTurno=0;
        rondas++;
        pantallaTurno(rondas, jugadores, cantidadPJ, puntuacion);
        rlutil::cls();

        ///TIRADA || JUEGO
        bool band = true;
        bool band2 = true;

        int posX = 19;
        int posY = 22;

        do {
            if (!bCambioTurno && band2) {
                lanzamientos=0;
                band2 = false;
            }
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
            if (bCambioTurno) {
                std::cout << "JUEGA " << strupr(jugadores[0]);
            } else {
                std::cout << "JUEGA " << strupr(jugadores[1]);
            }
            //puntaje
            rlutil::locate(10, 9);
            if (bCambioTurno) {
                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
            } else {
                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[1] << " PUNTOS";
            }

            //puntaje x ronda
            rlutil::locate(10, 10);
            puntosAux=0;
            std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
            //lanzamientos
            rlutil::locate(10, 12);
            std::cout << char(4) << " " << "LANZAMIENTO N" << char(248) << " " << lanzamientos;


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
                            std::cout << char(4) << " " << "LANZAMIENTO N" << char(248) << " " << lanzamientos;

                            rlutil::locate(21, 7);

                            rlutil::locate(10, 9);
                            if (bCambioTurno) {
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
                            } else {
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[1] << " PUNTOS";
                            }

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

                                bCambioTurno = !bCambioTurno;
                                cCambioTurno++;
                                if (cCambioTurno==2) {
                                    band = false;
                                } else if (cCambioTurno==1) {
                                    rlutil::cls();
                                }
                            }
                            if (jugada==7){
                                //significa que saque un sexteto
                                label("-PULSA UNA TECLA PARA CONTINUAR", 12, 22);
                                rlutil::anykey();
                                if (bCambioTurno) {
                                    puntuacion[0]=puntosXRonda;
                                } else {
                                    puntuacion[1]=puntosXRonda;
                                }
                                bCambioTurno = !bCambioTurno;
                                cCambioTurno++;
                                if (cCambioTurno==2) {
                                    band = false;
                                } else if (cCambioTurno==1) {
                                    rlutil::cls();
                                }
                            }
                            break;
                        case 24:
                            if (bCambioTurno) {
                                if (puntuacion[0]+puntosAux>10000){
                                    label("TE PASASTE DE LOS 10.000", 11, 22);
                                    rlutil::anykey();
                                } else {
                                    puntuacion[0]+=puntosAux;
                                }
                            } else {
                                if (puntuacion[1]+puntosAux>10000){
                                    label("TE PASASTE DE LOS 10.000", 11, 22);
                                    rlutil::anykey();
                                } else {
                                    puntuacion[1]+=puntosAux;
                                }
                            }
                            rlutil::msleep(500);
                            limpiarJuego();
                            rlutil::locate(10, 9);
                            if (bCambioTurno) {
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
                            } else {
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[1] << " PUNTOS";
                            }
                            label("-PULSA UNA TECLA PARA CONTINUAR", 12, 22);
                            rlutil::anykey();

                            bCambioTurno = !bCambioTurno;
                            cCambioTurno++;
                            if (cCambioTurno==2) {
                                band=false;
                            }
                            rlutil::cls();
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        } while (band);

        ///PANTALLAS DE FIN DE JUEGO
        if (jugada==7) {
            //pantalla final de sexteto
            if (cCambioTurno==2) {
                pantallaFinal("GANADOR POR COMBINACION GANADORA: SEXTETO", 40, 10, jugadores, apellidos, 2, puntuacion, rondas, false, jugada);
                rlutil::anykey();
                return 0;
            }
        }
        if (puntuacion[0]==10000) {
            //pantalla final de ganador basico
            if (cCambioTurno==2) {
                pantallaFinal("FINALIZACION POR LLEGAR A 10.000 PUNTOS", 52, 10, jugadores, apellidos, 2, puntuacion, rondas, false, jugada);
                rlutil::anykey();
                return 0;
            }
        }
    } while (rondas!=10);
    //pantalla final de ganador por puntos
    rondas++;
    pantallaFinal("FINALIZACION DE RONDAS, GANADOR POR PUNTAJE", 40, 10, jugadores, apellidos, 2, puntuacion, rondas, false, jugada);
    rlutil::anykey();
    return 0;
}
