#pragma once
#include "BasePiece.h"
#include <iostream>
#include "Rook.h"
#include "Bishop.h"

using std::string;


class Queen : public BasePiece
{
public:
	Queen(string location, char color) : BasePiece(location, color) {}

	int moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr) override;

};

