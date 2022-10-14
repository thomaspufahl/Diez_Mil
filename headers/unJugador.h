//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_UNJUGADOR_H
#define DIEZ_MIL_UNJUGADOR_H

#endif //DIEZ_MIL_UNJUGADOR_H



int unJugador(int &condicionCls, char jugadores[][35], int puntuacion[], int &rondas) {
    rlutil::cls();
    condicionCls = 1;
    do {
        rondas++;
        std::cout << "funka";
        if (rondas==3) {
            rlutil::anykey();
            return 0;
        }
    } while (rondas!=0);
}