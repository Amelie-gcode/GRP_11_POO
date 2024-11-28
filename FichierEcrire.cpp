#include "FichierEcrire.h"
FichierEcrire::FichierEcrire(string p)
{
    path = p;
}

FichierEcrire::~FichierEcrire()
{
}

void FichierEcrire::Ecrire(GrilleJDVL grille){
    f_out.open(path, std::ofstream::out);
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        return;
    }
    f_out << grille.getLigne()<<" "<< grille.getColonne()<< endl;
    for (int i = 0; i < grille.getLigne(); i++)
    {
        for (int j = 0; j < grille.getColonne(); j++)
        {
            f_out << grille.getCell(i,j)->GetEtat(); 
            f_out << "  " ;
        }
        f_out << endl;
    }
    
    f_out.close(); 
}
