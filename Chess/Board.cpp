#include "Board.h"

class Board;


Board::Board()
{

	char board[BoardSize] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
				  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
				  'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', '1', '\0'}; //initialize board, starting player and null.
	strcpy_s(this->_board,BoardSize, board); //put value inside board
	/*
	R N B Q K B N R
	P P P P P P P P
	# # # # # # # #
	# # # # # # # #
	# # # # # # # #
	# # # # # # # #
	p p p p p p p p
	r n b q k b n r
	*/
	BasePiece* ok = new King("d1", 'w');
	this->pieces.insert(std::make_pair(std::string("d1"), ok));

	ok = new King("d8", 'b');
	this->pieces.insert(std::make_pair(std::string("d8"), ok));

	ok = new Rook("h8", 'b');
	this->pieces.insert(std::make_pair(std::string("h8"), ok));
	ok = new Rook("a8", 'b');
	this->pieces.insert(std::make_pair(std::string("a8"), ok));

	ok = new Rook("h1", 'w');
	this->pieces.insert(std::make_pair(std::string("h1"), ok));
	ok = new Rook("a1", 'w');
	this->pieces.insert(std::make_pair(std::string("a1"), ok));
	ok = new Bishop("f8", 'w');
	this->pieces.insert(std::make_pair(std::string("f8"), ok));
	ok = new Bishop("c8", 'w');
	this->pieces.insert(std::make_pair(std::string("c8"), ok));

	
	/*
	* this->pieces.insert(knight, "b8");
	* this->pieces.insert(bishop, "c8");
	* this->pieces.insert(queen, d8);
	* this->pieces.insert(king, e8);
	* this->pieces.insert(bishop, f8)
	* this->pieces.insert(knight, g8)
	* this->pieces.insert(rook, h8)
	* this->pieces.insert(pawn, a-h 7) LOOPS
	* this->pieces.insert(pawn, a-h 2) LOOPS
	* this->pieces.insert(rook, "a1");
	* this->pieces.insert(knight, "b1");
	* this->pieces.insert(bishop, "c1");
	* this->pieces.insert(queen, d1);
	* this->pieces.insert(king, e1);
	* this->pieces.insert(bishop, f1)
	* this->pieces.insert(knight, g1)
	* this->pieces.insert(rook, h1)
	*/
	this->turn = true;
}

Board::~Board()
{}

bool Board::isTurn(BasePiece* piece)
{
	return (piece->getColor() == ((turn) ? 'b' : 'w'));
}

void Board::moveTurn()
{
	turn = !turn;
}

void Board::takePiece(std::string location)
{
	pieces.erase(location);
}

bool Board::isOnCheck(BasePiece* king)
{
	for (auto& piece : this->pieces) {
		if (piece.second->getColor() != king->getColor() &&
			piece.second->moveCheck(king->getLocation(), &(this->pieces))) {

			return true;
		}
	}

	return false;
}
