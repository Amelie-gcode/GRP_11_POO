#include "JeuGraphique.h"


void JeuGraphique :: run(){
    
    FichierLire f_ini(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();

    for (int i = 0; i < n; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        grille_ini->generationNext();
        Grille* grille2= grille_ini->getNext();
        grille_ini=grille2;
    }
    
}