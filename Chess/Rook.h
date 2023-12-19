#pragma once
#include "Board.h"
#include <map>

class Rook : public BasePiece
{
public:
	Rook(std::string location, char color) : BasePiece(location, color) {};
	//again no use for constructor, so we use default constructor

	
	bool moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
	int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;

};

