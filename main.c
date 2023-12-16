#include "Settings.c"
#include "Settings.h"


int main() {


    //getchar();     decommentare per debugging

    srand(time(NULL));
    initscr();
    noecho();
    curs_set(0);
    cbreak();
    keypad(stdscr, 1);
    start_color();
    init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    int input = 'a';

    pid_t pid_rana, pid_croc1, pid_croc2;


    int pipefd[2];



    // Disegna la schermata iniziale
    clear();
    attron(COLOR_PAIR(1));
    mvprintw(0, 3, " _______   _____    _______   _______     _______     _______   _____         ");
    mvprintw(1, 3, "|   ____| |  __ |  |   _   | |   ____|   |   ____|   |   ____| |  __ |        ");
    mvprintw(2, 3, "|  |___   | |  | | |  | |  | |  |        |  |        |  |____  | |  | |       ");
    mvprintw(3, 3, "|   ___|  |  -- /  |  | |  | |  |  ____  |  |  ____  |   ____| |  -- /        ");
    mvprintw(4, 3, "|  |      |  _ |   |  | |  | |  | |_  _| |  | |_  _| |  |      |  _ |         ");
    mvprintw(5, 3, "|  |      | | | |  |  |_|  | |  |___||   |  |___||   |  |____  | | | |        ");
    mvprintw(6, 3, "|__|      |_|  |_| |_______| |_______|   |_______|   |_______| |_|  |_|       ");

    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(9, 3, "BENVENUTO IN FROGGER!");
    mvprintw(11, 3, "PREMI 'q' PER USCIRE, 'a' PER INIZIARE IL GIOCO");
    attroff(COLOR_PAIR(3));
    refresh();


    do {
        input = getchar();
    } while (tolower(input) != 'q' && tolower(input) != 'a');
    clear();


    /* Chiamate pipes */
    if(pipe(pipefd)<0){
        perror("pipe call");
        _exit(1);
    }

    //Inizia il gioco
    pid_rana = fork();

    switch (pid_rana) {
        case -1:  //errore
            perror("Errore fork rana\n");
            exit(1);

        case 0:   //figlio rana
            close(pipefd[0]);
            moveRana(pipefd[1]);
            close(pipefd[1]);
            exit(0);

        default:  //padre
            pid_croc1 = fork();
            switch (pid_croc1) {
                case -1: //errore
                    perror("Errore fork croc1\n");
                    exit(1);

                case 0: //figlio croc1
                    close(pipefd[0]);
                    moveCrocDXtoSX(pipefd[1]);
                    close(pipefd[1]);
                    exit(0);

                default:  //padre
                    pid_croc2 = fork();
                    switch (pid_croc2) {
                        case -1:  //errore
                            perror("Errore fork croc2\n");
                            exit(1);

                        case 0:   //figlio croc2
                            close(pipefd[0]);
                            moveCrocSXtoDX(pipefd[1]);
                            close(pipefd[1]);
                            exit(0);

                        default: //padre
                            close(pipefd[1]);
                            check(pipefd[0]);
                            close(pipefd[0]);

                    }
            }
    }


}