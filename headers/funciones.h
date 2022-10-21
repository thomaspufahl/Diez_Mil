//
// Created by thoma on 14/10/2022.
//

#include <ctime>


#ifndef DIEZ_MIL_FUNCIONES_H
#define DIEZ_MIL_FUNCIONES_H

#endif //DIEZ_MIL_FUNCIONES_H


///1. PUNTERO
void punteroArriba (int &posX, int &posY, int caracter, int limite, int salto);
void punteroAbajo(int &posX, int &posY, int caracter, int limite, int salto);

///2. PETICIONES
void petNombre(char jugador[][35], char apellidos[][35], int cantidad);

///3. PROCESAMIENTOS
void vecZero (int vec[], int tam);
void antiCls(int &condicionCls);
void guardarDados(int vec[], int tam);
void pasoDatosHG(int puntuacion[], int jugada, int rondas, int max, char jugadores[][35], char apellidos[][35], bool &cGeneralHG, char* &jugadorHG, char* &apellidoHG, int &rondasHG);


/// 1
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
//-----------

/// 2
void petNombre(char jugador[][35], char apellidos[][35], int cantidad) {
    rlutil::cls();
    bordePetJugador();
    for (int i = 0; i < cantidad; ++i) {
        rlutil::cls();
        bordePetJugador();
        rlutil::locate(55, 6);
        std::cout << "JUGADOR " << i+1;
        label("Nombre: ", 53, 8);
        labelInt(175, 52, 9);
        rlutil::locate(53,9);
        rlutil::setChar(33);
        std::cin >> jugador[i];
        label("Apellido: ", 53, 11);
        labelInt(175, 52, 12);
        rlutil::locate(53,12);
        rlutil::setChar(33);
        std::cin >> apellidos[i];
    }
}
//-----------

/// 3
void vecZero (int vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        vec[i]=0;
    }
}

void antiCls(int &condicionCls) {
    if (condicionCls==1) {
        rlutil::cls();
        condicionCls = 0;
    }
}

void guardarDados(int vec[], int tam) {
    /*
    srand(time(nullptr));
    for (int i = 0; i < tam; ++i) {
        vec[i]=(1+rand()%6);
    }
     */
    vec[0]=1;
    vec[1]=1;
    vec[2]=1;
    vec[3]=1;
    vec[4]=4;
    vec[5]=5;
}

void pasoDatosHG(int puntuacion[], int jugada, int rondas, int max, char jugadores[][35], char apellidos[][35], bool &cGeneralHG, char* &jugadorHG, char* &apellidoHG, int &rondasHG) {
    if (puntuacion[max]==10000 && jugada!=7) {
        if (!cGeneralHG) {
            jugadorHG = jugadores[max];
            apellidoHG = apellidos[max];
            rondasHG = rondas;
            cGeneralHG = true;
        } else if (rondas<rondasHG){
            jugadorHG = jugadores[max];
            apellidoHG = apellidos[max];
            rondasHG = rondas;
        }
    }
}
//-----------