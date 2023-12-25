#include "Queen.h"

int Queen::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{

    bool rookCheck = false, bishopCheck = false;
    Rook* rook = new Rook(getLocation(), getColor());
    Bishop* bishop = new Bishop(getLocation(), getColor());
    bool ok = rook->moveCheck(newLocation, pieces_ptr) || bishop->moveCheck(newLocation, pieces_ptr);
    delete rook;
    delete bishop;
    return ok;
}