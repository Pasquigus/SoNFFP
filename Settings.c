//
// Created by neffefigus on 12/12/23.
//

#include "Settings.h"

void check(int pipein){

    Entita2 rana, aux, croc;

    croc.x=-1;
    rana.x=-1;



    do{

        read(pipein, &aux, sizeof(Entita2));

        if(aux.tipo == CROC){

            if(croc.x>=0 /*COLS-34*/){

                /*
                mvaddch(LINES / 2, croc.x + 26, ' ');
                mvaddch(LINES / 2 + 1, croc.x + 28, ' ');
                mvaddch(LINES / 2 + 2, croc.x + 31, ' ');  */
                mvaddch(croc.y, croc.x, ' ');
            }

            croc = aux;
            //printCrockDxToSx(aux.x, aux.y);

        }
        else if(aux.tipo == RANA){
            printTerrenoDiGioco();
            if(rana.x>=0)

            {

                mvaddch(rana.y, rana.x, ' ');

            }

            rana=aux;


        }
        mvaddch(aux.y, aux.x, aux.r);
        refresh();

        if (rana.exit==1){  //Esci dalla partita
            break;
        }





    }while(1);  //cambiare la condizione del while con la condizione di endgame()

    endwin();

}

void moveRana(int pipeout){
    Entita2 rana;
    rana.tipo = RANA;
    rana.x = COLS/2;
    rana.y = LINES-2;
    rana.exit = 0;
    rana.r = 'R';

    int c;

    write(pipeout, &rana, sizeof(Entita2));

    while(1){

        c = (int)getch();

        switch(c)

        {

            case KEY_UP:
                if(rana.y > 1){
                    rana.y -= 1;
                }

                break;

            case KEY_DOWN:
                if(rana.y < LINES - 2){
                    rana.y += 1;
                }

                break;

            case KEY_LEFT:
                if(rana.x > 1) {
                    rana.x -= 1;
                }

                break;

            case KEY_RIGHT:
                if(rana.x < COLS - 2) {
                    rana.x += 1;
                }

                break;

            case 'q':
                rana.exit = 1;

        }



        write(pipeout, &rana, sizeof(Entita2));

    }






}

void moveCrocDXtoSX(int pipeout){


    Entita2 croc;
    croc.r = 'C';
    croc.x = COLS; //-34;
    croc.y = LINES/2;
    croc.tipo = CROC;
    croc.exit = 0;

    write(pipeout, &croc, sizeof(Entita2));

    //Movimento croc dx to sx

    while (1) {

        for (int i = croc.x; i >= 0; i--) {
            if (i == 0) {
                //transitionCrockExitDxToSx(croc.y);
                croc.x = COLS;
            } else {
                //printCrockDxToSx(i, croc.y);
                croc.x = i;
                write(pipeout, &croc, sizeof(Entita2));
                usleep(100000);
            }
        }
    }








}

void moveCrocSXtoDX(int pipeout){
    Entita2 croc;
    croc.r = 'C';
    croc.x = 0; //34;
    croc.y = LINES/2+7;
    croc.tipo = CROC;
    croc.exit = 0;

    write(pipeout, &croc, sizeof(Entita2));

    //Movimento croc dx to sx

    while (1) {

        for (int i = croc.x; i < COLS; i++) {
            if (i == COLS-1) {
                //transitionCrockExitDxToSx(croc.y);
                croc.x = 0;
            } else {
                //printCrockDxToSx(i, croc.y);
                croc.x = i;
                write(pipeout, &croc, sizeof(Entita2));
                usleep(100000);
            }
        }
    }








}



void printBox(){
    attron(COLOR_PAIR(1));
    box(stdscr, ACS_VLINE, ACS_HLINE);
    attroff(COLOR_PAIR(1));
}

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
    printBox();
    printMarciapiede();
    printSponda();
    printTane();
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

