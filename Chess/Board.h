#pragma once

#include "Chess.h" // chess.h is for mass importing

class Board
{
private:
	
	bool turn;

public:
	std::map<BasePiece*, std::string> pieces;
	char board[66]; // for later send
	Board();
	~Board();
	
	void takePiece(std::string location);
	BasePiece* findKeyByValue(std::string value);

	static std::pair<std::string, std::string> getLocationPair(std::string location) { return std::pair<std::string, std::string>(location.substr(0, 2), location.substr(2, 2)); };
};

