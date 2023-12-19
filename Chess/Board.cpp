#include "Board.h"



Board::Board()
{
	BasePiece* ok = new King("a8", 'w');
	this->pieces.insert(std::make_pair(std::string("a8"), ok));
	ok = new Rook("h8", 'b');
	this->pieces.insert(std::make_pair(std::string("h8"), ok));

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
	this->turn = false;
}

Board::~Board()
{}

void Board::takePiece(std::string location)
{
	BasePiece* piece = pieces[location];
	if (piece == nullptr) //if exists
	{
		return;
	}
	pieces.erase(location);
}
