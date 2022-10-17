//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_UNJUGADOR_H
#define DIEZ_MIL_UNJUGADOR_H

#endif //DIEZ_MIL_UNJUGADOR_H



int unJugador(int &condicionCls, char jugadores[][35], int cantidadPJ, int puntuacion[], int &rondas) {
    rlutil::cls();
    condicionCls = 1;
    int puntosXRonda;
    int puntosAux=0;
    int dados[6];
    int mostrarCaso4;
    int jugada;
    int lanzamientos;
    do {
        lanzamientos=0;
        rondas++;
        pantallaTurno(rondas, jugadores, cantidadPJ, puntuacion);
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
        std::cout << "JUEGA " << strupr(jugadores[0]);
        //puntaje
        rlutil::locate(10, 9);
        std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
        //puntaje x ronda
        rlutil::locate(10, 10);
        std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
        //lanzamientos
        rlutil::locate(10, 12);
        std::cout << char(4) << " " << "LANZAMIENTOS: " << lanzamientos;

        ///TIRADA || JUEGO
        bool band = true;

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
                            std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";

                            rlutil::msleep(750);
                            rlutil::locate(10, 10);
                            std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";

                            if (puntosXRonda==0) {
                                rlutil::locate(10, 10);
                                std::cout << char(4) << " " << "                     " << puntosAux << "       ";
                                puntosAux=0;
                                rlutil::locate(10, 10);
                                std::cout << char(4) << " " << "PUNTAJE DE LA RONDA: " << puntosAux << " PUNTOS";
                                label("             ", 19, 22);
                                label("                ", 19, 24);
                                rlutil::msleep(500);
                                label("PULSA UNA TECLA PARA CONTINUAR", 11, 22);
                                rlutil::anykey();
                                band=false;
                            }
                            if (puntosXRonda==10000){
                                puntuacion[0]=10000;
                                label("ganaste la ronda con 10k", 11, 22);
                                rlutil::anykey();
                                band = false;
                            }
                            break;
                        case 24:
                            if (puntuacion[0]+puntosAux>10000){
                                label("TE PASASTE DE LOS 10.000", 11, 22);
                                rlutil::anykey();
                            } else {
                                puntuacion[0]+=puntosAux;
                            }
                            puntosAux=0;
                            rlutil::msleep(500);
                            limpiarJuego();
                            rlutil::locate(10, 9);
                            std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
                            label("PULSA UNA TECLA PARA CONTINUAR", 11, 22);
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

        if (puntuacion[0]==10000) {
            ///ESTO DEBERIA SER UNA FUNCION
            rlutil::cls();
            rlutil::locate(8, 4);
            std::cout << "FIN DEL JUEGO";
            rlutil::anykey();
            return 0;
        }
    } while (rondas!=10);
    finalRondas();
    return 0;
}