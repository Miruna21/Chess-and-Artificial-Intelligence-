// @Copyright Apostu-Croitoru Diana ,Dobrete Vlad ,Orzata Miruna 321CA
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <unistd.h>
#include <vector>
#include <utility>
#include "structure.h"
#include "constants.h"
using namespace std;

int main()
{
    Board board;
    int turn = White, pc = Black, i;
    setbuf(stdin, NULL);
    char command[30], inBuf[80];
    bool stop = false;
    int forceMode = 0;
    while (!stop) {
        fflush(stdout);
        for (i = 0; (inBuf[i] = getchar()) != '\n'; i++) {
            inBuf[i + 1] = 0;
        }
        // extragem primul cuvant
        sscanf(inBuf, "%s", command);
        // verific daca primeste comanda xboard
        if (strcmp(command, "xboard") == 0) {
            continue;
        }
        // alegem setarile non-default dorite
        if (!strcmp(command, "protover")) {
            printf("feature ping=1 setboard=1 colors=1\n");
            printf("feature usermove=1 memory=1 debug=1\n");
            printf("feature option=\"Resign -check 0\"\n");
            printf("feature option=\"Contempt -spin 0 -200 200\"\n");
            printf("feature done=1\n");
            printf("feature sigint=0\n");
            printf("feature sigterm=0\n");
            printf("feature san=0\n");
            continue;
        }
        // verific daca masina intra in force
        if (strcmp(command, "force") == 0) {
            forceMode = 1;
        }
        // verific daca masina primeste resign
        if (strcmp(command, "resign") == 0) {
            continue;
        }
        // se actualizeaza tabla in functie de coordonatele primite
        if (strcmp(command, "usermove") == 0) {
            char move[5];
            sscanf(inBuf + 9, "%s", move);
            // daca comanda primita este o rocada
            if (turn == White) {
                if (strcmp(move, "e1c1") == 0) {
                    board.setMove(move, turn);
                    char move2[5] = "a1d1";

                    board.setMove(move2, turn);
                }
                else if (strcmp(move, "e1g1") == 0) {
                    board.setMove(move, turn);
                    char move3[5] = "h1f1";
                    board.setMove(move3, turn);
                }
                else {
                    board.setMove(move, turn);
                }
            } else {
                if (strcmp(move, "e8c8") == 0) {
                    board.setMove(move, turn);
                    char move4[5] = "a8d8";
                    board.setMove(move4, turn);
                }
                else if (strcmp(move, "e8g8") == 0) {
                    board.setMove(move, turn);
                    char move5[5] = "h8f8";
                    board.setMove(move5, turn);
                }
                else {
                    board.setMove(move, turn);
                }
            }
            turn = !turn;
        }
        // creez un joc nou
        if (strcmp(command, "new") == 0) {
            turn = White;
            pc = Black;
            board.setBoard();
            forceMode = 0;
        }
        // se primeste comanda ping si se trimite pong
        if (strcmp(command, "ping") == 0) {
            printf("pong%s\n", inBuf + 4);
            fflush(stdout);
            continue;
        }
        // se iese din joc
        if (strcmp(command, "quit") == 0) {
            stop = true;
        }
        // comanda pentru a iesi din force ; seteaza pc-ul in functie de tura
        if (strcmp(command, "go") == 0) {
            pc = turn;
            forceMode = 0;
        }
        // daca e randul pc-ului si nu suntem in forcemode, mutam
        if (turn == pc && forceMode == 0) {
            board.makeMove(turn);
            turn = !turn;
        }
        // comanda primita pentru negru
        if (strcmp(command, "black") == 0) {
            turn = Black;
            pc = White;
            forceMode = 0;
        }
        // comanda primita pentru alb
        if (strcmp(command, "white") == 0) {
            turn = White;
            pc = Black;
            forceMode = 0;
        }
    }

    return 0;
}
