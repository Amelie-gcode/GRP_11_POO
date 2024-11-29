#include "FichierEcrire.h"


void run(){
    
    FichierLire f_ini("/home/game/GRP_11_POO/GRP_11_POO/Grille_ini.txt");
    cout <<"test"<<endl;
    GrilleJDVL *grille_ini=new GrilleJDVL();

    grille_ini->afficher();
    cout <<"==============="<<endl;
    grille_ini =f_ini.Lire();

    for (int i = 0; i < 3; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        grille_ini->generationNext();
        GrilleJDVL* grille2= grille_ini->getNext();
        grille_ini=grille2;
    }
    
}
int main(){
    cout<<"test1";
    run();
    return 0;

}
