//
// Created by Thomas Pufahl on 19/10/2022.
//

#ifndef DIEZ_MIL_HIGHSCORE_H
#define DIEZ_MIL_HIGHSCORE_H


#endif //DIEZ_MIL_HIGHSCORE_H

void mostrarPuntuacion(int &condicionCls, char* &jugador, char* &apellido, int &ronda, bool &cGeneral) {
    rlutil::cls();
    recuadroJuego();
    condicionCls = 1;
    label("PUNTAJE MAS ALTO", 55, 6);
    label("NOMBRE: ", 47, 9);
    label("APELLIDO: ", 47, 11);
    label("RONDAS:", 47, 13);
    if (cGeneral) {
        rlutil::locate(55, 9);
        std::cout << jugador;
        rlutil::locate(55, 11);
        std::cout << apellido;
        rlutil::locate(55, 13);
        std::cout << ronda;
    }
    rlutil::anykey();
}