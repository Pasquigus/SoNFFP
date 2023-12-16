//
// Created by neffefigus on 12/12/23.
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
#include <ctype.h>
#include <semaphore.h>

//Definizione delle Macro
#define OBJECT '@'
#define WALL '|'
#define SPAZI_INIZIALI 10
#define DIMENSIONE_MURO 27
#define DIMENSIONE_TANA 9
#define VITE_INIZIALI 3
#define TEMPOMANCHE_SEC 60



typedef enum {RANA, CROC, PIANTA}Tipo;
//Definizione strutture
typedef struct{
    int x;
    int y;
    bool isOccupata;
}Tana;

typedef struct{
    Tipo tipo;
    int x;
    int y;
    int exit;
}Entita;

typedef struct{
    char r;
    Tipo tipo;
    int x;
    int y;
    int exit;
}Entita2;


//Prototipi delle funzioni
void printMarciapiede();
void printSponda();
void printTane();
void printBox();
void printMarciapiede_V2();
void printSponda_V2();
void printTane_V2();
void printTerrenoDiGioco();
void printTerrainInChild();
void check(int pipein);
void moveRana(int pipeout);
void moveCrocDXtoSX(int pipeout);
void moveCrocSXtoDX(int pipeout);

char* rimuoviPrimoCarattere(const char* input);
char* rimuoviPrimiNCaratteri(const char* input, int n);

void transitionCrockExitDxToSx(int y);

void printCrockDxToSx(int x, int y);

void delchar(char *x,int a, int b);

void printString(char array[],int x,int y, int cDA);

int randomNumber(int min, int max);

#endif //SONFFP_SETTINGS_H
