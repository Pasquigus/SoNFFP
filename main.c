#include "Settings.h"




int main() {

    initscr(); noecho(); curs_set(0); cbreak(); keypad(stdscr, 1); start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);

    attron(COLOR_PAIR(1));

    int x = COLS / 2, y = LINES / 2, c;

    // Altezza del bordo inferiore
    int bottomBorderHeight = LINES-5;

    // Altezza del bordo superiore
    int upperBorderHeight = 11;

    int startTane = 6;

    bool isSpaziIniziali=false,isMuro=false,isTana=false,isSpaziFinali=false;

    // Disegna la finestra con un bordo più spesso nella parte inferiore
    box(stdscr, ACS_VLINE, ACS_HLINE);


    for(int i=0;i<3;i++) {
        for (int j = 0; j < COLS; j++) {
            mvaddch(bottomBorderHeight-i, j, OBJECT);
            refresh();
        }
    }

    for(int i=0;i<5;i++) {
        for (int j = 0; j < COLS; j++) {
            mvaddch(upperBorderHeight-i, j, OBJECT);
            refresh();
        }
    }

    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    /*
    mvprintw(LINES/2,COLS/2-5," /::::::8\\________________");
    mvprintw(LINES/2+1,COLS/2-5," vvvvvvvv |  @ @ @ @ @ @   \\");
    mvprintw(LINES/2+2,COLS/2-5," \\::::::::|_______/:::::::\\ - \\");
     */

    printCrockDxToSx((COLS/2)-25,LINES/2);
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));




    int count = 0;
    int count2= 0;
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(2));
    for(int i = 0; i < COLS; i++){
        mvaddch(3, i, WALL);
        refresh();
    }
    for(int j = 4; j < 7; j++){
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
        attron(COLOR_PAIR(1));
    }


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
}

char cosaScrivo(int pos){
    int tempPos;
    if (pos<SPAZI_INIZIALI){
        return ' ';
    }else{
        tempPos = pos-SPAZI_INIZIALI;

    }
}

void printCrockDxToSx(int x, int y){
    mvprintw(y,x," /::::::8\\________________");
    mvprintw(y+1,x," vvvvvvvv |  @ @ @ @ @ @   \\");
    mvprintw(y+2,x," \\::::::::|_______/:::::::\\ - \\");
}
