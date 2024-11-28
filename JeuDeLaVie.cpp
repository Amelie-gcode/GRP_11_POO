#include "FichierEcrire.h"


void run(){
    
    FichierLire f_ini("/wsl.localhost/Ubuntu-22.04/home/game/GRP_11_POO/GRP_11_POO/Grille_ini.txt");
    cout <<"test";
    GrilleJDVL *grille_ini;
    grille_ini =f_ini.Lire();
    for (int i = 0; i < 1; i++)
    {
        grille_ini->afficher();
        GrilleJDVL* grille2= grille_ini->getNext();
        delete grille_ini;
        grille_ini=grille2;
        delete grille2;
    }
    
}
int main(){
    cout<<"test1";
    run();
    return 0;

}
