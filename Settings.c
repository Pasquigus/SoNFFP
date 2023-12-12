//
// Created by neffefigus on 12/12/23.
//

#include "Settings.h"

void printMarciapiede(){
    attron(COLOR_PAIR(1));
    // Altezza del bordo inferiore
    int bottomBorderHeight = LINES-5;

    // Altezza del bordo superiore
    int upperBorderHeight = 12;

    int startTane = 6;

    for(int i=0;i<3;i++) {
        for (int j = 0; j < COLS; j++) {
            mvaddch(bottomBorderHeight-i, j, OBJECT);
            refresh();
        }
    }
    attroff(COLOR_PAIR(2));
}

void printSponda(){
    attron(COLOR_PAIR(1));
    // Altezza del bordo inferiore
    int bottomBorderHeight = LINES-5;

    // Altezza del bordo superiore
    int upperBorderHeight = 12;

    int startTane = 6;


    for(int i=0;i<5;i++) {
        for (int j = 0; j < COLS; j++) {
            mvaddch(upperBorderHeight-i, j, OBJECT);
            refresh();
        }
    }
    attron(COLOR_PAIR(1));

}

void printTane(){

    int count = 0;
    int count2= 0;
    attron(COLOR_PAIR(2));
    for(int i = 0; i < COLS; i++){
        mvaddch(3, i, WALL);
        refresh();
    }
    for(int j = 4; j < 8; j++){
        count = 0;

        for(int i = 0; i < COLS; i++){
            if(count < DIMENSIONE_MURO){
                count++;
                mvaddch(j, i, WALL);
                refresh();
            }else {
                count++;
                mvaddch(j, i, ' ');
                refresh();
                if (count == DIMENSIONE_MURO + DIMENSIONE_TANA) {
                    count = 0;
                    count2++;
                }
                if (count2 == 5) {
                    for(int f = i; f < i+DIMENSIONE_MURO; f++){
                        mvaddch(j, f, WALL);
                        refresh();
                    }
                    break;
                }
            }
        }
        if(count2==5){
            count2=0;

            continue;
        }
        attroff(COLOR_PAIR(2));
    }

}

void printMarciapiede_V2(){

}

void printSponda_V2(){

}

void printString(char array[],int x,int y, int cDA){
    int xAggiornata = x;
    for(int i = cDA; i< strlen(array);i++){
        mvaddch(y,xAggiornata,array[i]);
        xAggiornata++;
    }
}

void printTane_V2(){

}
void printCrockDxToSx(int x, int y){
    attron(COLOR_PAIR(3));
    mvprintw(y,x,  " /::::::8\\________________       ");
    mvprintw(y+1,x," vvvvvvvv |  @ @ @ @ @ @   \\     ");
    mvprintw(y+2,x," \\::::::::|_______/:::::::\\ - \\");
    attroff(COLOR_PAIR(3));
}

void transitionCrockExitDxToSx(int y){
    attron(COLOR_PAIR(3));

    char firstRow[40]=  " /::::::8\\________________       ";

    char secondRow[40]= " vvvvvvvv |  @ @ @ @ @ @   \\     ";

    char thirdRow[40]=  " \\::::::::|_______/:::::::\\ - \\";

    for(int i=1;i<strlen(firstRow);i++){
        printString(firstRow,0,y,i);
        printString(secondRow,0,y+1,i);
        printString(thirdRow,0,y+2,i);
        mvaddch(y,0 + 32 - i,' ');
        mvaddch(y+1,0 + 32 - i,' ');
        mvaddch(y+2,0 + 32 - i,' ');
        usleep(100000);
        refresh();
    }

    attroff(COLOR_PAIR(3));
}

char* rimuoviPrimiNCaratteri(const char* input, int n) {
    // Verifica se la stringa in input è vuota o contiene meno di n caratteri
    if (input == NULL || input[0] == '\0' || strlen(input) <= n) {
        return NULL; // Non c'è nulla da rimuovere
    }

    // Calcola la lunghezza della stringa in input
    int lunghezzaInput = strlen(input);

    // Alloca memoria per la nuova stringa senza i primi n caratteri
    char* risultato = (char*)malloc(lunghezzaInput - n + 1);

    if (risultato == NULL) {
        // Errore di allocazione della memoria
        return NULL;
    }

    // Copia la parte della stringa senza i primi n caratteri nella nuova stringa
    strcpy(risultato, input + n);

    return risultato;
}

void printTerrenoDiGioco(){
    printMarciapiede();
    printSponda();
    printTane();
}

void printTerrainInChild() {
    clear();
    printTerrenoDiGioco();
    refresh();
}

void delchar(char *x,int a, int b){
    if ((a+b-1) <= strlen(x)){
    strcpy(&x[b-1],&x[a+b-1]);
    puts(x);
    }
}

int randomNumber(int min, int max){
    return rand()%(max-min+1);
}

