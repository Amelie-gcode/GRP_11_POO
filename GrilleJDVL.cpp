#include "GrilleJDVL.h"
GrilleJDVL::GrilleJDVL(/* args */)
{
    ini_grille();
}

GrilleJDVL::~GrilleJDVL()
{
}

void GrilleJDVL::ini_grille()
{
    tab = vector <vector<Cell>>(nb_ligne,vector<Cell>(nb_colonne));
}

void GrilleJDVL::afficher()
{
   for (int i = 0; i < nb_ligne; i++)
   {
        for (int j = 0; j < nb_colonne; j++)
        {
            cout << tab[i][j].GetEtat() << "  ";
        }
        cout<< " "<< endl;
   }
    
}