#include "test.h"
void test(){

    FichierLire f_ini("Grille_test.txt");
    FichierLire f_final("Grille_test_resultat.txt");
    Grille *g=new GrilleJDVL();
    Grille *g2=new GrilleJDVL();
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

    g->generationNext(2);
    g = g->getNext();
    g2=f_final.Lire();
    
    
    if (g->getLigne() == 10 && g->getColonne() == 5) {
        cout << "[OK] taille generation suivante fonctionne" << endl;
    }
    else {
        cout << "[FAILURE] taille de la generation suivante non correcte" << endl;
    }
    bool test= true;
    for (int i = 0; i < g->getLigne() && test; i++)
    {
        for (int j = 0; j < g->getColonne() && test; j++)
        {
            if(g->getCell(i,j)->GetEtat() != g2->getCell(i,j)->GetEtat()){
                test = false;
                cout << "erreur celulle: "<< i << ", "<< j <<endl; 
            }
        }
    }
    if(test){
        cout << "[OK] generation suivante fonctionne" << endl;
    }
    else {
        cout << "[FAILURE] generation suivante defaillante" << endl;
    }
}
