#pragma once
#include "Lib.h"
#include "Grille.h"
class IFichier
{
protected:
    
public:
    virtual ~IFichier(){}
    virtual Grille* Lire()=0;
    virtual void Setpath(string chemin)=0;
};