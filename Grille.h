#include "Cell.h"
#pragma once
class Grille
{
    
public:
    virtual ~Grille(){}
    virtual void afficher()=0;
    virtual void ini_grille()=0;
    virtual int getLigne()=0;
    virtual int getColonne()=0;
    virtual void setLigne(int x)=0;
    virtual void setColonne(int y)=0;
    virtual Cell* getCell(int i, int j)=0;
    virtual void generationNext(int mode)=0;
    virtual int nb_cote(int i, int j)=0;
    virtual int nb_cote_torique(int i, int j)=0;
    virtual Grille* getNext()=0;
    virtual bool espaceDispo(int x, int y, int surface_long, int surface_larg)=0;
    virtual void fusionGrille(Grille * ajout, int x, int y)=0;
};
