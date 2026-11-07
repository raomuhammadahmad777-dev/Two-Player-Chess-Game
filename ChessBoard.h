#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "Peice.h"

class ChessBoard{
  private:
    Piece* board[8][8];
  
  public:
      ChessBoard();

      void initializeBoard();
      void displayBoard();

      Piece* getPiece(int row, int col);

      bool isInsideBoard(int row, int col);
      bool isEmpty(int row, int col);

      bool isPathClear(
          int startRow, int startCol,
          int endRow, int endCol
      );

      void movePiece(
          int startRow, int startCol,
          int endRow, int endCol
      );

      void removePiece(int row, int col);

      void clearBoard();

      ~ChessBoard();
};

#endif