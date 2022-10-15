//
// Created by Thomas Pufahl on 15/10/2022.
//

#ifndef DIEZ_MIL_FUNCIONESESTILO_H
#define DIEZ_MIL_FUNCIONESESTILO_H

#endif //DIEZ_MIL_FUNCIONESESTILO_H

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

