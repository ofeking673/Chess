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


	ok = new Bishop("f1", 'w');
	this->pieces.insert(std::make_pair(std::string("f1"), ok));
	ok = new Bishop("c1", 'w');
	this->pieces.insert(std::make_pair(std::string("c1"), ok));

	ok = new Bishop("f8", 'b');
	this->pieces.insert(std::make_pair(std::string("f8"), ok));
	ok = new Bishop("c8", 'b');
	this->pieces.insert(std::make_pair(std::string("c8"), ok));
	

	ok = new Knight("b1", 'w');
	this->pieces.insert(std::make_pair(std::string("b1"), ok));
	ok = new Knight("g1", 'w');
	this->pieces.insert(std::make_pair(std::string("g1"), ok));
	
	ok = new Knight("g8", 'b');
	this->pieces.insert(std::make_pair(std::string("g8"), ok));
	ok = new Knight("b8", 'b');
	this->pieces.insert(std::make_pair(std::string("b8"), ok));


	ok = new Queen("e1", 'w');
	this->pieces.insert(std::make_pair(std::string("e1"), ok));

	ok = new Queen("e8", 'b');
	this->pieces.insert(std::make_pair(std::string("e8"), ok));

	std::string string = "";
	for (int i = 0; i < BoardLength; i++)
	{
		string += ('a' + i);
		string += '2';
		std::cout << string << std::endl;
		ok = new Pawn(string, 'w');
		this->pieces.insert(std::make_pair(string, ok));
		string = "";
	}

	for (int i = 0; i < BoardLength; i++)
	{
		string += ('a' + i);
		string += '7';
		std::cout << string << std::endl;
		ok = new Pawn(string, 'b');
		this->pieces.insert(std::make_pair(string, ok));
		string = "";
	}
	
	this->turn = true;
}

Board::~Board()
{
	for (auto& piece : pieces)
	{
		delete piece.second;
	}
}

bool Board::isTurn(BasePiece* piece)
{
	return (piece->getColor() == ((turn) ? 'b' : 'w'));
}

void Board::moveTurn()
{
	turn = !turn;
}

bool Board::isOnCheck(BasePiece* king)
{
	for (auto& piece : this->pieces) {
		if (piece.second->getColor() != king->getColor() &&
			!(piece.second->moveCheck(king->getLocation(), &(this->pieces)))) {

			return true;
		}
	}

	return false;
}
