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
int cargarHG (bool &bandHg, int &ganadorHgMin, int &ganadorHg, char jugadores[][35], int* &punteroTam, char* jugadorMinCpy, int &rondasMin, int &ronda, bool &bVisualHg, int* &punteroTam2, char* apellidoMinCpy, char apellidos[][35]);

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
    srand(time(nullptr));
    for (int i = 0; i < tam; ++i) {
        vec[i]=(1+rand()%6);
    }
}

int cargarHG (bool &bandHg, int &ganadorHgMin, int &ganadorHg, char jugadores[][35], int* &punteroTam, char* jugadorMinCpy, int &rondasMin, int &ronda, bool &bVisualHg, int* &punteroTam2, char* apellidoMinCpy, char apellidos[][35]) {
    if (bandHg) {
        ganadorHgMin = ganadorHg;
        if (ganadorHgMin==2 || ganadorHgMin==3 || ganadorHgMin==4) {
            return 0;
        }
        //nombre
        int i = 0;
        while (jugadores[ganadorHgMin][i]!=0) {
            i++;
        }
        char jugadorMin[i+1];
        for (int j = 0; j < i+1; ++j) {
            jugadorMin[j] = jugadores[ganadorHgMin][j];
        }
        *punteroTam = i;
        strcpy(jugadorMinCpy, jugadorMin);
        //-
        //apellido
        int x = 0;
        while (apellidos[ganadorHgMin][x]!=0) {
            x++;
        }
        char apellidoMin[x+1];
        for (int y = 0; y < x+1; ++y) {
            apellidoMin[y] = apellidos[ganadorHgMin][y];
        }
        *punteroTam2 = x;
        strcpy(apellidoMinCpy, apellidoMin);
        //-

        //rondas
        rondasMin = ronda;
        bVisualHg = true;
        bandHg = false;
    } else if (ronda < rondasMin) {
        ganadorHgMin = ganadorHg;
        if (ganadorHgMin==2 || ganadorHgMin==3 || ganadorHgMin==4) {
            return 0;
        }
        //nombre
        int i = 0;
        while (jugadores[ganadorHgMin][i]!=0) {
            i++;
        }
        char jugadorMin[i+1];
        for (int j = 0; j < i+1; ++j) {
            jugadorMin[j] = jugadores[ganadorHgMin][j];
        }
        *punteroTam = i;
        strcpy(jugadorMinCpy, jugadorMin);
        //-
        //apellido
        int x = 0;
        while (apellidos[ganadorHgMin][x]!=0) {
            x++;
        }
        char apellidoMin[x+1];
        for (int y = 0; y < x+1; ++y) {
            apellidoMin[y] = apellidos[ganadorHgMin][y];
        }
        *punteroTam2 = x;
        strcpy(apellidoMinCpy, apellidoMin);
        //-
        //rondas
        rondasMin = ronda;
    }
    return 0;
}

//-----------