#include "RegleJDLV.h"


bool RegleJDLV::Morte(int nb_cote)
{
    if (nb_cote==3)
    {
        return true;
    }
    else return false;
}

bool RegleJDLV::Vivant(int nb_cote)
{
    if (nb_cote==2 || nb_cote==3)
    {
        return true;
    }
    else return false;
}