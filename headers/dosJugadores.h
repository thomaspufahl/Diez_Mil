//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_DOSJUGADORES_H
#define DIEZ_MIL_DOSJUGADORES_H

#endif //DIEZ_MIL_DOSJUGADORES_H

void dosJugadores(int &condicionCls, char jugadores[][35], int puntuacion[]) {
    rlutil::cls();
    condicionCls = 1;

    label("DOS JUGADORES", 1, 1);
    rlutil::locate(1, 2);
    std::cout << jugadores[0];

    rlutil::locate(1, 3);
    std::cout << "puntaje j1: ";
    rlutil::locate(1, 4);
    std::cout << puntuacion[0];

    rlutil::locate(1, 6);
    std::cout << jugadores[1];


    rlutil::locate(1, 7);
    std::cout << "puntaje j2: ";
    rlutil::locate(1, 8);
    std::cout << puntuacion[1];

    rlutil::anykey();
}