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
        rlutil::locate(13, 9);
        std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
        //lanzamientos
        rlutil::locate(13, 10);
        std::cout << char(4) << " " << "LANZAMIENTOS: " << lanzamientos;

        ///TIRADA || JUEGO
        bool band = true;

        int posX = 13;
        int posY = 18;

        do {
            label("TIRAR", 14, 18);
            label("GUARDAR PUNTOS", 14, 20);

            labelInt(175, posX, posY);

            int key = rlutil::getkey();
            //up    14
            //down  15
            //enter 1

            switch (key) {
                case 14:
                    punteroArriba(posX, posY, 175, 18, 2);
                    break;
                case 15:
                    punteroAbajo(posX, posY, 175, 20, 2);
                    break;
                case 1:
                    switch (posY) {
                        case 18:
                            limpiarJuego();
                            mezclar();
                            guardarDados(dados, 6);
                            mostrarDados(dados, 6);
                            lanzamientos++;
                            jugada = identificarJugada(dados, 6, puntosXRonda, mostrarCaso4);
                            mostrarJugada(jugada, mostrarCaso4);
                            puntuacion[0]+=puntosXRonda;
                            mostrarSumaPuntaje(puntosXRonda);
                            rlutil::locate(13, 10);
                            std::cout << char(4) << " " << "LANZAMIENTOS: " << lanzamientos;
                            rlutil::msleep(1000);
                            rlutil::locate(13, 9);
                            std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
                            if (puntosXRonda==0) {
                                puntuacion[0]=0;
                                rlutil::locate(13, 9);
                                std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";
                                rlutil::msleep(500);
                                label("PULSA UNA TECLA PARA CONTINUAR", 11, 22);
                                rlutil::anykey();
                                band=false;
                            }
                            break;
                        case 20:
                            rlutil::msleep(500);
                            limpiarJuego();
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
            rlutil::cls();
            rlutil::locate(8, 4);
            std::cout << "FIN DEL JUEGO";
            rlutil::anykey();
            return 0;
        }
    } while (rondas!=10);
    return 0;
}