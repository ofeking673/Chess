#pragma once

#include "Chess.h" // chess.h is for mass importing

#define BoardLength 8
#define BoardSize 66
class BasePiece;

class Board
{
private:

	
	bool turn;

	std::string findBlackKingCords();
public:
	std::map<std::string, BasePiece*> pieces;
	char _board[BoardSize];

	Board();
	~Board();

	bool isTurn(BasePiece* piece);
	void moveTurn();
	void takePiece(std::string location);
	bool isOnCheck(BasePiece* king); // checks if black king is under check
	static std::pair<std::string, std::string> getLocationPair(std::string location) { return std::pair<std::string, std::string>(location.substr(0, 2), location.substr(2, 2)); };
};

