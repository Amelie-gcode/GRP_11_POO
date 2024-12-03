#include "JeuFichier.h"
//#include "test.h"
void JeuFichier::run(){
    
    FichierLire f_ini(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();
    FichierEcrire f_deux;

    for (int i = 0; i < n; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        grille_ini->generationNext();
        Grille* grille2= grille_ini->getNext();
        cout <<"==============="<<endl;
        grille_ini=grille2;
        f_deux.Ecrire(grille_ini);

    }
    
}