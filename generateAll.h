#include <iostream>
#include <stdio.h>
#include <string.h>
#include "constants.h"
#include <vector>
#include <utility>
using namespace std;

void Board::generateAllMovesBISHOP(Piece bishop, vector<Move_coord>& bishop_vector) {
    pair<int, int> source;
    source.first = bishop.getX();
    source.second = bishop.getY();
    pair<int, int> destination;
    Move_coord my_move;
    int i = 1;
    bool stop = false;
    Piece opponentKing;
    // in functie de culoarea nebunului meu aflu id-ul regelui oponent
    if (bishop.getColor() == White) {
        opponentKing = pieces[32];
    }
    else {
        opponentKing = pieces[31];
    }
    // => pentru cazul in care  nebunul merge in stanga -> sus
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((bishop.getX() + i) <= 8 && (bishop.getY() - i) >= 1 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[bishop.getX() + i][bishop.getY() - i].getPieceType() != NONE
            && square[bishop.getX() + i][bishop.getY() - i].getColor() != bishop.getColor()) {
            if ((bishop.getX() + i) == opponentKing.getX() && (bishop.getY() - i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = bishop.getX() + i;
                destination.second = bishop.getY() - i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                bishop_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[bishop.getX() + i][bishop.getY() - i].getPieceType() == NONE) {
            destination.first = bishop.getX() + i;
            destination.second = bishop.getY() - i;
            my_move.source = source;
            my_move.destination = destination;
            bishop_vector.push_back(my_move);
        }
        else if (square[bishop.getX() + i][bishop.getY() - i].getPieceType() != NONE
            && square[bishop.getX() + i][bishop.getY() - i].getColor() == bishop.getColor()) {
            stop = true; 
        }
        i++;
    }
    // reinitializez
    stop = false;
    i = 1;
    //  => pentru cazul in care nebunul merge in dreapta -> sus 
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((bishop.getX() + i) <= 8 && (bishop.getY() + i) <= 8 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[bishop.getX() + i][bishop.getY() + i].getPieceType() != NONE
            && square[bishop.getX() + i][bishop.getY() + i].getColor() != bishop.getColor()) {
            if ((bishop.getX() + i) == opponentKing.getX() && (bishop.getY() + i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = bishop.getX() + i;
                destination.second = bishop.getY() + i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                bishop_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[bishop.getX() + i][bishop.getY() + i].getPieceType() == NONE) {
            destination.first = bishop.getX() + i;
            destination.second = bishop.getY() + i;
            my_move.source = source;
            my_move.destination = destination;
            bishop_vector.push_back(my_move);
        }
        else if (square[bishop.getX() + i][bishop.getY() + i].getPieceType() != NONE
            && square[bishop.getX() + i][bishop.getY() + i].getColor() == bishop.getColor()) {
            stop = true;
        }
        i++;
    }
    // reinitializez
    stop = false;
    i = 1;
    //  => pentru cazul in care nebunul merge in dreapta -> jos
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((bishop.getX() - i) >= 1 && (bishop.getY() + i) <= 8 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[bishop.getX() - i][bishop.getY() + i].getPieceType() != NONE
            && square[bishop.getX() - i][bishop.getY() + i].getColor() != bishop.getColor()) {
            if ((bishop.getX() - i) == opponentKing.getX() && (bishop.getY() + i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = bishop.getX() - i;
                destination.second = bishop.getY() + i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                bishop_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[bishop.getX() - i][bishop.getY() + i].getPieceType() == NONE) {
            destination.first = bishop.getX() - i;
            destination.second = bishop.getY() + i;
            my_move.source = source;
            my_move.destination = destination;
            bishop_vector.push_back(my_move);
        }
        else if (square[bishop.getX() - i][bishop.getY() + i].getPieceType() != NONE
            && square[bishop.getX() - i][bishop.getY() + i].getColor() == bishop.getColor()) {
            stop = true; 
        }
        i++;
    }
    stop = false;
    i = 1;
    //  => pentru cazul in care nebunul merge in stanga -> jos
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((bishop.getX() - i) >= 1 && (bishop.getY() - i) >= 1 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[bishop.getX() - i][bishop.getY() - i].getPieceType() != NONE
            && square[bishop.getX() - i][bishop.getY() - i].getColor() != bishop.getColor()) {
            if ((bishop.getX() - i) == opponentKing.getX() && (bishop.getY() - i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = bishop.getX() - i;
                destination.second = bishop.getY() - i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                bishop_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[bishop.getX() - i][bishop.getY() - i].getPieceType() == NONE) {
            destination.first = bishop.getX() - i;
            destination.second = bishop.getY() - i;
            my_move.source = source;
            my_move.destination = destination;
            bishop_vector.push_back(my_move);
        }
        else if (square[bishop.getX() - i][bishop.getY() - i].getPieceType() != NONE
            && square[bishop.getX() - i][bishop.getY() - i].getColor() == bishop.getColor()) {
            stop = true; 
        }
        i++;
    }
}
void Board::generateAllMovesROOK(Piece rook, vector<Move_coord>& rook_vector) {
    pair<int, int> source;
    source.first = rook.getX();
    source.second = rook.getY();
    pair<int, int> destination;
    Move_coord my_move;
    // in functie de culoarea turei mele aflu id-ul regelui vecin
    Piece opponentKing;
    if (rook.getColor() == White) {
        opponentKing = pieces[32];
    }
    else {
        opponentKing = pieces[31];
    }
    int i = 1;
    bool stop = false;
    //  => pentru cazul in care  tura merge in sus
   // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((rook.getX() + i) <= 8 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[rook.getX() + i][rook.getY()].getPieceType() != NONE && square[rook.getX() + i][rook.getY()].getColor() != rook.getColor()) {
            if ((rook.getX() + i) == opponentKing.getX() && rook.getY() == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = rook.getX() + i;
                destination.second = rook.getY();
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                rook_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[rook.getX() + i][rook.getY()].getPieceType() == NONE) {
            destination.first = rook.getX() + i;
            destination.second = rook.getY();
            my_move.source = source;
            my_move.destination = destination;
            rook_vector.push_back(my_move);
        }
        else if (square[rook.getX() + i][rook.getY()].getPieceType() != NONE && square[rook.getX() + i][rook.getY()].getColor() == rook.getColor()) {
            stop = true;
        }
        i++;
    }
    // reinitializez
    stop = false;
    i = 1;
    //  => pentru cazul in care tura merge in dreapta
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((rook.getY() + i) <= 8 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[rook.getX()][rook.getY() + i].getPieceType() != NONE && square[rook.getX()][rook.getY() + i].getColor() != rook.getColor()) {
            if (rook.getX() == opponentKing.getX() && (rook.getY() + i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = rook.getX();
                destination.second = rook.getY() + i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                rook_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[rook.getX()][rook.getY() + i].getPieceType() == NONE) {
            destination.first = rook.getX();
            destination.second = rook.getY() + i;
            my_move.source = source;
            my_move.destination = destination;
            rook_vector.push_back(my_move);
        }
        else if (square[rook.getX()][rook.getY() + i].getPieceType() != NONE && square[rook.getX()][rook.getY() + i].getColor() == rook.getColor()) {
            stop = true;
        }
        i++;
    }
    // reinitializez
    stop = false;
    i = 1;
    //  => pentru cazul in care tura merge in jos
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((rook.getX() - i) >= 1 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[rook.getX() - i][rook.getY()].getPieceType() != NONE && square[rook.getX() - i][rook.getY()].getColor() != rook.getColor()) {
            if ((rook.getX() - i) == opponentKing.getX() && rook.getY() == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = rook.getX() - i;
                destination.second = rook.getY();
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                rook_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[rook.getX() - i][rook.getY()].getPieceType() == NONE) {
            destination.first = rook.getX() - i;
            destination.second = rook.getY();
            my_move.source = source;
            my_move.destination = destination;
            rook_vector.push_back(my_move);
        }
        else if (square[rook.getX() - i][rook.getY()].getPieceType() != NONE && square[rook.getX() - i][rook.getY()].getColor() == rook.getColor()) {
            stop = true;
        }
        i++;
    }
    stop = false;
    i = 1;
    //  => pentru cazul in care tura merge in stanga
    // cat timp ma aflu pe tabla si nu am intalnit o piesa de aceeasi culoare
    while ((rook.getY() - i) >= 1 && stop == false) {
        // daca e o piesa a adversarului si nu este regele, adaug miscarea in 
        // lista 
        if (square[rook.getX()][rook.getY() - i].getPieceType() != NONE && square[rook.getX()][rook.getY() - i].getColor() != rook.getColor()) {
            if (rook.getX() == opponentKing.getX() && (rook.getY() - i) == opponentKing.getY()) {
                break;
            }
            else {
                destination.first = rook.getX();
                destination.second = rook.getY() - i;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                rook_vector.push_back(my_move);
                stop = true;
            }
        }
        else if (square[rook.getX()][rook.getY() - i].getPieceType() == NONE) {
            destination.first = rook.getX();
            destination.second = rook.getY() - i;
            my_move.source = source;
            my_move.destination = destination;
            rook_vector.push_back(my_move);
        }
        else if (square[rook.getX()][rook.getY() - i].getPieceType() != NONE && square[rook.getX()][rook.getY() - i].getColor() == rook.getColor()) {
            stop = true;
        }
        i++;
    }
}
void Board::generateAllMovesKNIGHT(Piece knight, vector<Move_coord>& knight_vector) {
    pair<int, int> source;
    source.first = knight.getX();
    source.second = knight.getY();
    pair<int, int> destination;
    Move_coord my_move;
    // in functie de culoare calului meu aflu culoarea regelui vecin
    Piece opponentKing;
    if (knight.getColor() == White) {
        opponentKing = pieces[32];
    }
    else {
        opponentKing = pieces[31];
    }
    // stanga sus caz 1
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() + 2) <= 8 && (knight.getY() - 1) >= 1 && square[knight.getX() + 2][knight.getY() - 1].getPieceType() == NONE) {
        destination.first = knight.getX() + 2;
        destination.second = knight.getY() - 1;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului  si nu este regele adaug mutarea in lista
    else if ((knight.getX() + 2) <= 8 && (knight.getY() - 1) >= 1 && square[knight.getX() + 2][knight.getY() - 1].getPieceType() != NONE
        && square[knight.getX() + 2][knight.getY() - 1].getColor() != knight.getColor()) {
        if ((knight.getX() + 2) != opponentKing.getX() || (knight.getY() - 1) != opponentKing.getY()) {
            destination.first = knight.getX() + 2;
            destination.second = knight.getY() - 1;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // stanga sus caz 2
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() + 1) <= 8 && (knight.getY() - 2) >= 1 && square[knight.getX() + 1][knight.getY() - 2].getPieceType() == NONE) {
        destination.first = knight.getX() + 1;
        destination.second = knight.getY() - 2;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() + 1) <= 8 && (knight.getY() - 2) >= 1 && square[knight.getX() + 1][knight.getY() - 2].getPieceType() != NONE
        && square[knight.getX() + 1][knight.getY() - 2].getColor() != knight.getColor()) {
        if ((knight.getX() + 1) != opponentKing.getX() || (knight.getY() - 2) != opponentKing.getY()) {
            destination.first = knight.getX() + 1;
            destination.second = knight.getY() - 2;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // dreapta sus caz 1
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() + 2) <= 8 && (knight.getY() + 1) <= 8 && square[knight.getX() + 2][knight.getY() + 1].getPieceType() == NONE) {
        destination.first = knight.getX() + 2;
        destination.second = knight.getY() + 1;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() + 2) <= 8 && (knight.getY() + 1) <= 8 && square[knight.getX() + 2][knight.getY() + 1].getPieceType() != NONE
        && square[knight.getX() + 2][knight.getY() + 1].getColor() != knight.getColor()) {
        if ((knight.getX() + 2) != opponentKing.getX() || (knight.getY() + 1) != opponentKing.getY()) {
            destination.first = knight.getX() + 2;
            destination.second = knight.getY() + 1;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // dreapta sus caz 2
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() + 1) <= 8 && (knight.getY() + 2) <= 8 && square[knight.getX() + 1][knight.getY() + 2].getPieceType() == NONE) {
        destination.first = knight.getX() + 1;
        destination.second = knight.getY() + 2;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului  si nu este regele adaug mutarea in lista
    else if ((knight.getX() + 1) <= 8 && (knight.getY() + 2) <= 8 && square[knight.getX() + 1][knight.getY() + 2].getPieceType() != NONE
        && square[knight.getX() + 1][knight.getY() + 2].getColor() != knight.getColor()) {
        if ((knight.getX() + 1) != opponentKing.getX() || (knight.getY() + 2) != opponentKing.getY()) {
            destination.first = knight.getX() + 1;
            destination.second = knight.getY() + 2;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // stanga jos caz 1
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() - 2) >= 1 && (knight.getY() - 1) >= 1 && square[knight.getX() - 2][knight.getY() - 1].getPieceType() == NONE) {
        destination.first = knight.getX() - 2;
        destination.second = knight.getY() - 1;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() - 2) >= 1 && (knight.getY() - 1) >= 1 && square[knight.getX() - 2][knight.getY() - 1].getPieceType() != NONE
        && square[knight.getX() - 2][knight.getY() - 1].getColor() != knight.getColor()) {
        if ((knight.getX() - 2) != opponentKing.getX() || (knight.getY() - 1) != opponentKing.getY()) {
            destination.first = knight.getX() - 2;
            destination.second = knight.getY() - 1;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // stanga jos caz 2
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() - 1) >= 1 && (knight.getY() - 2) >= 1 && square[knight.getX() - 1][knight.getY() - 2].getPieceType() == NONE) {
        destination.first = knight.getX() - 1;
        destination.second = knight.getY() - 2;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() - 1) >= 1 && (knight.getY() - 2) >= 1 && square[knight.getX() - 1][knight.getY() - 2].getPieceType() != NONE
        && square[knight.getX() - 1][knight.getY() - 2].getColor() != knight.getColor()) {
        if ((knight.getX() - 1) != opponentKing.getX() || (knight.getY() - 2) != opponentKing.getY()) {
            destination.first = knight.getX() - 1;
            destination.second = knight.getY() - 2;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // dreapta jos caz 1
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() - 2) >= 1 && (knight.getY() + 1) <= 8 && square[knight.getX() - 2][knight.getY() + 1].getPieceType() == NONE) {
        destination.first = knight.getX() - 2;
        destination.second = knight.getY() + 1;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() - 2) >= 1 && (knight.getY() + 1) <= 8 && square[knight.getX() - 2][knight.getY() + 1].getPieceType() != NONE
        && square[knight.getX() - 2][knight.getY() + 1].getColor() != knight.getColor()) {
        if ((knight.getX() - 2) != opponentKing.getX() || (knight.getY() + 1) != opponentKing.getY()) {
            destination.first = knight.getX() - 2;
            destination.second = knight.getY() + 1;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
    // dreapta jos caz 2
    // daca e o casuta goala adaug mutarea in lista
    if ((knight.getX() - 1) >= 1 && (knight.getY() + 2) <= 8 && square[knight.getX() - 1][knight.getY() + 2].getPieceType() == NONE) {
        destination.first = knight.getX() - 1;
        destination.second = knight.getY() + 2;
        my_move.source = source;
        my_move.destination = destination;
        knight_vector.push_back(my_move);
    } // daca este o piesa a adversarului si nu este regele adaug mutarea in lista
    else if ((knight.getX() - 1) >= 1 && (knight.getY() + 2) <= 8 && square[knight.getX() - 1][knight.getY() + 2].getPieceType() != NONE
        && square[knight.getX() - 1][knight.getY() + 2].getColor() != knight.getColor()) {
        if ((knight.getX() - 1) != opponentKing.getX() || (knight.getY() + 2) != opponentKing.getY()) {
            destination.first = knight.getX() - 1;
            destination.second = knight.getY() + 2;
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            knight_vector.push_back(my_move);
        }
    }
}
void Board::generateAllMovesKING(Piece king, vector<Move_coord>& king_vector) {
    pair<int, int> source;
    source.first = king.getX();
    source.second = king.getY();
    Move_coord my_move;
    pair<int, int> destination;
    int attackerId = -1;
    Piece opponentKing;
    // in functie de culoarea regelui meu aflu id-ul regelui oponent
    if (king.getColor() == White) {
        opponentKing = pieces[32];
    }
    else {
        opponentKing = pieces[31];
    }
    // pentru cazul in care regele merge in sus , verific ca miscarea urmatoare
    // nu il baga in sah 
    if ((king.getX() + 1) <= 8) {
        bool is_check = isCheck(king.getId(), king.getX() + 1, king.getY(), attackerId);
        // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() + 1][king.getY()].getPieceType() != NONE && square[king.getX() + 1][king.getY()].getColor() != king.getColor()
            && is_check == false) {
            if ((king.getX() + 1) != opponentKing.getX() || king.getY() != opponentKing.getY()) {
                destination.first = king.getX() + 1;
                destination.second = king.getY();
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() + 1][king.getY()].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() + 1;
            destination.second = king.getY();
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }

    // pentru cazul in care regele merge in jos , verific ca miscarea urmatoare
    // nu il baga in sah 
    if ((king.getX() - 1) >= 1) {
        bool is_check = isCheck(king.getId(), king.getX() - 1, king.getY(), attackerId);
         // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() - 1][king.getY()].getPieceType() != NONE && square[king.getX() - 1][king.getY()].getColor() != king.getColor() && is_check == false) {
            if ((king.getX() - 1) != opponentKing.getX() || king.getY() != opponentKing.getY()) {
                destination.first = king.getX() - 1;
                destination.second = king.getY();
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() - 1][king.getY()].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() - 1;
            destination.second = king.getY();
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }
    // pentru cazul in care regele merge la dreapta, verific ca miscarea urmatoare
    // nu il baga in sah 
    if ((king.getY() + 1) <= 8) {
        bool is_check = isCheck(king.getId(), king.getX(), king.getY() + 1, attackerId);
        // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX()][king.getY() + 1].getPieceType() != NONE && square[king.getX()][king.getY() + 1].getColor() != king.getColor() && is_check == false) {
            if (king.getX() != opponentKing.getX() || (king.getY() + 1) != opponentKing.getY()) {
                destination.first = king.getX();
                destination.second = king.getY() + 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX()][king.getY() + 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX();
            destination.second = king.getY() + 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }

    // pentru cazul in care regele merge la stanga, verific ca miscarea urmatoare
    // nu il baga in sah 
    if ((king.getY() - 1) >= 1) {
        bool is_check = isCheck(king.getId(), king.getX(), king.getY() - 1, attackerId);
        // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX()][king.getY() - 1].getPieceType() != NONE &&
         square[king.getX()][king.getY() - 1].getColor() != king.getColor() && is_check == false) {
            if (king.getX() != opponentKing.getX() || (king.getY() - 1) != opponentKing.getY()) {
                destination.first = king.getX();
                destination.second = king.getY() - 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX()][king.getY() - 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX();
            destination.second = king.getY() - 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }

    // pentru cazul in care regele merge pe diagonala dreapta-sus,
    // verific ca miscarea urmatoare nu il baga in sah 
    if ((king.getX() + 1) <= 8 && (king.getY() + 1) <= 8) {
        bool is_check = isCheck(king.getId(), king.getX() + 1, king.getY() + 1, attackerId);
         // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() + 1][king.getY() + 1].getPieceType() != NONE &&
         square[king.getX() + 1][king.getY() + 1].getColor() != king.getColor() && is_check == false) {
            if ((king.getX() + 1) != opponentKing.getX() || (king.getY() + 1) != opponentKing.getY()) {
                destination.first = king.getX() + 1;
                destination.second = king.getY() + 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() + 1][king.getY() + 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() + 1;
            destination.second = king.getY() + 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }

    // pentru cazul in care regele merge pe diagonala stanga-sus,
    // verific ca miscarea urmatoare nu il baga in sah 
    if ((king.getX() + 1) <= 8 && (king.getY() - 1) >= 1) {
        bool is_check = isCheck(king.getId(), king.getX() + 1, king.getY() - 1, attackerId);
         // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() + 1][king.getY() - 1].getPieceType() != NONE &&
         square[king.getX() + 1][king.getY() - 1].getColor() != king.getColor() && is_check == false) {
            if ((king.getX() + 1) != opponentKing.getX() || (king.getY() - 1) != opponentKing.getY()) {
                destination.first = king.getX() + 1;
                destination.second = king.getY() - 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() + 1][king.getY() - 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() + 1;
            destination.second = king.getY() - 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }

    // pentru cazul in care regele merge pe diagonala dreapta-jos,
    // verific ca miscarea urmatoare nu il baga in sah 
    if ((king.getX() - 1) >= 1 && (king.getY() + 1) <= 8) {
        bool is_check = isCheck(king.getId(), king.getX() - 1, king.getY() + 1, attackerId);
         // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() - 1][king.getY() + 1].getPieceType() != NONE &&
         square[king.getX() - 1][king.getY() + 1].getColor() != king.getColor() && is_check == false) {
            if ((king.getX() - 1) != opponentKing.getX() || (king.getY() + 1) != opponentKing.getY()) {
                destination.first = king.getX() - 1;
                destination.second = king.getY() + 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        }  // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() - 1][king.getY() + 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() - 1;
            destination.second = king.getY() + 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }


    // pentru cazul in care regele merge pe diagonala stanga-jos,
    // verific ca miscarea urmatoare nu il baga in sah 
    if ((king.getX() - 1) >= 1 && (king.getY() - 1) >= 1) {
        bool is_check = isCheck(king.getId(), king.getX() - 1, king.getY() - 1, attackerId);
        // daca este o piesa a adversarului si nu este in sah, poate captura piesa
        if (square[king.getX() - 1][king.getY() - 1].getPieceType() != NONE &&
         square[king.getX() - 1][king.getY() - 1].getColor() != king.getColor() && is_check == false) {
            if ((king.getX() - 1) != opponentKing.getX() || (king.getY() - 1) != opponentKing.getY()) {
                destination.first = king.getX() - 1;
                destination.second = king.getY() - 1;
                my_move.source = source;
                my_move.destination = destination;
                my_move.can_capture = 1;
                king_vector.push_back(my_move);
            }
        } // daca este o casuta goala adaug miscarea in lista
        else if (square[king.getX() - 1][king.getY() - 1].getPieceType() == NONE && is_check == false) {
            destination.first = king.getX() - 1;
            destination.second = king.getY() - 1;
            my_move.source = source;
            my_move.destination = destination;
            king_vector.push_back(my_move);
        }
    }
}
// Functia generateAllMovesQUEEN genereaza toate miscarile reginei.
void Board::generateAllMovesQUEEN(Piece queen, vector<Move_coord>& queen_vector) {
    // Regina are un comportament similar cu cel al nebului si turei.
    generateAllMovesROOK(queen, queen_vector);
    generateAllMovesBISHOP(queen, queen_vector);
}
void Board::generateAllMovesPAWN(Piece pawn, vector<Move_coord>& pawn_vector) {
    pair<int, int> source;
    source.first = pawn.getX();
    source.second = pawn.getY();
    Move_coord my_move;
    pair<int, int> destination;
    Piece opponentKing;
    if (pawn.getColor() == White) {
        opponentKing = pieces[32];
    }
    else {
        opponentKing = pieces[31];
    }
    // daca este un pion alb
    if (pawn.getColor() == White) {
        // daca pot captura o piesa en passant, creez miscarea corespunzatoare
        if (pawnPossibleCaptureEnPassantId != -1 && pieces[pawnPossibleCaptureEnPassantId].getX() == pawn.getX() &&
         abs(pawn.getY() - pieces[pawnPossibleCaptureEnPassantId].getY()) == 1 && pawn.getColor() != pieces[pawnPossibleCaptureEnPassantId].getColor()) {
            // daca pe aceeasi linie si pe coloane alaturate se afla un pion al adversarului, il pot captura
            destination.first = pawn.getX() + 1;
            destination.second = pieces[pawnPossibleCaptureEnPassantId].getY();
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            pawn_vector.push_back(my_move);
        }
        // daca e prima miscare si intre destinatie si sursa sunt casute goale, adaug miscarea in lista
        if (pawn.getX() == 2 && square[pawn.getX() + 2][pawn.getY()].getPieceType() == NONE &&
         square[pawn.getX() + 1][pawn.getY()].getPieceType() == NONE) {
            destination.first = pawn.getX() + 2;
            destination.second = pawn.getY();
            my_move.source = source;
            my_move.destination = destination;
            pawn_vector.push_back(my_move);
        }
        // cazul in care pionul se deplaseaza o casuta.
        // Daca se afla pe tabla, si este o casuta goala, adaug miscarea in lista
        if ((pawn.getX() + 1) <= 8) {
            if (square[pawn.getX() + 1][pawn.getY()].getPieceType() == NONE) {
                destination.first = pawn.getX() + 1;
                destination.second = pawn.getY();
                my_move.source = source;
                my_move.destination = destination;
                pawn_vector.push_back(my_move);
            }
        }
        // Daca pe diagonala in partea dreapta se afla o piesa de culoare opusa
        // adaug miscarea in lista 
        if ((pawn.getX() + 1) <= 8 && (pawn.getY() + 1) <= 8) {
            if (square[pawn.getX() + 1][pawn.getY() + 1].getPieceType() != NONE) {
                if (square[pawn.getX() + 1][pawn.getY() + 1].getColor() == Black) {
                    if ((pawn.getX() + 1) != opponentKing.getX() || (pawn.getY() + 1) != opponentKing.getY()) {
                        destination.first = pawn.getX() + 1;
                        destination.second = pawn.getY() + 1;
                        my_move.source = source;
                        my_move.destination = destination;
                        my_move.can_capture = 1;
                        pawn_vector.push_back(my_move);
                    }
                }
            }
        }
        // Daca pe diagonala in partea stanga se afla o piesa de culoare opusa
        // adaug miscarea in lista 
        if ((pawn.getX() + 1) <= 8 && (pawn.getY() - 1) >= 1) {
            if (square[pawn.getX() + 1][pawn.getY() - 1].getPieceType() != NONE) {
                if (square[pawn.getX() + 1][pawn.getY() - 1].getColor() == Black) {
                    if ((pawn.getX() + 1) != opponentKing.getX() || (pawn.getY() - 1) != opponentKing.getY()) {
                        destination.first = pawn.getX() + 1;
                        destination.second = pawn.getY() - 1;
                        my_move.source = source;
                        my_move.destination = destination;
                        my_move.can_capture = 1;
                        pawn_vector.push_back(my_move);
                    }
                }
            }
        }
    }
    else if (pawn.getColor() == Black) {
        // daca pot captura o piesa en passant, creez miscarea corespunzatoare
        if (pawnPossibleCaptureEnPassantId != -1 && pieces[pawnPossibleCaptureEnPassantId].getX() == pawn.getX() &&
         abs(pawn.getY() - pieces[pawnPossibleCaptureEnPassantId].getY()) == 1 && pawn.getColor() != pieces[pawnPossibleCaptureEnPassantId].getColor()) {
            // daca pe aceeasi linie si pe coloane alaturate se afla un pion al adversarului, il pot captura
            destination.first = pawn.getX() - 1;
            destination.second = pieces[pawnPossibleCaptureEnPassantId].getY();
            my_move.source = source;
            my_move.destination = destination;
            my_move.can_capture = 1;
            pawn_vector.push_back(my_move);
        }
        // daca e prima miscare si intre destinatie si sursa sunt casute goale, adaug miscarea in lista
        if (pawn.getX() == 7 && square[pawn.getX() - 2][pawn.getY()].getPieceType() == NONE && square[pawn.getX() - 1][pawn.getY()].getPieceType() == NONE) {
            destination.first = pawn.getX() - 2;
            destination.second = pawn.getY();
            my_move.source = source;
            my_move.destination = destination;
            pawn_vector.push_back(my_move);
        }
        // cazul in care pionul se deplaseaza o casuta.
        // Daca se afla pe tabla, si este o casuta goala, adaug miscarea in lista
        if ((pawn.getX() - 1) >= 1) {
            if (square[pawn.getX() - 1][pawn.getY()].getPieceType() == NONE) {
                destination.first = pawn.getX() - 1;
                destination.second = pawn.getY();
                my_move.source = source;
                my_move.destination = destination;
                pawn_vector.push_back(my_move);
            }
        }
        // Daca pe diagonala in partea stanga se afla o piesa de culoare opusa
        // adaug miscarea in lista 
        if ((pawn.getX() - 1) >= 1 && (pawn.getY() - 1) >= 1) {
            if (square[pawn.getX() - 1][pawn.getY() - 1].getPieceType() != NONE) {
                if (square[pawn.getX() - 1][pawn.getY() - 1].getColor() == White) {
                    if ((pawn.getX() - 1) != opponentKing.getX() || (pawn.getY() - 1) != opponentKing.getY()) {
                        destination.first = pawn.getX() - 1;
                        destination.second = pawn.getY() - 1;
                        my_move.source = source;
                        my_move.destination = destination;
                        my_move.can_capture = 1;
                        pawn_vector.push_back(my_move);
                    }
                }
            }
        }
        // Daca pe diagonala in partea dreapta se afla o piesa de culoare opusa
        // adaug miscarea in lista 
        if ((pawn.getX() - 1) >= 1 && (pawn.getY() + 1) <= 8) {
            if (square[pawn.getX() - 1][pawn.getY() + 1].getPieceType() != NONE) {
                if (square[pawn.getX() - 1][pawn.getY() + 1].getColor() == White) {
                    if ((pawn.getX() - 1) != opponentKing.getX() || (pawn.getY() + 1) != opponentKing.getY()) {
                        destination.first = pawn.getX() - 1;
                        destination.second = pawn.getY() + 1;
                        my_move.source = source;
                        my_move.destination = destination;
                        my_move.can_capture = 1;
                        pawn_vector.push_back(my_move);
                    }
                }
            }
        }
    }
}
// Functia genereaza miscarile pentru rocada mare, implicit rocada mica.
void Board::generateCastling(vector<Move_coord>& vector, int king, int rook1, int rook2, int turn) {
    pair<int, int> source;
    Move_coord my_move;
    pair<int, int> destination;
    int attackerId = -1;
    int ok = false;
    // rocada mare
    if (rook1 != -1) { 
        if (pieces[rook1].getNotMove() == 0 && pieces[king].getNotMove() == 0 &&
         square[pieces[rook1].getX()][pieces[rook1].getY() + 1].getPieceType() == NONE &&
          square[pieces[rook1].getX()][pieces[rook1].getY() + 2].getPieceType() == NONE && 
          square[pieces[rook1].getX()][pieces[rook1].getY() + 3].getPieceType() == NONE) {
            // mut regele cu cate o patratica si verific,pe rand, daca intra in sah pana ajunge la destinatie
            if (turn == White && isCheck(king, 1, 4, attackerId) == false && isCheck(king, 1, 3, attackerId) == false) {
                ok = true;
            }
            else if (turn == Black && isCheck(king, 8, 4, attackerId) == false && isCheck(king, 8, 3, attackerId) == false) {
                ok = true;
            }
            if (ok == true) {
                source.first = 0;
                source.second = 0;
                destination.first = 0;
                destination.second = 0;
                my_move.source = source;
                my_move.destination = destination;
                vector.push_back(my_move);
            }
        }
    }
    ok = false;
    // rocada mica
    if (rook2 != -1) { 
        if (pieces[rook2].getNotMove() == 0 && pieces[king].getNotMove() == 0 &&
         square[pieces[rook2].getX()][pieces[rook2].getY() - 1].getPieceType() == NONE &&
          square[pieces[rook2].getX()][pieces[rook2].getY() - 2].getPieceType() == NONE) {
            // mut regele cu cate o patratica si verific,pe rand, daca intra in sah pana ajunge la destinatie
            if (turn == White && isCheck(king, 1, 6, attackerId) == false && isCheck(king, 1, 7, attackerId) == false) {
                ok = true;
            }
            else if (turn == Black && isCheck(king, 8, 6, attackerId) == false && isCheck(king, 8, 7, attackerId) == false) {
                ok = true;
            }
            if (ok == true) {
                source.first = 9;
                source.second = 9;
                destination.first = 9;
                destination.second = 9;
                my_move.source = source;
                my_move.destination = destination;
                vector.push_back(my_move);
            }
        }
    }
}