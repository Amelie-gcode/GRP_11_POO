#include "GrilleJDVL.h"
GrilleJDVL::GrilleJDVL()
{
    nb_colonne=5;
    nb_ligne=5;
    IRegle *regle;
    ini_grille();
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
    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonne; j++) {
            tab[i][j] = new Cell();  // Allouer chaque cellule
        }
    }
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

void GrilleJDVL:: generationNext(){
    regle=new RegleJDLV();
    Grille* temp=new GrilleJDVL();
    temp->setLigne(this->getLigne());
    temp->setColonne(this->getColonne());
    temp->ini_grille();
    for (int i = 0; i < nb_ligne; i++) {
            for (int j = 0; j < nb_colonne; j++) {
                int cote= nb_cote(i,j);
                if (tab[i][j]->GetEtat()) {                    
                    temp->getCell(i,j)->SetEtat(regle->Vivant(cote));
                } else {
                    temp->getCell(i,j)->SetEtat(regle->Morte(cote));
                }
            }
        }
    next =temp;
    //delete temp;
}

