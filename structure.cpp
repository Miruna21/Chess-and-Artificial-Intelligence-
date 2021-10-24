#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include "structure.h"
#include "constants.h"
#include "generateAll.h"
#include <vector>
#include <utility>
#include "minimax.h"

using namespace std;

Piece::Piece() {}
// constructor pentru o piesa de pe tabla
Piece::Piece(int id, PieceType pieceType, int color, int x,
    int y, bool captured, int notMove)
{
    this->id = id;
    this->pieceType = pieceType;
    this->color = color;
    this->x = x;
    this->y = y;
    this->captured = captured;
    this->notMove = notMove;
}
int Piece::getId()
{
    return id;
}
PieceType Piece::getPieceType()
{
    return pieceType;
}
int Piece::getColor()
{
    return color;
}
int Piece::getX()
{
    return x;
}
int Piece::getY()
{
    return y;
}
bool Piece::isCaptured()
{
    return captured;
}
void Piece::setId(int id)
{
    this->id = id;
}
void Piece::setColor(int color)
{
    this->color = color;
}
void Piece::setX(int x)
{
    this->x = x;
}
void Piece::setY(int y)
{
    this->y = y;
}
void Piece::setCaptured(bool status)
{
    this->captured = status;
}
void Piece::setPieceType(PieceType pieceType)
{
    this->pieceType = pieceType;
}

void Piece::setNoPiece()
{
    pieceType = NONE;
}
void Piece::setNotMove(int notMove)
{
    this->notMove = notMove;
}
int Piece::getNotMove()
{
    return notMove;
}
Piece::Piece(const Piece& other)
{
    this->id = other.id;
    this->pieceType = other.pieceType;
    this->color = other.color;
    this->x = other.x;
    this->y = other.y;
    this->captured = other.captured;
    this->notMove = other.notMove;
}

void Piece::changePieces(Piece* srcPiece)
{
    this->id = srcPiece->id;
    this->pieceType = srcPiece->pieceType;
    this->color = srcPiece->color;
    this->captured = srcPiece->captured;
    this->notMove = srcPiece->notMove;
}

void Board::setBoard()
{
    // casutele goale
    for (int i = 3; i <= 6; i++) {
        for (int j = 1; j <= 8; j++) {
            square[i][j].setNoPiece();
        }
    }
    // pionii
    for (int i = 1; i <= 8; i++) {
        pieces[i] = Piece(i, PAWN, White, 2, i, false, 0);
        square[2][i] = pieces[i];
        pieces[i + 8] = Piece(i + 8, PAWN, Black, 7, i, false, 0);
        square[7][i] = pieces[i + 8];
    }

    // tura
    pieces[17] = Piece(17, ROOK, White, 1, 1, false, 0);
    square[1][1] = pieces[17];
    pieces[19] = Piece(19, ROOK, Black, 8, 1, false, 0);
    square[8][1] = pieces[19];
    pieces[18] = Piece(18, ROOK, White, 1, 8, false, 0);
    square[1][8] = pieces[18];
    pieces[20] = Piece(20, ROOK, Black, 8, 8, false, 0);
    square[8][8] = pieces[20];

    // calul
    pieces[21] = Piece(21, KNIGHT, White, 1, 2, false, 0);
    square[1][2] = pieces[21];
    pieces[23] = Piece(23, KNIGHT, Black, 8, 2, false, 0);
    square[8][2] = pieces[23];
    pieces[22] = Piece(22, KNIGHT, White, 1, 7, false, 0);
    square[1][7] = pieces[22];
    pieces[24] = Piece(24, KNIGHT, Black, 8, 7, false, 0);
    square[8][7] = pieces[24];

    // nebunul
    pieces[25] = Piece(25, BISHOP, White, 1, 3, false, 0);
    square[1][3] = pieces[25];
    pieces[27] = Piece(27, BISHOP, Black, 8, 3, false, 0);
    square[8][3] = pieces[27];
    pieces[26] = Piece(26, BISHOP, White, 1, 6, false, 0);
    square[1][6] = pieces[26];
    pieces[28] = Piece(28, BISHOP, Black, 8, 6, false, 0);
    square[8][6] = pieces[28];

    // regina
    pieces[29] = Piece(29, QUEEN, White, 1, 4, false, 0);
    square[1][4] = pieces[29];
    pieces[30] = Piece(30, QUEEN, Black, 8, 4, false, 0);
    square[8][4] = pieces[30];

    // regele
    pieces[31] = Piece(31, KING, White, 1, 5, false, 0);
    square[1][5] = pieces[31];
    pieces[32] = Piece(32, KING, Black, 8, 5, false, 0);
    square[8][5] = pieces[32];
}
// functie care seteaza destinatia
void Board::updatePiecesArray(int id, int xFinal, int yFinal) {
    pieces[id].setX(xFinal);
    pieces[id].setY(yFinal);
}

int Board::checkEnPassantMove(int xInitial, int yInitial, int xFinal, int yFinal) {
    // daca pionul initial are un pion al adversarului langa acesta 
    // (pe aceeasi coloana cu destinatia si aceeasi linie cu sursa)
    if (square[xInitial][yFinal].getPieceType() == PAWN &&
     square[xInitial][yInitial].getColor() != square[xInitial][yFinal].getColor()) {
        // pot captura piesa adversarului
        return square[xInitial][yFinal].getId();
    }
    return -1;
}
// ne actualizam tabla de sah
void Board::applyCastling(int turn, int xInitial)
{
    if (xInitial == 0) {
        if (turn == White) {
            char* move1 = strdup("a1d1");
            char* move2 = strdup("e1c1");
            setMove(move1, turn);
            setMove(move2, turn);
        }
        else {
            char* move1 = strdup("a8d8");
            char* move2 = strdup("e8c8");
            setMove(move1, turn);
            setMove(move2, turn);
        }
    }
    else if (xInitial == 9) {
        if (turn == White) {
            char* move1 = strdup("h1f1");
            char* move2 = strdup("e1g1");
            setMove(move1, turn);
            setMove(move2, turn);
        }
        else {
            char* move1 = strdup("h8f8");
            char* move2 = strdup("e8g8");
            setMove(move1, turn);
            setMove(move2, turn);
        }
    }
}

// functie ce face update la tabla cu noua miscare primita
int Board::setMove(char move[4], int turn)
{
    int yInitial = (int)(move[0] - '0' - '0');
    int xInitial = (int)(move[1] - '0');
    int yFinal = (int)(move[2] - '0' - '0');
    int xFinal = (int)(move[3] - '0');
    if (xInitial == 0 || xInitial == 9) {
        applyCastling(turn, xInitial);
        return -2;
    }
    int initialPieceId = square[xInitial][yInitial].getId();
    Piece initialPiece = square[xInitial][yInitial];
    Piece finalPiece = square[xFinal][yFinal];
    bool pawnMovesTwoPositions = false;
    if (initialPiece.getPieceType() == ROOK || initialPiece.getPieceType() == KING) {
        square[xInitial][yInitial].setNotMove(1);
        pieces[initialPieceId].setNotMove(1);
    }
    if (initialPiece.getPieceType() == PAWN && (xFinal == 1 || xFinal == 8)) {
        initialPiece.setPieceType(QUEEN);
        square[xInitial][yInitial].setPieceType(QUEEN);
        pieces[initialPieceId].setPieceType(QUEEN);
    }

    // daca un pion se muta 2 patratele, retin acest lucru
    if (initialPiece.getPieceType() == PAWN && abs(xFinal - xInitial) == 2) {
        this->pawnPossibleCaptureEnPassantId = initialPiece.getId();
        pawnMovesTwoPositions = true;
    }
    // daca este o mutare de tip EnPassant
    if (pieces[initialPieceId].getPieceType() == PAWN && finalPiece.getPieceType() == NONE &&
     checkEnPassantMove(xInitial, yInitial, xFinal, yFinal) != -1) {
        int capturedPieceEnPassantId = checkEnPassantMove(xInitial, yInitial, xFinal, yFinal);
        int xCapture = pieces[capturedPieceEnPassantId].getX();
        int yCapture = pieces[capturedPieceEnPassantId].getY();
        // actualizez piesa din sursa pe casuta libera destinatie
        square[xFinal][yFinal].changePieces(&square[xInitial][yInitial]);
        square[xInitial][yInitial].setNoPiece();
        updatePiecesArray(initialPieceId, xFinal, yFinal);
        // sterg piesa capturata
        square[xCapture][yCapture].setNoPiece();
        pieces[capturedPieceEnPassantId].setCaptured(true);
        this->pawnPossibleCaptureEnPassantId = -1;
        return capturedPieceEnPassantId;
    }

    if (finalPiece.getPieceType() == NONE) {
        // casuta destinatie este libera
        square[xFinal][yFinal].changePieces(&square[xInitial][yInitial]);
        square[xInitial][yInitial].setNoPiece();
        updatePiecesArray(initialPieceId, xFinal, yFinal);
        if (pawnMovesTwoPositions == false) {
            this->pawnPossibleCaptureEnPassantId = -1;
        }
        return -1;
    }
    else if (finalPiece.getColor() != initialPiece.getColor()) {
        // daca adversarul ne captureaza o piesa neagra
        int capturedPieceId = finalPiece.getId();
        square[xFinal][yFinal].changePieces(&square[xInitial][yInitial]);
        square[xInitial][yInitial].setNoPiece();
        updatePiecesArray(initialPieceId, xFinal, yFinal);
        // sterg piesa care se afla pe casuta destinatie
        // din vectorul de piese negre
        pieces[capturedPieceId].setCaptured(true);
        if (pawnMovesTwoPositions == false) {
            this->pawnPossibleCaptureEnPassantId = -1;
        }
        return capturedPieceId;
    }
    return -2;
}

void Board::makeMove(int turn)
{
    // aleg cea mai buna mutare
    char move[20];
    char str[5] = { 'x', 'x', 'x', 'x', '\0' };
    char str_copy[5] = { 'x', 'x', 'x', 'x', '\0' };
    strcpy(move, "move ");
    // apelez algoritmul de Mini-Max
    int score = maxi(*this, 5, turn, str, Inf);
    if (score != (-Inf + 10)) {
        // daca am gasit o mutare valida, setam mutarea
        setMove(str, turn);
        // daca este  cumva o rocada , atribuim 
        // mutarea corecta
        if (turn == White) {
            if (str[1] == '0') {
                // rocada mare
                str[0] = 'e';
                str[1] = '1';
                str[2] = 'c';
                str[3] = '1';
                str[4] = '\0';
            }
            else if (str[1] == '9') {
                // rocada mica
                str[0] = 'e';
                str[1] = '1';
                str[2] = 'g';
                str[3] = '1';
                str[4] = '\0';
            }
        }
        else {
            if (str[1] == '0') {
                // rocada mare
                str[0] = 'e';
                str[1] = '8';
                str[2] = 'c';
                str[3] = '8';
                str[4] = '\0';
            }
            else if (str[1] == '9') {
                // rocada mica
                str[0] = 'e';
                str[1] = '8';
                str[2] = 'g';
                str[3] = '8';
                str[4] = '\0';
            }
        }
        strcat(move, str);
        printf("%s\n", move);
        fflush(stdout);
    }
    else if(score == (-Inf + 10) && strcmp(str, str_copy) != 0){
    	setMove(str, turn);
    	strcat(move, str);
        printf("%s\n", move);
        fflush(stdout);
    }
    else {
        // daca nu am gasit o mutare valida, ne predam
        printf("resign\n");
        fflush(stdout);
    }
}

// sortam miscarile astfel incat primele sa fie cele care captureaza piese
bool cmp(const Move_coord& a, const Move_coord& b)
{
    return a.can_capture > b.can_capture;
}
// generam toate miscarile posibile pt fiecare piese + rocadele
vector<Move_coord> Board::generateAllMoves(Piece pieces[33], int turn)
{
    vector<Move_coord> allMoves;
    int rook1 = -1, rook2 = -1, king = -1;
    for (int i = 1; i <= 32; i++) {
        if (pieces[i].isCaptured() == false && turn == pieces[i].getColor()) {
            if (pieces[i].getPieceType() == PAWN) {
                generateAllMovesPAWN(pieces[i], allMoves);
            }
            if (pieces[i].getPieceType() == KNIGHT) {
                generateAllMovesKNIGHT(pieces[i], allMoves);
            }
            if (pieces[i].getPieceType() == BISHOP) {
                generateAllMovesBISHOP(pieces[i], allMoves);
            }

            if (pieces[i].getPieceType() == QUEEN) {
                generateAllMovesQUEEN(pieces[i], allMoves);
            }
            if (pieces[i].getPieceType() == ROOK) {
                generateAllMovesROOK(pieces[i], allMoves);
                if (rook1 == -1) {
                    rook1 = i;
                }
                else {
                    rook2 = i;
                }
            }
            if (pieces[i].getPieceType() == KING) {
                generateAllMovesKING(pieces[i], allMoves);
                king = i;
            }
        }
    }

    if (king != -1) {
        generateCastling(allMoves, king, rook1, rook2, turn);
    }
    // sortam miscarile in functie de piesele capturate
    sort(allMoves.begin(), allMoves.end(), cmp);

    return allMoves;
}
// functia de evaluare
// contine euristica pt rocada
// de asemenea, contine euristica pt pozitia oricarei piese pe harta
// in functie de valorile din matricile din minimax.h
// fiecare piesa are de asemenea valoarea proprie
int Board::evaluate(int turn, int kingId)
{
    int sumW = 0, sumB = 0, i, j;

    for (i = 1; i < 9; i++) {
        for (j = 1; j < 9; j++) {
            //verific fiecare piesa de pe tabla si adaug la sumW, respectiv sumB,
            //valuarea ei si bonusul pozitiei
            //daca este pion alb
            if (square[i][j].getPieceType() == PAWN && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 100 + pawnW[i - 1][j - 1];
            }
            //daca este pion negru
            if (square[i][j].getPieceType() == PAWN && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 100 + pawnB[i - 1][j - 1];
            }
            //daca este cal alb
            else if (square[i][j].getPieceType() == KNIGHT && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 300 + knightW[i - 1][j - 1];
            }
            //daca este cal negru
            else if (square[i][j].getPieceType() == KNIGHT && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 300 + knightB[i - 1][j - 1];
            }
            //daca este nebun alb
            else if (square[i][j].getPieceType() == BISHOP && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 300 + bishopW[i - 1][j - 1];
            }
            //daca este nebun negru
            else if (square[i][j].getPieceType() == BISHOP && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 300 + bishopB[i - 1][j - 1];
            }
            //daca este tura alb
            else if (square[i][j].getPieceType() == ROOK && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 500 + rookW[i - 1][j - 1];
            }
            //daca este tura negru
            else if (square[i][j].getPieceType() == ROOK && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 500 + rookB[i - 1][j - 1];
            }
            //daca este regina alba
            else if (square[i][j].getPieceType() == QUEEN && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 900 + queenW[i - 1][j - 1];
            }
            //daca este regina neagra
            else if (square[i][j].getPieceType() == QUEEN && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 900 + queenB[i - 1][j - 1];
            }
            // daca este regele alb
            else if (square[i][j].getPieceType() == KING && square[i][j].getColor() == White && pieces[square[i][j].getId()].isCaptured() == false) {
                sumW = sumW + 20000 + kingW[i - 1][j - 1];
            }
            //daca este regele neagru
            else if (square[i][j].getPieceType() == KING && square[i][j].getColor() == Black && pieces[square[i][j].getId()].isCaptured() == false) {
                sumB = sumB + 20000 + kingB[i - 1][j - 1];
            }
        }
    }
    // Castling
    if (square[1][3].getPieceType() == KING && square[1][3].getColor() == White && square[1][4].getPieceType() == ROOK && square[1][4].getColor() == White) {
        sumW += 100;
    }
    if (square[1][7].getPieceType() == KING && square[1][7].getColor() == White && square[1][6].getPieceType() == ROOK && square[1][6].getColor() == White) {
        sumW += 110;
    }
    if (square[8][3].getPieceType() == KING && square[8][3].getColor() == Black && square[8][4].getPieceType() == ROOK && square[8][4].getColor() == Black) {
        sumB += 100;
    }
    if (square[8][7].getPieceType() == KING && square[8][7].getColor() == Black && square[8][6].getPieceType() == ROOK && square[8][6].getColor() == Black) {
        sumB += 110;
    }
    // facem diferenta in functie de tura
    if (turn == White)
        return sumW - sumB;
    else
        return sumB - sumW;
}

// functie ce verifica daca regele este in sah
bool Board::isCheck(int kingId, int king_x, int king_y, int &attackerId) {
    int cnt = 1;
    // verificam dreapta
      // nu luam in considerare actualul rege
    while((king_y + cnt) <= 8 && ((square[king_x][king_y + cnt].getPieceType() == NONE) || (square[king_x][king_y + cnt].getPieceType() == KING
                                                    && square[king_x][king_y + cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_y + cnt) <= 8 && square[king_x][king_y + cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x][king_y + cnt];
        if (thisPiece.getPieceType() == ROOK || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
    }
    // verificam stanga
    cnt = 1;
    while((king_y - cnt) >= 1 && (square[king_x][king_y - cnt].getPieceType() == NONE || (square[king_x][king_y - cnt].getPieceType() == KING
                                        && square[king_x][king_y - cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_y - cnt) >= 1 && square[king_x][king_y - cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x][king_y - cnt];
        if (thisPiece.getPieceType() == ROOK || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
    }
    // verificam sus
    cnt = 1;
    while((king_x + cnt) <= 8 && (square[king_x + cnt][king_y].getPieceType() == NONE || (square[king_x + cnt][king_y].getPieceType() == KING
                                        && square[king_x + cnt][king_y].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_x + cnt) <= 8 && square[king_x + cnt][king_y].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x + cnt][king_y];
        if ((thisPiece.getPieceType() == ROOK || thisPiece.getPieceType() == QUEEN) || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
    }
    // verificam jos
    cnt = 1;
    while((king_x - cnt) >= 1 && ((square[king_x - cnt][king_y].getPieceType() == NONE) || (square[king_x - cnt][king_y].getPieceType() == KING
                                        && square[king_x - cnt][king_y].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_x - cnt) >= 1 && square[king_x - cnt][king_y].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x - cnt][king_y];
        if (thisPiece.getPieceType() == ROOK || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
    }

    // verificam coltul dreapta-sus
    cnt = 1;
    while((king_x + cnt) <= 8 && (king_y + cnt) <= 8 && (square[king_x + cnt][king_y + cnt].getPieceType() == NONE
                        || (square[king_x + cnt][king_y + cnt].getPieceType() == KING
                        && square[king_x + cnt][king_y + cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }

    if ((king_x + cnt) <= 8 && (king_y + cnt) <= 8 && square[king_x + cnt][king_y + cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x + cnt][king_y + cnt];
        if (thisPiece.getPieceType() == BISHOP || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
        if (cnt == 1 && thisPiece.getPieceType() == PAWN && pieces[kingId].getColor() == White) {
            // doar pionul negru poate ataca regele alb din aceasta pozitie
            attackerId = thisPiece.getId();
            return true;
        }
    }

    // verificam coltul dreapta-jos
    cnt = 1;
    while((king_x - cnt) >= 1 && (king_y + cnt) <= 8 && (square[king_x - cnt][king_y + cnt].getPieceType() == NONE
            || (square[king_x - cnt][king_y + cnt].getPieceType() == KING
                    && square[king_x - cnt][king_y + cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }

    if ((king_x - cnt) >= 1 && (king_y + cnt) <= 8 && square[king_x - cnt][king_y + cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x - cnt][king_y + cnt];
        if (thisPiece.getPieceType() == BISHOP || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
        if (cnt == 1 && thisPiece.getPieceType() == PAWN && pieces[kingId].getColor() == Black) {
            // doar pionul alb poate ataca regele negru din aceasta pozitie
            attackerId = thisPiece.getId();
            return true;
        }
    }
    // verificam coltul stanga-sus
    cnt = 1;
    while((king_x + cnt) <= 8 && (king_y - cnt) >= 1 && (square[king_x + cnt][king_y - cnt].getPieceType() == NONE
            || (square[king_x + cnt][king_y - cnt].getPieceType() == KING
                    && square[king_x + cnt][king_y - cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_x + cnt) <= 8 && (king_y - cnt) >= 1 && square[king_x + cnt][king_y - cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x + cnt][king_y - cnt];
        if (thisPiece.getPieceType() == BISHOP || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
        if (cnt == 1 && thisPiece.getPieceType() == PAWN && pieces[kingId].getColor() == White) {
            attackerId = thisPiece.getId();
            return true;
        }
    }

    // verificam coltul stanga-jos
    cnt = 1;
    while((king_x - cnt) >= 1 && (king_y - cnt) >= 1 && ((square[king_x - cnt][king_y - cnt].getPieceType() == NONE)
                || (square[king_x - cnt][king_y - cnt].getPieceType() == KING
                    && square[king_x - cnt][king_y - cnt].getColor() == pieces[kingId].getColor()))) {
        cnt++;
    }
    if ((king_x - cnt) >= 1 && (king_y - cnt) >= 1 && square[king_x - cnt][king_y - cnt].getColor() != pieces[kingId].getColor()) {
        // o piesa a adversarului
        Piece thisPiece = square[king_x - cnt][king_y - cnt];
        if (thisPiece.getPieceType() == BISHOP || thisPiece.getPieceType() == QUEEN || (cnt == 1 && thisPiece.getPieceType() == KING)) {
            attackerId = thisPiece.getId();
            return true;
        }
        if (cnt == 1 && thisPiece.getPieceType() == PAWN && pieces[kingId].getColor() == Black) {
            attackerId = thisPiece.getId();
            return true;
        }
    }
    // daca avem sah de la un cal
    // stanga sus
    if ((king_x + 2) <= 8 && (king_y - 1) >= 1 && square[king_x + 2][king_y - 1].getPieceType() != NONE
        && square[king_x + 2][king_y - 1].getPieceType() == KNIGHT
        && square[king_x + 2][king_y - 1].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x + 2][king_y - 1].getId();
        return true;
    }

    if ((king_x + 1) <= 8 && (king_y - 2) >= 1
        && square[king_x + 1][king_y - 2].getPieceType() != NONE
        && square[king_x + 1][king_y - 2].getPieceType() == KNIGHT
        && square[king_x + 1][king_y - 2].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x + 1][king_y - 2].getId();
        return true;
    }
    // stanga jos
    if ((king_x - 1) >= 1 && (king_y - 2) >= 1
        && square[king_x - 1][king_y - 2].getPieceType() != NONE
        && square[king_x - 1][king_y - 2].getPieceType() == KNIGHT
        && square[king_x - 1][king_y - 2].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x - 1][king_y - 2].getId();
        return true;
    }

    if ((king_x - 2) >= 1 && (king_y - 1) >= 1
        && square[king_x - 2][king_y - 1].getPieceType() != NONE
        && square[king_x - 2][king_y - 1].getPieceType() == KNIGHT
        && square[king_x - 2][king_y - 1].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x - 2][king_y - 1].getId();
        return true;
    }

    // dreapta jos
    if ((king_x - 2) >= 1 && (king_y + 1) <= 8
        && square[king_x - 2][king_y + 1].getPieceType() != NONE
        && square[king_x - 2][king_y + 1].getPieceType() == KNIGHT
        && square[king_x - 2][king_y + 1].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x - 2][king_y + 1].getId();
        return true;
    }

    if ((king_x - 1) >= 1 && (king_y + 2) <= 8
        && square[king_x - 1][king_y + 2].getPieceType() != NONE
        && square[king_x - 1][king_y + 2].getPieceType() == KNIGHT
        && square[king_x - 1][king_y + 2].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x - 1][king_y + 2].getId();
        return true;
    }

    // dreapta sus
    if ((king_x + 1) <= 8 && (king_y + 2) <= 8
        && square[king_x + 1][king_y + 2].getPieceType() != NONE
        && square[king_x + 1][king_y + 2].getPieceType() == KNIGHT
        && square[king_x + 1][king_y + 2].getColor() != pieces[kingId].getColor()) {
        return true;
    }

    if ((king_x + 2) <= 8 && (king_y + 1) <= 8
        && square[king_x + 2][king_y + 1].getPieceType() != NONE
        && square[king_x + 2][king_y + 1].getPieceType() == KNIGHT
        && square[king_x + 2][king_y + 1].getColor() != pieces[kingId].getColor()) {
        attackerId = square[king_x + 2][king_y + 1].getId();
        return true;
    }
    return false;
}


// verificam daca putem face castling
void getIntermediateWay(vector<pair<int, int> >& intermediate_way, Piece attacker, Piece king)
{
    // drum orizontal
    if (attacker.getX() == king.getX() && attacker.getY() > king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe orizontala, in dreapta
        int aux_colon = attacker.getY() - 1;
        int king_colon = king.getY();
        while ((aux_colon - king_colon) >= 1) {
            intermediate_way.push_back(pair<int, int>(attacker.getX(), aux_colon));
            aux_colon--;
        }
    }
    else if (attacker.getX() == king.getX() && attacker.getY() < king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe orizontala, in stanga
        int aux_colon = attacker.getY() + 1;
        int king_colon = king.getY();
        while ((king_colon - aux_colon) >= 1) {
            intermediate_way.push_back(pair<int, int>(attacker.getX(), aux_colon));
            aux_colon++;
        }
    }
    // drum vertical
    if (attacker.getY() == king.getY() && attacker.getX() < king.getX()) { 
    // caut drumul dintre piesa atacanta si rege pe verticala, in sus
        int aux_line = attacker.getX() + 1;
        int king_line = king.getX();
        while ((king_line - aux_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, attacker.getY()));
            aux_line++;
        }
    }
    else if (attacker.getY() == king.getY() && attacker.getX() > king.getX()) { 
    // caut drumul dintre piesa atacanta si rege pe verticala, in jos
        int aux_line = attacker.getX() - 1;
        int king_line = king.getX();
        while ((aux_line - king_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, attacker.getY()));
            aux_line--;
        }
    }
    // drum diagonal
    if (attacker.getX() > king.getX() && attacker.getY() > king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe diagonala din dreapta-jos
        int aux_line = attacker.getX() - 1;
        int aux_colon = attacker.getY() - 1;
        int king_line = king.getX();
        while ((aux_line - king_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, aux_colon));
            aux_line--;
            aux_colon--;
        }
    }
    else if (attacker.getX() > king.getX() && attacker.getY() < king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe diagonala din stanga-jos
        int aux_line = attacker.getX() - 1;
        int aux_colon = attacker.getY() + 1;
        int king_line = king.getX();
        while ((aux_line - king_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, aux_colon));
            aux_line--;
            aux_colon++;
        }
    }
    else if (attacker.getX() < king.getX() && attacker.getY() > king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe diagonala din dreapta-sus
        int aux_line = attacker.getX() + 1;
        int aux_colon = attacker.getY() - 1;
        int king_line = king.getX();
        while ((king_line - aux_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, aux_colon));
            aux_line++;
            aux_colon--;
        }
    }
    else if (attacker.getX() < king.getX() && attacker.getY() < king.getY()) { 
    // caut drumul dintre piesa atacanta si rege pe diagonala din stanga-sus
        int aux_line = attacker.getX() + 1;
        int aux_colon = attacker.getY() + 1;
        int king_line = king.getX();
        while ((king_line - aux_line) >= 1) {
            intermediate_way.push_back(pair<int, int>(aux_line, aux_colon));
            aux_line++;
            aux_colon++;
        }
    }
}

// functie speciala pentru generarea miscarilor care scot regele din sah
vector<Move_coord> Board::generateAllMovesForEscapingFromCheck(Piece pieces[33], int turn, int kingId, int attackerId)
{
    vector<Move_coord> allMoves;
    vector<pair<int, int> > intermediate_way;
    vector<pair<int, int> >::iterator it;
    // incercam sa mutam regele
    generateAllMovesKING(pieces[kingId], allMoves);
    vector<Move_coord> tmpMoves;
    for (int i = 1; i <= 32; i++) {
        if (pieces[i].isCaptured() == false && turn == pieces[i].getColor()) {
            if (pieces[i].getPieceType() == PAWN) {
                generateAllMovesPAWN(pieces[i], tmpMoves);
            }
            if (pieces[i].getPieceType() == KNIGHT) {
                generateAllMovesKNIGHT(pieces[i], tmpMoves);
            }
            if (pieces[i].getPieceType() == BISHOP) {
                generateAllMovesBISHOP(pieces[i], tmpMoves);
            }

            if (pieces[i].getPieceType() == QUEEN) {
                generateAllMovesQUEEN(pieces[i], tmpMoves);
            }
            if (pieces[i].getPieceType() == ROOK) {
                generateAllMovesROOK(pieces[i], tmpMoves);
            }
        }
    }
    // daca avem spatiu liber intre piesa care ne-a atacat si rege, vom cauta o modalitate de a interpune o piesa proprie in acel loc
    if (pieces[attackerId].getPieceType() == QUEEN || pieces[attackerId].getPieceType() == ROOK || pieces[attackerId].getPieceType() == BISHOP) {
        if (abs(pieces[attackerId].getX() - pieces[kingId].getX()) > 1 || abs(pieces[attackerId].getY() - pieces[kingId].getY()) > 1) {
            getIntermediateWay(intermediate_way, pieces[attackerId], pieces[kingId]);
        }
    }
    // incercam sa capturam piesa care ne-a dat sah sau sa interpunem o piesa proprie intre rege si piesa care ne-a atacat
    for (unsigned int i = 0; i < tmpMoves.size(); i++) {
        int x = tmpMoves[i].destination.first;
        int y = tmpMoves[i].destination.second;
        if ((x == pieces[attackerId].getX() && y == pieces[attackerId].getY())
            || (intermediate_way.size() != 0
                   && find(intermediate_way.begin(), intermediate_way.end(), pair<int, int>(x, y)) != intermediate_way.end())) {
            allMoves.push_back(tmpMoves[i]);
        }
    }
    sort(allMoves.begin(), allMoves.end(), cmp);
    return allMoves;
}

// alpha beta maxi
int Board::maxi(Board& board, int depth, int turn, char final_move[5], int beta)
{
    int max = -Inf + 10;
    int aux =0;
    int score;
    char best_move[5];
    int kingId, attackerId = -1;
    int ok = false;
    // In functie de turn gasim id-ul regelui nostru
    if (turn == White) {
        kingId = 31;
    }
    else {
        kingId = 32;
    }
    // daca atingem adancimea maxima
    if (depth == 0) {
        return board.evaluate(!turn, kingId);
    }
    vector<Move_coord> generated_moves;
    attackerId = -1;
    // vedem daca generam toate miscarile sau doar cele care scot regele din sah
    if (board.isCheck(kingId, board.pieces[kingId].getX(), board.pieces[kingId].getY(), attackerId) == true) {
        generated_moves = board.generateAllMovesForEscapingFromCheck(board.pieces, turn, kingId, attackerId);
    }
    else {
        generated_moves = board.generateAllMoves(board.pieces, turn);
    }
    // daca nu mai avem miscari inseamna ca e game-over
    if (generated_moves.empty() == true) {
        return -Inf + 10;
    }

    if (generated_moves.empty() == false) {
        for (Move_coord movee : generated_moves) {
            char move[5];
            char temp[5];
            move[1] = (char)(movee.source.first + '0');
            move[0] = (char)(movee.source.second + '0' + '0');
            move[3] = (char)(movee.destination.first + '0');
            move[2] = (char)(movee.destination.second + '0' + '0');
            move[4] = '\0';
            Board new_board = board;
            new_board.setMove(move, turn);
            // facem miscarea doar daca nu ne pune regele in sah
            if (new_board.isCheck(kingId, new_board.pieces[kingId].getX(), new_board.pieces[kingId].getY(), attackerId) == false) {
                score = mini(new_board, depth - 1, !turn, temp, max);
                ok = true;
                // actualizam cea mai buna miscare
                if(score == -Inf + 10 && aux == 0){
                	strcpy(best_move, move);
                }
                if (max < score) {
                	aux = 1;
                    max = score;
                    strcpy(best_move, move);
                }
                if (max >= beta) {
                    strcpy(best_move, move);
                    break;
                }
            }
        }
        if (ok == true) {
            strcpy(final_move, best_move);
        } else {
            return -Inf + 10;
        }
    }

    return max;
}

int Board::mini(Board& board, int depth, int turn, char final_move[5], int alpha)
{
    int min = Inf - 10;
    int aux = 0;
    int score, ok = false;
    char best_move[5];
    int kingId, attackerId = -1;
    // In functie de turn gasim id-ul regelui nostru
    if (turn == White) {
        kingId = 31;
    }
    else {
        kingId = 32;
    }
    // daca atingem adancimea maxima
    if (depth == 0) {
        return board.evaluate(!turn, kingId);
    }
    vector<Move_coord> generated_moves;
    attackerId = -1;
    // vedem daca generam toate miscarile sau doar cele care scot regele din sah
    if (board.isCheck(kingId, board.pieces[kingId].getX(), board.pieces[kingId].getY(), attackerId) == true) {
        generated_moves = board.generateAllMovesForEscapingFromCheck(board.pieces, turn, kingId, attackerId);
    }
    else {
        generated_moves = board.generateAllMoves(board.pieces, turn);
    }
    // daca nu mai avem miscari inseamna ca e game-over
    if (generated_moves.empty() == true) {
        return Inf - 10;
    }
    if (generated_moves.empty() == false) {
        for (Move_coord movee : generated_moves) {
            char move[5];
            char temp[5];
            move[1] = (char)(movee.source.first + '0');
            move[0] = (char)(movee.source.second + '0' + '0');
            move[3] = (char)(movee.destination.first + '0');
            move[2] = (char)(movee.destination.second + '0' + '0');
            move[4] = '\0';
            Board new_board = board;
            new_board.setMove(move, turn);
             // facem miscarea doar daca nu ne pune regele in sah
            if (new_board.isCheck(kingId, new_board.pieces[kingId].getX(), new_board.pieces[kingId].getY(), attackerId) == false) {
                score = maxi(new_board, depth - 1, !turn, temp, min);
                ok = true;
                 // actualizam cea mai buna miscare
                if(score == Inf - 10 && aux == 0){
                	strcpy(best_move, move);
                }
                if (min > score) {
                    min = score;
                    strcpy(best_move, move);
                    aux = 1;
                }
                if (min <= alpha) {
                    strcpy(best_move, move);
                    break;
                }
            }
        }
        if (ok == true) {
            strcpy(final_move, best_move);
        } else {
            return Inf - 10;
        }
    }

    return min;
}
