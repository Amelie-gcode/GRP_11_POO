#include "FichierEcrire.h"


void run(){
    FichierLire f_ini("Grille_ini.txt");
    GrilleJDVL *grille_ini;
    grille_ini =f_ini.Lire();
    for (int i = 0; i < 2; i++)
    {
        grille_ini->afficher();
        GrilleJDVL* grille2= grille_ini->getNext();
        delete grille_ini;
        grille_ini=grille2;
        delete grille2;
    }
    
}
int main(){

    run();
    return 0;

}
