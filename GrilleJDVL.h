#include "Grille.h"
#include "RegleJDLV.h"
#pragma once
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
    void ini_grille();
    int getLigne(){return nb_ligne;}
    int getColonne(){return nb_colonne;}
    void setLigne(int x){ nb_ligne=x;}
    void setColonne(int y){ nb_colonne=y;}
    Cell* getCell(int i, int j){return tab[i][j];}
    void generationNext();
    int nb_cote(int i, int j);
    Grille* getNext(){return this->next;}

};

