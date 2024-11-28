#include "GrilleJDVL.h"
GrilleJDVL::GrilleJDVL()
{
    ini_grille();
    next= generationNext();
}

GrilleJDVL::~GrilleJDVL()
{
    for (int i = 0; i < nb_ligne; i++)
    {
        for (int j = 0; j < nb_colonne; j++)
        {
            delete tab[i][j];
        }
    }
}

void GrilleJDVL::ini_grille()
{
    tab = vector <vector<Cell*>>(nb_ligne,vector<Cell*>(nb_colonne));
}

void GrilleJDVL::afficher()
{
   for (int i = 0; i < nb_ligne; i++)
   {
        for (int j = 0; j < nb_colonne; j++)
        {
            cout << tab[i][j]->GetEtat() << "  ";
        }
        cout<< " "<< endl;
   }
    
}
int GrilleJDVL:: nb_cote(int i, int j){
    int compt = 0;
        for (int k = i - 1; k <= i + 1; k++) {
            for (int q = j - 1; q <= j + 1; q++) {
                if (k >= 0 && k < nb_ligne && q >= 0 && q < nb_colonne && !(k == i && q == j)) {
                    if (tab[k][q]->GetEtat()) {
                        compt++;
                    }
                }
            }
        }
    return compt;
}

GrilleJDVL* GrilleJDVL:: generationNext(){
    GrilleJDVL* temp;

    for (int i = 0; i < nb_ligne; i++) {
            for (int j = 0; j < nb_colonne; j++) {
                if (tab[i][j]->GetEtat()) {
                    if (nb_cote(i, j) == 2 || nb_cote(i, j) == 3) {
                        temp->getCell(i,j)->SetEtat(true);
                    } else {
                        temp->getCell(i,j)->SetEtat(false);
                    }
                } else {
                    if (nb_cote(i, j) == 3) {
                        temp->getCell(i,j)->SetEtat(true);
                    } else {
                        temp->getCell(i,j)->SetEtat(false);
                    }
                }
            }
        }
    return temp;
}

