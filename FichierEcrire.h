#pragma once
#include "IFichier.h"
#include "Grille.h"

class FichierEcrire
{
private:
    ofstream f_out;
    static int comp;
public:
    FichierEcrire();
    ~FichierEcrire();
    void Ecrire(Grille *grille);
    string genere_nom();
};
