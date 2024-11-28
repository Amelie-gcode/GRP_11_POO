#include "Cell.h"


Cell::Cell()
{
    etat= false;
}

Cell::~Cell()
{
}

bool Cell::GetEtat()
{
    return etat;
}
void Cell::SetEtat(bool a)
{
    etat=a;
}
