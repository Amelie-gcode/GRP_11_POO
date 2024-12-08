#include "JeuFichier.h"

void JeuFichier::run(){
    
    FichierLire f_ini(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();
    FichierEcrire f_deux;

    for (int i = 0; i < n; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        grille_ini->generationNext(mode);
        grille_ini= grille_ini->getNext();
        cout <<"==============="<<endl;
        f_deux.Ecrire(grille_ini);

    }
    delete grille_ini;
}