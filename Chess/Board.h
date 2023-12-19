#pragma once

#include "Chess.h" // chess.h is for mass importing
#include <iostream>
#include <map>
#include <cstring>

class Board
{
private:
	std::map<BasePiece*, std::string> pieces;
	bool turn;

public:
	char* board; // for later send
	Board();
	~Board();
	
	void takePiece(std::string location);
	BasePiece* findKeyByValue(std::string value);
};

