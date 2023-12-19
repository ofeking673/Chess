#include "Board.h"

Board::Board()
{

	char board[66] = { 'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R',
				  'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  '#', '#', '#', '#', '#', '#', '#', '#',
				  'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p',
				  'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r', 1, '\0'}; //initialize board, starting player and null.
	this->board = board; //put value inside board
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
	
	/*
	* this->pieces.insert(rook, "a8");
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
{
	delete this->board;
}

void Board::takePiece(std::string location)
{
	BasePiece* piece = findKeyByValue(location);
	if (piece == nullptr)
	{
		return;
	}
}

BasePiece* Board::findKeyByValue(std::string value)
{
	for (auto& pair : this->pieces)
	{
		if (pair.second == value)
		{
			return pair.first;
		}
	}
	return nullptr;
}
