//
// Created by Thomas Pufahl on 19/10/2022.
//

#ifndef DIEZ_MIL_HIGHSCORE_H
#define DIEZ_MIL_HIGHSCORE_H


#endif //DIEZ_MIL_HIGHSCORE_H

void mostrarPuntuacion(int &condicionCls, bool &bVisualHg, int &tam, char* jugadorMinCpy, int &tam2, char* apellidoMinCpy, int &rondasMin) {
    rlutil::cls();
    recuadroJuego();
    condicionCls = 1;

    label("PUNTAJE MAS ALTO", 55, 6);
    label("NOMBRE: ", 44, 9);
    label("APELLIDO: ", 44, 11);
    label("RONDAS:", 44, 13);

    if (bVisualHg) {
        int valorX = 55;
        //nombre
        rlutil::locate(valorX, 9);
        for (int i = 0; i < tam; ++i) {
            std::cout << jugadorMinCpy[i];
        }
        //apellido
        rlutil::locate(valorX, 11);
        for (int i = 0; i < tam2; ++i) {
            std::cout << apellidoMinCpy[i];
        }

        rlutil::locate(55, 13);
        std::cout << rondasMin;
    }
    rlutil::anykey();

}