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

int GrilleJDVL:: nb_cote_torique(int i, int j){
    int compt = 0;
    for (int k = i - 1; k <= i + 1; k++) {
        for (int q = j - 1; q <= j + 1; q++) {
            if (!(k == i && q == j)) {
                int a  = (k + nb_ligne) % nb_ligne;
                int b =  (q + nb_colonne) % nb_colonne;

                if (tab[a][b]->GetEtat()) {
                    compt++;
                }
            }
        }
    }
    return compt;
}

void GrilleJDVL:: generationNext(int mode){
    int cote=0;
    regle=new RegleJDLV();
    Grille* temp=new GrilleJDVL();
    temp->setLigne(this->getLigne());
    temp->setColonne(this->getColonne());
    temp->ini_grille();
    for (int i = 0; i < nb_ligne; i++) {
            for (int j = 0; j < nb_colonne; j++) {
                if (mode==1)
                {
                    cote= nb_cote_torique(i,j);
                }
                else
                {
                    cote= nb_cote(i,j);
                }
                if (tab[i][j]->GetEtat()) {                    
                    temp->getCell(i,j)->SetEtat(regle->Vivant(cote));
                } else {
                    temp->getCell(i,j)->SetEtat(regle->Morte(cote));
                }
            }
        }
    next =temp;
}


bool GrilleJDVL :: espaceDispo(int x, int y,  int surface_long, int surface_larg){
    // coordonnées de la surface dépassent du cadre
    if (x < 0 || y < 0 || x+surface_long > this->getLigne() || y+surface_larg > this->getColonne()) {
        return false;
    }
    
    // parcours de la surface, si une seul cellule est vivante alors l'espace est indisponible
    for (int i = 0; i<surface_long; i++) {
        for (int j = 0; j<surface_larg; j++) {
            if (this->getCell(y + j, x + i)->GetEtat() == true){
                return false;
            }
        }
    }
    return true;
};

void GrilleJDVL :: fusionGrille(Grille * ajout, int x, int y){      // /!\ ligne colonne 
    // colle la grille en paramètre aux coordonnées données sur l'entité fourni
    for (int i = 0; i < ajout->getLigne(); i++) {
        for (int j = 0; j < ajout->getColonne(); j++) {
            this->getCell(y + j, x + i)->SetEtat(ajout->getCell(j, i)->GetEtat());
        }
    }
}