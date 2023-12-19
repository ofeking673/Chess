#pragma once

#include "Chess.h" // chess.h is for mass importing

#define BoardLength 8
#define BoardSize 66

class Board
{
private:
	
	bool turn;

public:
	std::map<std::string, BasePiece*> pieces;
	char board[BoardSize]; // for later send
	Board();
	~Board();
	
	void takePiece(std::string location);
	std::string findKeyByValue(BasePiece* value);

	static std::pair<std::string, std::string> getLocationPair(std::string location) { return std::pair<std::string, std::string>(location.substr(0, 2), location.substr(2, 2)); };
};

