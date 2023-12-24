#pragma once
#include "BasePiece.h"
#include <iostream>

using std::string;
class Knight : public BasePiece
{
public:
	Knight(string location, char color) : BasePiece(location, color) {}

	bool moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
	int move(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
};

