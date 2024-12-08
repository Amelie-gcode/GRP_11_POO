#include "Cell.h"


Cell::Cell()
{
    etat= false; //initialisation a morte
}

Cell::~Cell()
{
}

bool Cell::GetEtat()
{
    return etat; //retourne l'etat
}
void Cell::SetEtat(bool a)
{
    etat=a;  // set l'etat
}
