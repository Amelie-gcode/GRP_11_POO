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
    ~FichierLire();
    Grille* Lire();
    void Setpath(string chemin){path=chemin ;}
};


