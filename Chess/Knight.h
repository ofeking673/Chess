#pragma once
#include "BasePiece.h"
#include <iostream>

using std::string;
class Knight : public BasePiece
{
public:
	Knight(string location, char color) : BasePiece(location, color) {}

	int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;
};

