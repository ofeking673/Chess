#pragma once
#include "BasePiece.h"
#include <iostream>
#include <map>

class Board;

class King : public BasePiece
{
public:
	King(std::string location, char color) : BasePiece(location, color) {};
	//again no use for deconstructor, so we use default deconstructor


	bool moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
	bool isCheck(Board* brd) override;
	int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;

};

