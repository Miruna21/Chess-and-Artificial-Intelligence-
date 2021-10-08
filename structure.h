#include "constants.h"
#include <vector>
#include <iostream>
#include <utility>
#include <bits/stdc++.h>
using namespace std;
enum PieceType { KING,
    QUEEN,
    BISHOP,
    KNIGHT,
    ROOK,
    PAWN,
    NONE };
// clasa pentru o piesa de pe tabla
class Piece {
private:
    int id;
    PieceType pieceType;
    bool captured;
    int color;
    int x;
    int y;
    int notMove;

public:
    Piece();
    Piece(int id, PieceType pieceType, int color, int x, int y, bool captured, int notMove);
    int getId();
    PieceType getPieceType();
    int getColor();
    int getX();
    int getY();
    int getNotMove();
    void setNotMove(int notMove);
    bool isCaptured();
    void setId(int id);
    void setColor(int color);
    void setX(int x);
    void setY(int y);
    void setCaptured(bool status);
    void setPieceType(PieceType pieceType);
    void setNoPiece();
    Piece(const Piece& other);
    void changePieces(Piece* srcPiece);
};
struct Move_coord {
    pair<int, int> source;
    pair<int, int> destination;
    int can_capture = 0;
};
// clasa pentru tabla de sah
class Board {
private:
    Piece square[9][9];
    Piece pieces[33];
    int pawnPossibleCaptureEnPassantId = -1;
    void updatePiecesArray(int id, int xFinal, int yFinal);
    int checkEnPassantMove(int xInitial, int yInitial, int xFinal, int yFinal);

public:
    void setBoard();
    int setMove(char move[4], int turn);
    void undoMove(char move[4], int turn, int capturedPieceID);
    void makeMove(int turn);
    vector<Move_coord> generateAllMoves(Piece pieces[33], int turn);
    void generateAllMovesPAWN(Piece pawn, vector<Move_coord>& pawn_vector);
    void generateAllMovesBISHOP(Piece bishop, vector<Move_coord>& bishop_vector);
    void generateAllMovesROOK(Piece rook, vector<Move_coord>& rook_vector);
    void generateAllMovesKNIGHT(Piece knight, vector<Move_coord>& knight_vector);
    void generateAllMovesKING(Piece king, vector<Move_coord>& king_vector);
    void generateAllMovesQUEEN(Piece queen, vector<Move_coord>& queen_vector);
    void generateCastling(vector<Move_coord>& vector, int king, int rook1, int rook2, int turn);
    void applyCastling(int turn, int xInitial);
    bool isCheck(int kingId, int king_x, int king_y, int& attackerId);
    vector<Move_coord> generateAllMovesForEscapingFromCheck(Piece pieces[33], int turn, int kingId, int attackerId);
    int evaluate(int turn, int kingId);
    int maxi(Board& board, int depth, int turn, char move[5], int beta);
    int mini(Board& board, int depth, int turn, char move[5], int alpha);
};
