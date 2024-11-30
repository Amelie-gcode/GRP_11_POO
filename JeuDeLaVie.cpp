#include "FichierEcrire.h"


void run(){
    
    FichierLire f_ini("Grille_ini.txt");
    GrilleJDVL *grille_ini=new GrilleJDVL();

    grille_ini->afficher();
    cout <<"==============="<<endl;
    grille_ini =f_ini.Lire();
    FichierEcrire f_deux("Grille_out.txt");

    for (int i = 0; i < 4; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        grille_ini->generationNext();
        GrilleJDVL* grille2= grille_ini->getNext();
        cout <<"==============="<<endl;
        grille_ini=grille2;
        f_deux.Ecrire(grille_ini);

    }
    
}
int main(){
    run();
    return 0;

}
