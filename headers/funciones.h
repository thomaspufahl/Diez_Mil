//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONES_H
#define DIEZ_MIL_FUNCIONES_H

#endif //DIEZ_MIL_FUNCIONES_H


//1. IMPRESION
void endl();
void label(char* texto, int posX, int posY);
void labelInt(int caracter, int posX, int posY);
void bordeMenu();

//2. PUNTERO
void punteroArriba (int &posX, int &posY, int caracter, int limite, int salto);
void punteroAbajo(int &posX, int &posY, int caracter, int limite, int salto);

//3. PETICIONES
void petNombre(char jugador[][35], int cantidad);

//4. PROCESAMIENTOS
void vecZero (int vec[], int tam);
void antiCls(int &condicionCls);



/// 1
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

void bordeMenu() {
    //vertical
    int posVerticalIzq = 29;
    for (int i = 3; i < posVerticalIzq; ++i) {
        rlutil::locate(4, i);
        std::cout << (char)186;
    }
    //esquina inf izq
    rlutil::locate(4, 29);
    std::cout << (char)200;
    //esquina sup izq
    rlutil::locate(4, 2);
    std::cout << (char)201;
    //horizontal inf
    rlutil::locate(5, 29);
    std::cout << (char)205;
    //horizontal sup
    rlutil::locate(5, 2);
    std::cout << (char)205;
}

//-----------

/// 2
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

/// 3
void petNombre(char jugador[][35], int cantidad) {
    rlutil::cls();
    for (int i = 0; i < cantidad; ++i) {
        if (i==1) {
            label("JUGADOR 2: ", 2, 4);
        } else {label("JUGADOR 1: ", 2, 2);}
        std::cin >> jugador[i];
    }
}
//-----------

/// 4
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


//-----------