#pragma once
#include "Board.h"


class King : public BasePiece
{
public:
	King(std::string location, char color) : BasePiece(location, color) {};
	//again no use for deconstructor, so we use default deconstructor


	bool moveCheck(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr) override;
	bool isCheck(std::map<BasePiece*, std::string>* pieces_ptr) override;
	int move(std::string newLocation, std::map<BasePiece*, std::string>* pieces_ptr) override;

};

