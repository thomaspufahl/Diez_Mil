//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONES_H
#define DIEZ_MIL_FUNCIONES_H

#endif //DIEZ_MIL_FUNCIONES_H


///1. PUNTERO
void punteroArriba (int &posX, int &posY, int caracter, int limite, int salto);
void punteroAbajo(int &posX, int &posY, int caracter, int limite, int salto);

///2. PETICIONES
void petNombre(char jugador[][35], int cantidad);

///3. PROCESAMIENTOS
void vecZero (int vec[], int tam);
void antiCls(int &condicionCls);
void guardarDados(int vec[], int tam);
int identificarJugada(int vec[], int tam, int &puntos);




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
void petNombre(char jugador[][35], int cantidad) {
    rlutil::cls();
    bordePetUnJugador();
    for (int i = 0; i < cantidad; ++i) {
        if (i==1) {
            label("JUGADOR 2", 55, 11);
            labelInt(175, 52, 13);
            rlutil::locate(55,13);
            rlutil::setChar(33);
            std::cin >> jugador[i];
        } else {
            label("JUGADOR 1", 55, 6);
            labelInt(175, 52, 8);
            rlutil::locate(55,8);
            rlutil::setChar(33);
            std::cin >> jugador[i];
        }
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
    for (int i = 0; i < tam; ++i) {
        vec[i]=rand()%6;
        if (vec[i]==0) {vec[i]++;}
    }
}

int identificarJugada(int vec[], int tam, int &puntos) {
    //puntosXRonda = puntos
    //return = jugada
    puntos=10;




    return 0;
}

//-----------