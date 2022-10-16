//
// Created by Thomas Pufahl on 15/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONESESTILO_H
#define DIEZ_MIL_FUNCIONESESTILO_H

#endif //DIEZ_MIL_FUNCIONESESTILO_H

///4. IMPRESION
void label(char* texto, int posX, int posY);
void labelInt(int caracter, int posX, int posY);
void bordeMenu();
void bordePetUnJugador();
void pantallaTurno(int &rondas, char jugadores[][35], int cantidadPJ, int puntuacion[]);
void recuadroRondas();
void recuadroJuego();
void lineaHorizontal(int posY, int caracter);
void lineaVertical(int posX, int caracter);
void mezclar();
void mostrarDados(const int vec[], int tam);
void mostrarJugada(int jugada);
void mostrarSumaPuntaje(int puntaje);
void cuadrado(int posX, int posY, int caracter);
void limpiarCuadrado(int posX, int posY);



/// 4
void label(char* texto, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << texto;
}
void labelInt(int caracter, int posX, int posY) {
    rlutil::locate(posX, posY);
    std::cout << (char)caracter;
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
    int posY=9+7;
    int posX=23+47;
    for (int i = 0; i < 3; ++i) {
        if (i>0) {
            rlutil::msleep(100);
            limpiarCuadrado(posX+(8*2), posY);
            rlutil::msleep(250);
        } else {rlutil::msleep(100);}

        cuadrado(posX, posY, 219);

        rlutil::msleep(250);
        cuadrado(posX+8, posY, 219);

        rlutil::msleep(100);
        limpiarCuadrado(posX, posY);

        rlutil::msleep(250);
        cuadrado(posX+(8*2), posY, 219);

        rlutil::msleep(100);
        limpiarCuadrado(posX+8, posY);

        if (i==2) {
            rlutil::msleep(100);
            limpiarCuadrado(posX+(8*2), posY);
        }
    }
}
void mostrarDados(const int vec[], int tam) {
    int ubiX = 47;
    int ubiY = 9;
    int cont = 0;
    int contY = 0;
    for (int i = 0; i < tam; ++i) {
        if (i==3) {
            contY=8;
            cont=10;
        }
        ///Esquinas
        //SUP
        //izq
        labelInt(218, ubiX+7+cont, ubiY+2+contY);
        //der
        labelInt(191, ubiX+17+cont, ubiY+2+contY);
        //INF
        //izq
        labelInt(192, ubiX+7+cont, ubiY+6+contY);
        //der
        labelInt(217, ubiX+17+cont, ubiY+6+contY);
        ///verticales
        labelInt(179, ubiX+7+cont, ubiY+3+contY);
        labelInt(179, ubiX+17+cont, ubiY+3+contY);
        labelInt(179, ubiX+7+cont, ubiY+5+contY);
        labelInt(179, ubiX+17+cont, ubiY+5+contY);
        ///horizontales
        labelInt(196, ubiX+8+cont, ubiY+2+contY);
        labelInt(196, ubiX+16+cont, ubiY+2+contY);
        labelInt(196, ubiX+8+cont, ubiY+6+contY);
        labelInt(196, ubiX+16+cont, ubiY+6+contY);
        ///puntos
        switch (vec[i]) {
            case 1:
                labelInt(254, ubiX+12+cont, ubiY+4+contY);
                break;
            case 2:
                labelInt(254, ubiX+10+cont, ubiY+3+contY);
                labelInt(254, ubiX+14+cont, ubiY+5+contY);
                break;
            case 3:
                labelInt(254, ubiX+10+cont, ubiY+3+contY);
                labelInt(254, ubiX+12+cont, ubiY+4+contY);
                labelInt(254, ubiX+14+cont, ubiY+5+contY);
                break;
            case 4:
                labelInt(254,ubiX+10+cont, ubiY+3+contY);
                labelInt(254, ubiX+14+cont, ubiY+3+contY);
                labelInt(254, ubiX+10+cont, ubiY+5+contY);
                labelInt(254, ubiX+14+cont, ubiY+5+contY);
                break;
            case 5:
                labelInt(254, ubiX+10+cont, ubiY+3+contY);
                labelInt(254, ubiX+14+cont, ubiY+3+contY);
                labelInt(254, ubiX+12+cont, ubiY+4+contY);
                labelInt(254, ubiX+10+cont, ubiY+5+contY);
                labelInt(254, ubiX+14+cont, ubiY+5+contY);
                break;
            case 6:
                labelInt(254, ubiX+10+cont, ubiY+3+contY);
                labelInt(254, ubiX+12+cont, ubiY+3+contY);
                labelInt(254, ubiX+14+cont, ubiY+3+contY);
                labelInt(254, ubiX+10+cont, ubiY+5+contY);
                labelInt(254, ubiX+12+cont, ubiY+5+contY);
                labelInt(254, ubiX+14+cont, ubiY+5+contY);
                break;
            default:
                break;
        }
        cont+=20;
    }
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

void cuadrado(int posX, int posY, int caracter) {
    //primer linea horizontal
    labelInt(caracter, posX, posY);
    labelInt(caracter, posX+1, posY);
    labelInt(caracter, posX+2, posY);
    labelInt(caracter, posX+3, posY);
    //segunda linea horizontal
    labelInt(caracter, posX, posY+1);
    labelInt(caracter, posX+1, posY+1);
    labelInt(caracter, posX+2, posY+1);
    labelInt(caracter, posX+3, posY+1);
}

void limpiarCuadrado(int posX, int posY) {
    //primer linea horizontal
    label(" ", posX, posY);
    label(" ", posX+1, posY);
    label(" ", posX+2, posY);
    label(" ", posX+3, posY);
    //segunda linea horizontal
    label(" ", posX, posY+1);
    label(" ", posX+1, posY+1);
    label(" ", posX+2, posY+1);
    label(" ", posX+3, posY+1);
}
