#include "FichierEcrire.h"


int FichierEcrire ::comp =0;
FichierEcrire::FichierEcrire(string p)
{
    path = p;
    ofstream f_out;
}

FichierEcrire::~FichierEcrire()
{
}

string FichierEcrire:: genere_nom(){
    stringstream nomfichier;
    comp++;
    nomfichier<<"Grille_out"<< comp <<".txt" ;
    return nomfichier.str();
    
}

void FichierEcrire::Ecrire(GrilleJDVL* grille){
    f_out.open(genere_nom(), std::ofstream::out);
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << path << endl;
        return;
    }
    f_out << grille->getLigne()<<" "<< grille->getColonne()<< endl;
    for (int i = 0; i < grille->getLigne(); i++)
    {
        for (int j = 0; j < grille->getColonne(); j++)
        {
            f_out << grille->getCell(i,j)->GetEtat(); 
            f_out << "  " ;
        }
        f_out << endl;
    }
    
    f_out.close(); 
}
