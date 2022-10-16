//
// Created by Thomas Pufahl on 16/10/2022.
//

#ifndef DIEZ_MIL_ALGORITMOPUNTOS_H
#define DIEZ_MIL_ALGORITMOPUNTOS_H

#endif //DIEZ_MIL_ALGORITMOPUNTOS_H

int identificarJugada(int vec[], int tam, int &puntos, int &varCaso4);

///QUE HACE EL ALGORITMO:
// EVALUA EL TIPO DE JUGADA SEGUN LOS DADOS
// RETORNA UN NUMERO QUE IDENTIFICA A LA JUGADA
// MODIFICA LA VARIABLE QUE OTORGA PUNTOS SEGUN LA JUGADA

///JUGADAS
//JUGADAS GANADORAS
//1. 1 o 2 dados con el valor 1 => JUEGO DE 1 => 100 PUNTOS por dado. MAX DE 200 (dos dados)
//2. 1 o 2 dados con el valor 5 => JUEGO DE 5 => 50 PUNTOS por dado. MAX DE 100 (dos dados)

//3.   3         dados con el valor 1          => TRIO 1            => 1000 PUNTOS
//4. dados>=3    con el mismo valor, EXCEPTO 1 => TRIO X(valorDado) => X * 100 PUNTOS. MAX DE 600 ( dado(num6)>=3 )
//5. 4 o 5       dados con el valor 1          => TRIO 1 AMPLIADO   => 2000 PUNTOS

//6. 6 dados con diferente valor   => ESCALERA LARGA => 1500 PUNTOS

//7. SEIS DADOS CON EL VALOR DE 1     =>     SEXTETO    => GANA LA PARTIDA EN ESA RONDA

// JUGADAS PERDEDORAS
//0. != a las ganadoras

//LAS JUGADAS EN EL ALGORITMO VAN A ESTAR ORDENADAS POR PUNTAJE (MAYOR A MENOR), NO POR CASO
int identificarJugada(int vec[], int tam, int &puntos, int &varCaso4) {
    //puntosXRonda = puntos
    //return = jugada
    puntos=0;

    //7. GANA
    int cont7=0;
    for (int i = 0; i < tam; ++i) {
        if (vec[i]==1) {
            cont7++;
        }
    }
    if (cont7==6) {
        puntos=10000;
        return 7;
    }

    //5. +2000
    int cont5=0;
    for (int i = 0; i < tam; ++i) {
        if (vec[i]==1) {
            cont5++;
        }
    }
    if (cont5>=4) {
        puntos+=2000;
        return 5;
    }

    //6. +1500
    int cont6=0;
    int r6;
    for (int i = 0; i < tam; ++i) {
        r6=0;
        for (int j = 0; j < tam; ++j) {
            if (vec[i]==vec[j]) {
                r6++;
            }
        }
        if (r6>1) {
            cont6++;
        }
    }
    if (cont6==0) {
        puntos+=1500;
        return 6;
    }

    //3. +1000
    int cont3=0;
    for (int i = 0; i < tam; ++i) {
        if (vec[i]==1) {
            cont3++;
        }
    }
    if (cont3==3) {
        puntos+=1000;
        return 3;
    }

    //4. +(MAX)600
    int repetidos[2] = {0, 0};
    bool band4 = true;
    int acu4 = 0;
    int cont4 = 0;
    int r4;
    int max4 = 0;
    for (int i = 0; i < tam; ++i) {
        r4=0;
        for (int j = 0; j < tam; ++j) {
            if (vec[i]==vec[j]) {
                r4++;
            }
        }
        if (r4>1) {
            cont4++;
            acu4+=r4-cont4;
            if (acu4>=3) {
                acu4=0;
                if (band4) {
                    repetidos[0] = vec[i];
                    band4=false;
                } else if (repetidos[0]!=vec[i]){
                    repetidos[1] = vec[i];
                }
            }
        }
    }
    if (repetidos[max4]>repetidos[1]) {
        puntos+=(repetidos[max4]*100);
        varCaso4 = repetidos[max4];
        return 4;
    } else if (repetidos[max4]<repetidos[1]) {
        puntos+=(repetidos[1]*100);
        varCaso4 = repetidos[1];
        return 4;
    }

    //1. +(MAX)200
    int cont1=0;
    for (int i = 0; i < tam; ++i) {
        if (vec[i]==1) {
            cont1++;
        }
    }
    if (cont1==1) {
        puntos+=100;
        return 1;
    } else if (cont1==2) {
        puntos+=200;
        return 1;
    }

    //2. +(MAX)100
    int cont2=0;
    for (int i = 0; i < tam; ++i) {
        if (vec[i]==5) {
            cont2++;
        }
    }
    if (cont2==1) {
        puntos+=50;
        return 2;
    } else if (cont2==2) {
        puntos+=100;
        return 2;
    }


    return 0;
}