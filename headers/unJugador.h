//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_UNJUGADOR_H
#define DIEZ_MIL_UNJUGADOR_H

#endif //DIEZ_MIL_UNJUGADOR_H



void unJugador(int &condicionCls, char jugadores[][35], int puntuacion[]) {
    rlutil::cls();
    condicionCls = 1;

    label("UN JUGADOR", 1, 1);
    rlutil::locate(1, 2);
    std::cout << jugadores[0];

    rlutil::locate(1, 3);
    std::cout << "puntaje: ";
    rlutil::locate(1, 4);
    std::cout << puntuacion[0];



    rlutil::anykey();
}