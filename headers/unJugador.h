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
    do {
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

        ///ESTILOS CON PROCESAMIENTOS
        //CUERPO

        //Tirada
        //mezclar (animacion de carga)
        label("PRESIONA ESPACIO PARA TIRAR", 14, 15);
        labelInt(16, 11, 15);
        labelInt(17, 43, 15);
        int keyMezcla = rlutil::getkey();
        //espacio = 32
        if (keyMezcla==32) {
            label("                                 ", 11, 15);
            mezclar();
        } else {
            label("                                 ", 11, 15);
        }

        //"tirar" y guardar
        guardarDados(dados, 6);

        //mostrar tirada
        mostrarDados(dados, 6);

        //identifico jugada || algoritmo
        int jugada = identificarJugada(dados, 6, puntosXRonda, mostrarCaso4);

        //mostrar Jugada
        mostrarJugada(jugada, mostrarCaso4);

        //puntos
        puntuacion[0]+=puntosXRonda;

        //muestro puntaje a sumar
        mostrarSumaPuntaje(puntosXRonda);

        //update de label con el puntaje
        rlutil::msleep(1000);
        rlutil::locate(13, 9);
        std::cout << char(4) << " " << "PUNTAJE TOTAL: " << puntuacion[0] << " PUNTOS";

        rlutil::msleep(500);
        label("PULSA UNA TECLA PARA CONTINUAR", 11, 22);
        rlutil::anykey();
        if (puntuacion[0]==10000) {
            rlutil::cls();
            rlutil::locate(8, 4);
            std::cout << "FIN DEL JUEGO";
            rlutil::anykey();
            return 0;
        }
    } while (rondas!=10); //debe ser 10
    return 0;
}