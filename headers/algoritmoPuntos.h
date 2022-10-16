//
// Created by Thomas Pufahl on 16/10/2022.
//

#ifndef DIEZ_MIL_ALGORITMOPUNTOS_H
#define DIEZ_MIL_ALGORITMOPUNTOS_H

#endif //DIEZ_MIL_ALGORITMOPUNTOS_H

int identificarJugada(int vec[], int tam, int &puntos);

///QUE HACE EL ALGORITMO:
// EVALUA EL TIPO DE JUGADA SEGUN LOS DADOS
// RETORNA UN NUMERO QUE IDENTIFICA A LA JUGADA
// MODIFICA LA VARIABLE QUE OTORGA PUNTOS SEGUN LA JUGADA

///JUGADAS
// 1 o 2 dados con el valor 1 => JUEGO DE 1 => 100 PUNTOS por dado. MAX DE 200 (dos dados)
// 1 o 2 dados con el valor 5 => JUEGO DE 5 => 50 PUNTOS por dado. MAX DE 100 (dos dados)

//   3         dados con el valor 1          => TRIO 1            => 1000 PUNTOS
// dados>=3    con el mismo valor, EXCEPTO 1 => TRIO X(valorDado) => X * 100 PUNTOS. MAX DE 600 ( dado(num6)>=3 )
// 4 o 5       dados con el valor 1          => TRIO 1 AMPLIADO   => 2000 PUNTOS

// ESCALERA DE 6 DADOS (CRECIENTE)  => ESCALERA LARGA => 1500 PUNTOS

// SEIS DADOS CON EL VALOR DE 1     =>     SEXTETO    => GANA LA PARTIDA EN ESA RONDA


int identificarJugada(int vec[], int tam, int &puntos) {
    //puntosXRonda = puntos
    //return = jugada
    puntos=10;




    return 0;
}