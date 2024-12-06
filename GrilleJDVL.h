#pragma once
#include "Grille.h"
#include "RegleJDLV.h"

class GrilleJDVL: public Grille
{
private:
    vector <vector<Cell*>> tab;
    int nb_colonne;
    int nb_ligne;
    Grille* next;
    IRegle* regle;
public:
    GrilleJDVL();
    ~GrilleJDVL()override;
    void afficher()override;
    void ini_grille()override;
    int getLigne()override{return nb_ligne;}
    int getColonne()override{return nb_colonne;}
    void setLigne(int x)override{ nb_ligne=x;}
    void setColonne(int y)override{ nb_colonne=y;}
    Cell* getCell(int i, int j)override{return tab[i][j];}
    void generationNext()override;
    int nb_cote(int i, int j)override;
    Grille* getNext()override{return this->next;}
    bool espaceDispo(int x, int y, int surface_long, int surface_larg)override;
    void fusionGrille(Grille * ajout, int x, int y)override;
};