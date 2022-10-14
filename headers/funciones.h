//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONES_H
#define DIEZ_MIL_FUNCIONES_H

#endif //DIEZ_MIL_FUNCIONES_H


void endl() {
    std::cout << std::endl;
}

void label(char* texto, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << texto;
}
void labelInt(int caracter, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << (char)caracter;
}

//puntero
void punteroArriba (int &posX, int &posY, int caracter, int limite, int salto){
    label(" ", posX, posY);
    if (posY==limite) {
        posY=limite;
    } else {posY-=salto;}
    labelInt((char)caracter, posX, posY);
}
void punteroAbajo(int &posX, int &posY, int caracter, int limite, int salto) {
    label(" ", posX, posY);
    if (posY==limite) {
        posY=limite;
    } else {posY+=salto;}
    labelInt((char)caracter, posX, posY);
}

//pedir nombres de jugadores

void petNombre(char jugador[][35], int cantidad) {
    rlutil::showcursor();
    rlutil::cls();
    for (int i = 0; i < cantidad; ++i) {
        if (i==1) {
            label("JUGADOR 2: ", 2, 4);
        } else {label("JUGADOR 1: ", 2, 2);}
        std::cin >> jugador[i];
    }
    rlutil::hidecursor();
}

//vectores
void vecZero (int vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        vec[i]=0;
    }
}
