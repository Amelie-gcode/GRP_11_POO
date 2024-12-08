#pragma once
#include "GrilleJDVL.h"
#include "IFichier.h"

class FichierLire: public IFichier
{
private:
    ifstream f_in;
    string path; 
public:
    FichierLire(string chemin);
    ~FichierLire()override;
    Grille* Lire()override;
    void Setpath(string chemin)override{path=chemin ;}
};


