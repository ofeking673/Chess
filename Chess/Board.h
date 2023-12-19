#pragma once

#include "Chess.h" // chess.h is for mass importing

class Board
{
private:
	std::map<BasePiece*, std::string> pieces;
	bool turn;

public:
	char board[66]; // for later send
	Board();
	~Board();
	
	void takePiece(std::string location);
	BasePiece* findKeyByValue(std::string value);
};

