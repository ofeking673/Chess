#include "Queen.h"

int Queen::moveCheck(std::string newLocation, std::map<std::string, BasePiece*>* pieces_ptr)
{

    bool rookCheck = false, bishopCheck = false;
    Rook* rook = new Rook(getLocation(), getColor());
    Bishop* bishop = new Bishop(getLocation(), getColor());
    int ok = rook->moveCheck(newLocation, pieces_ptr);
    delete rook;
    if (ok == 0 || ok == 1)
    {
        ok = bishop->moveCheck(newLocation, pieces_ptr);
        delete bishop;
        return ok;
    }
    return ok;
}