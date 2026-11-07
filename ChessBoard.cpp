#include "ChessBoard.h"
#include "Rook.h"
#include "Knight.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Pawn.h"


ChessBoard::ChessBoard(){
  initializeBoard();
}

void ChessBoard::initializeBoard(){
  for (int i = 0; i < 8; i++){
    for (int j = 0; j < 8; j++){
      board[i][j] = nullptr;
    }
  }

  board[0][0] = new Rook(false);
  board[0][1] = new Knight(false);
  board[0][2] = new Bishop(false);
  board[0][3] = new Queen(false);
  board[0][4] = new King(false);
  board[0][5] = new Bishop(false);
  board[0][6] = new Knight(false);
  board[0][7] = new Rook(false);

  for(int i=0; i<8; i++){
    board[1][i] = new Pawn(false);
  }

  for (int j = 0; j < 8; j++){
    board[6][j] = new Pawn(true);
  }

  board[7][0] = new Rook(true);
  board[7][1] = new Knight(true);
  board[7][2] = new Bishop(true);
  board[7][3] = new Queen(true);
  board[7][4] = new King(true);
  board[7][5] = new Bishop(true);
  board[7][6] = new Knight(true);
  board[7][7] = new Rook(true);

}

void ChessBoard::displayBoard(){
  void ChessBoard::displayBoard(){
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if (board[i][j] == nullptr)
                cout << ". ";
            else
                cout << board[i][j]->getSymbol() << " ";
        }
        cout << endl;
    }
  }
}

bool ChessBoard::isInsideBoard(int row, int col){
  return (row >= 0 && row < 8 &&
          col >= 0 && col < 8);
}

bool ChessBoard::isEmpty(int row, int col)
{
    return board[row][col] == nullptr;
}

Piece* ChessBoard::getPiece(int row, int col){
    if (!isInsideBoard(row, col))
        return nullptr;

    return board[row][col];
}

bool ChessBoard::isValidMove(
    int startRow, int startCol,
    int endRow, int endCol)
{
    if (!isInsideBoard(endRow, endCol))
        return false;

    Piece* piece = getPiece(startRow, startCol);

    if (piece == nullptr)
        return false;

    return piece->isValidMove(
        startRow, startCol,
        endRow, endCol, *this);
}

bool ChessBoard::movePiece(
  int startRow, int startCol,
  int endRow, int endCol
){
  if(!isValidMove(startRow,startCol,endRow,endCol)){
    return false;
  }

  Piece* movingPiece = board[startRow][startCol];

  delete movingPiece;

  board[endRow][endCol] = movePiece;
  board[startRow][startCol] = nullptr;

  return true;
}

bool ChessBoard::isPathClear(
  int startRow, int startCol,
  int endRow, int endCol
){
  int rowStep = 0;
  int colStep = 0;

  if(endRow<startRow) rowStep = -1;
  if(endRow>startRow) rowStep = 1;

  if(endCol<startCol) colStep = -1;
  if(endCol>startCol) colStep = 1;

  int r = startRow + rowStep;
  int c = startCol + colStep;

  while(r!=endRow || c!=endCol){
    if(board[r][c] != nullptr){
      return false;
    }

    r += rowStep;
    c += colStep;
  }

  return true;
}

void ChessBoard::clearBoard()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            delete board[i][j];
            board[i][j] = nullptr;
        }
    }
}

~ChessBoard::ChessBoard(){
  clearBoard();
}

void ChessBoard::removePiece(int row, int col)
{
    // Check if position is inside the board
    if (!isInsideBoard(row, col))
        return;

    // Check if there is a piece at this position
    if (board[row][col] == nullptr)
        return;

    // Delete the piece
    delete board[row][col];

    // Make the square empty
    board[row][col] = nullptr;
}

