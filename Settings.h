//
// Created by neffefigus on 09/12/23.
//

#ifndef SONFFP_SETTINGS_H
#define SONFFP_SETTINGS_H

//Inclusione librerie utilizzate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ncurses.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <sys/signal.h>

//Definizione delle Macro
#define OBJECT '@'
#define WALL '|'
#define SPAZI_INIZIALI 10
#define DIMENSIONE_MURO 27
#define DIMENSIONE_TANA 9
#define VITE_INIZIALI 3
#define TEMPOMANCHE_SEC 60



//Definizione struttura Tana
typedef struct{
    int x;
    int y;
    bool isOccupata;
}Tana;

void printCrockDxToSx(int x, int y);




#endif //SONFFP_SETTINGS_H
