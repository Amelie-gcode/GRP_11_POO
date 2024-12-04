#include "test.h"
void test(){

    FichierLire f_ini("Grille_test.txt");
    Grille *g=new GrilleJDVL();
    g =f_ini.Lire();

    if (g->getLigne() == 10 && g->getColonne() == 5) {
        cout << "[OK] Lecture taille Grille fonctionnelle" << endl;
    }
    else {
        cout << "[FAILURE] Lecture taille Grille non fonctionnelle" << endl;
    }
    if (g->getCell(0,0)->GetEtat() == 0 && g->getCell(9,4)->GetEtat() == 0 ) {
        cout << "[OK] premier et dernier point valide" << endl;
    }
    else {
        cout << "[FAILURE] premier ou dernier point non valide" << endl;
    }

    g->generationNext();
    g = g->getNext();

    
    if (g->getLigne() == 10 && g->getColonne() == 5) {
        cout << "[OK] taille generation suivante fonctionne" << endl;
    }
    else {
        cout << "[FAILURE] taille de la generation suivante non corecte" << endl;
    }

    if (g->getCell(2,3)->GetEtat() == 0 && g->getCell(6,1)->GetEtat() == 1) {
        cout << "[OK] generation suivante fonctionne" << endl;
    }
    else {
        cout << "[FAILURE] generation suivante defaillante" << endl;
    }
}
