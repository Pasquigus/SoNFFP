#include "Settings.c"
#include "Settings.h"


int main() {

    //getchar();     decommentare per debugging
    srand(time(NULL));
    initscr(); noecho(); curs_set(0); cbreak(); keypad(stdscr, 1); start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    int x = COLS / 2, y = LINES / 2, c;
    int input = 'a';

    bool isSpaziIniziali=false, isMuro=false, isTana=false, isSpaziFinali=false;


    // Disegna la schermata iniziale
    clear();
    attron(COLOR_PAIR(1));
    mvprintw( 0, 3, " _______   _____    _______   _______     _______     _______   _____         ");
    mvprintw( 1, 3, "|   ____| |  __ |  |   _   | |   ____|   |   ____|   |   ____| |  __ |        ");
    mvprintw( 2, 3, "|  |___   | |  | | |  | |  | |  |        |  |        |  |____  | |  | |       ");
    mvprintw( 3, 3, "|   ___|  |  -- /  |  | |  | |  |  ____  |  |  ____  |   ____| |  -- /        ");
    mvprintw( 4, 3, "|  |      |  _ |   |  | |  | |  | |_  _| |  | |_  _| |  |      |  _ |         ");
    mvprintw( 5, 3, "|  |      | | | |  |  |_|  | |  |___||   |  |___||   |  |____  | | | |        ");
    mvprintw( 6, 3, "|__|      |_|  |_| |_______| |_______|   |_______|   |_______| |_|  |_|       ");

    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(9,3, "BENVENUTO IN FROGGER!");
    mvprintw(11,3, "PREMI 'q' PER USCIRE, 'a' PER INIZIARE IL GIOCO");
    attroff(COLOR_PAIR(3));
    refresh();


    do{
        input=getchar();
    }while(tolower(input)!='q' && tolower(input)!='a');
    clear();

    // Disegna la finestra con un bordo più spesso nella parte inferiore
    attron(COLOR_PAIR(1));
    box(stdscr, ACS_VLINE, ACS_HLINE);
    attroff(COLOR_PAIR(1));

    printTerrenoDiGioco();

    //Movimento croc dx to sx

    while(1){

        for(int i=COLS-34;i>=0;i--){
            if(i==0){
                transitionCrockExitDxToSx(LINES/2);
            }else {
                printCrockDxToSx(i, LINES / 2);

                mvaddch(LINES / 2, i + 26, ' ');
                mvaddch(LINES / 2 + 1, i + 28, ' ');
                mvaddch(LINES / 2 + 2, i + 31, ' ');
                usleep(1000000);
                refresh();
            }
        }
    }





/*
    while (1) {
        c = (int)getch();
        mvaddch(y, x, ' ');

        switch (c) {
            case KEY_UP:
                y -= 1;
                break;
            case KEY_DOWN:
                y += 1;
                break;
            case KEY_LEFT:
                x -= 1;
                break;
            case KEY_RIGHT:
                x += 1;
                break;
            case (int)'q':
                endwin();
                exit(0);
        }

        mvaddch(y, x, OBJECT);
        refresh();
    }
    */

    return 0;
}


