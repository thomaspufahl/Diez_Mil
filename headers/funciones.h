//
// Created by thoma on 14/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONES_H
#define DIEZ_MIL_FUNCIONES_H

#endif //DIEZ_MIL_FUNCIONES_H


///1. IMPRESION
void label(char* texto, int posX, int posY);
void labelInt(int caracter, int posX, int posY);
void labelNum(int num, int posX, int posY);
void bordeMenu();
void bordePetUnJugador();
void pantallaTurno(int &rondas, char jugadores[][35], int cantidadPJ, int puntuacion[]);
void recuadroRondas();
void recuadroJuego();
void lineaHorizontal(int posY, int caracter);
void lineaVertical(int posX, int caracter);
void mezclar();
void mostrarDados(int vec[], int tam);
void mostrarJugada(int jugada);
void mostrarSumaPuntaje(int puntaje);
void cuadrado(int posX, int posY);
void limpiarCuadrado(int posX, int posY);


///2. PUNTERO
void punteroArriba (int &posX, int &posY, int caracter, int limite, int salto);
void punteroAbajo(int &posX, int &posY, int caracter, int limite, int salto);

///3. PETICIONES
void petNombre(char jugador[][35], int cantidad);

///4. PROCESAMIENTOS
void vecZero (int vec[], int tam);
void antiCls(int &condicionCls);
void guardarDados(int vec[], int tam);
int identificarJugada(int vec[], int tam, int &puntos);



/// 1
void label(char* texto, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << texto;
}
void labelInt(int caracter, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << (char)caracter;
}
void labelNum(int num, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << num;
}

void bordeMenu() {
    /// esquinas
    // IZQ
    //inf
    rlutil::locate(4, 29);
    std::cout << (char)200;
    //sup
    rlutil::locate(4, 2);
    std::cout << (char)201;
    /// horizontales
    //inf
    rlutil::locate(5, 29);
    std::cout << (char)205;
    //sup
    rlutil::locate(5, 2);
    std::cout << (char)205;
    /// verticales
    //izq
    for (int i = 3; i < 29; ++i) {
        rlutil::locate(4, i);
        std::cout << (char)186;
    }
}
void bordePetUnJugador() {
    /// verticales
    //izq
    for (int i = 4; i < 12; ++i) {
        rlutil::locate(48, i);
        std::cout << (char)186;
    }
    //der
    for (int i = 4; i < 12; ++i) {
        rlutil::locate(69, i);
        std::cout << (char)186;
    }
    /// esquinas
    // IZQ
    //inf
    rlutil::locate(48, 12);
    std::cout << (char)200;
    //sup
    rlutil::locate(48, 3);
    std::cout << (char)201;
    // DER
    //inf
    rlutil::locate(69, 12);
    std::cout << (char)188;
    //sup
    rlutil::locate(69, 3);
    std::cout << (char)187;
    /// horizontales
    // IZQ
    //inf
    rlutil::locate(49, 12);
    std::cout << (char)205;
    //sup
    rlutil::locate(49, 3);
    std::cout << (char)205;
    // DER
    //inf
    rlutil::locate(68, 12);
    std::cout << (char)205;
    //sup
    rlutil::locate(68, 3);
    std::cout << (char)205;
}

void pantallaTurno(int &rondas, char jugadores[][35], int cantidadPJ, int puntuacion[]) {
    rlutil::cls();
    recuadroRondas();
    rlutil::locate(54, 6);
    std::cout << "RONDA N" << char(248) << " " << rondas;

    rlutil::locate(49, 8);
    std::cout << "PROXIMO TURNO: " << strupr(jugadores[0]);

    rlutil::locate(46, 11);
    std::cout << "PUNTAJE DE " << strupr(jugadores[0]) << ": " << puntuacion[0] << " PUNTOS";

    if (cantidadPJ>1) {
        rlutil::locate(46, 12);
        std::cout << "PUNTAJE DE " << strupr(jugadores[1]) << ": " << puntuacion[1];
        std::cout << std::endl;
    }
    rlutil::locate(3, 29);
    std::cout << "PULSA UNA TECLA PARA CONTINUAR...";
    rlutil::anykey();
}

void recuadroRondas() {
    /// esquinas
    // IZQ
    //inf
    rlutil::locate(28, 16);
    std::cout << (char)200;
    //sup
    rlutil::locate(28, 3);
    std::cout << (char)201;
    // DER
    //inf
    rlutil::locate(90, 16);
    std::cout << (char)188;
    //sup
    rlutil::locate(90, 3);
    std::cout << (char)187;
    /// horizontales
    //inf
    for (int i = 29; i < 90; ++i) {
        rlutil::locate(i, 16);
        std::cout << (char)205;
    }
    //sup
    for (int i = 29; i < 90; ++i) {
        rlutil::locate(i, 3);
        std::cout << (char)205;
    }
}
void recuadroJuego() {
    /// esquinas
    // IZQ
    //inf
    rlutil::locate(8, 29);
    std::cout << (char)200;
    //sup
    rlutil::locate(8, 2);
    std::cout << (char)201;
    // DER
    //inf
    rlutil::locate(112, 29);
    std::cout << (char)188;
    //sup
    rlutil::locate(112, 2);
    std::cout << (char)187;
    /// horizontales
    //inf
    for (int i = 9; i < 112; ++i) {
        rlutil::locate(i, 29);
        std::cout << (char)205;
    }
    //sup
    for (int i = 9; i < 112; ++i) {
        rlutil::locate(i, 2);
        std::cout << (char)205;
    }
    /// verticales
    //izq
    for (int i = 3; i < 29; ++i) {
        rlutil::locate(8, i);
        std::cout << (char)186;
    }
    //der
    for (int i = 3; i < 29; ++i) {
        rlutil::locate(112, i);
        std::cout << (char)186;
    }
}
void lineaHorizontal(int posY, int caracter) {
    for (int i = 9; i < 112; ++i) {
        labelInt(char(caracter), i, posY);
    }
}
void lineaVertical(int posX, int caracter) {
    for (int i = 7; i < 29; ++i) {
        labelInt(char(caracter), posX, i);
    }
}

void mezclar() {
    int posY=9;
    int posX=23;
    for (int i = 0; i < 3; ++i) {
        if (i>0) {
            rlutil::msleep(100);
            limpiarCuadrado(posX+(8*2), posY);
            rlutil::msleep(250);
        } else {rlutil::msleep(100);}

        cuadrado(posX,posY);

        rlutil::msleep(250);
        cuadrado(posX+8,posY);

        rlutil::msleep(100);
        limpiarCuadrado(posX, posY);

        rlutil::msleep(250);
        cuadrado(posX+(8*2),posY);

        rlutil::msleep(100);
        limpiarCuadrado(posX+8, posY);

        if (i==2) {
            rlutil::msleep(100);
            limpiarCuadrado(posX+(8*2), posY);
        }
    }
}
void mostrarDados(int vec[], int tam) {
    labelNum(vec[0], 77, 10);
    labelNum(vec[1], 79, 10);
    labelNum(vec[2], 81, 10);
    labelNum(vec[3], 83, 10);
    labelNum(vec[4], 85, 10);
    rlutil::msleep(500);
}

void mostrarJugada(int jugada) {
    switch (jugada) {
        case 0:
            label("TRIO 1 AMPLIADO", 19, 14);
            break;
        case 1:
            label("TRIO 1 AMPLIADO SI", 19, 14);
            break;
        default:
            break;
    }
}

void mostrarSumaPuntaje(int puntaje) {
    label("+     PUNTOS", 20, 16);
    rlutil::locate(21, 16);
    std::cout << puntaje;
}

void cuadrado(int posX, int posY) {
    //primer linea horizontal
    labelInt(219, 47+posX, 7+posY);
    labelInt(219, 47+posX+1, 7+posY);
    labelInt(219, 47+posX+2, 7+posY);
    labelInt(219, 47+posX+3, 7+posY);
    //segunda linea horizontal
    labelInt(219, 47+posX, 7+posY+1);
    labelInt(219, 47+posX+1, 7+posY+1);
    labelInt(219, 47+posX+2, 7+posY+1);
    labelInt(219, 47+posX+3, 7+posY+1);
}

void limpiarCuadrado(int posX, int posY) {
    //primer linea horizontal
    label(" ", 47+posX, 7+posY);
    label(" ", 47+posX+1, 7+posY);
    label(" ", 47+posX+2, 7+posY);
    label(" ", 47+posX+3, 7+posY);
    //segunda linea horizontal
    label(" ", 47+posX, 7+posY+1);
    label(" ", 47+posX+1, 7+posY+1);
    label(" ", 47+posX+2, 7+posY+1);
    label(" ", 47+posX+3, 7+posY+1);
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

void guardarDados(int vec[], int tam) {
    for (int i = 0; i < tam; ++i) {
        vec[i]=rand()%6;
        if (vec[i]==0) {vec[i]++;}
    }
}

int identificarJugada(int vec[], int tam, int &puntos) {
    puntos=10;
    return 0;
}

//-----------