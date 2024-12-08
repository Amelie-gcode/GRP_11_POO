#include "test.h" 
void test(){
    FichierLire f_ini("Grille_test.txt");  // Fichier d'entrée (initial) avec les données de la grille
    FichierLire f_final("Grille_test_resultat.txt");  // Fichier de sortie attendu (résultat de la génération suivante)
    Grille *g = new GrilleJDVL();  // La grille initiale (chargée depuis le fichier d'entrée)
    Grille *g2 = new GrilleJDVL();  // La grille de comparaison (chargée depuis le fichier de résultat attendu)
    g = f_ini.Lire();  // Lecture de la grille depuis le fichier "Grille_test.txt"

    // Vérification que la taille de la grille est correcte (10 lignes, 5 colonnes)
    if (g->getLigne() == 10 && g->getColonne() == 5) {
        cout << "[OK] Lecture taille Grille fonctionnelle" << endl;  // Si la taille est correcte, on affiche un message de succès
    }
    else {
        cout << "[FAILURE] Lecture taille Grille non fonctionnelle" << endl;  // Si la taille est incorrecte, on affiche un message d'erreur
    }

    // Vérification que la cellule (0,0) et la cellule (9,4) sont initialement éteintes (état == 0)
    if (g->getCell(0, 0)->GetEtat() == 0 && g->getCell(9, 4)->GetEtat() == 0 ) {
        cout << "[OK] premier et dernier point valide" << endl;  // Si l'état est correct, on affiche un message de succès
    }
    else {
        cout << "[FAILURE] premier ou dernier point non valide" << endl;  // Si l'état est incorrect, on affiche un message d'erreur
    }
    g->generationNext(2);  // On passe à la génération suivante avec un mode spécifié (mode 2= grille non torique)
    g = g->getNext();  // La grille 'g' est mise à jour avec la grille suivante
    g2 = f_final.Lire();  // Lecture de la grille attendue dans "Grille_test_resultat.txt"

    // Vérification que la taille de la nouvelle grille est correcte après la génération suivante
    if (g->getLigne() == 10 && g->getColonne() == 5) {
        cout << "[OK] taille generation suivante fonctionne" << endl;  // Si la taille est correcte, on affiche un message de succès
    }
    else {
        cout << "[FAILURE] taille de la generation suivante non correcte" << endl;  // Si la taille est incorrecte, on affiche un message d'erreur
    }
    bool test = true;  // Flag qui indiquera si les tests sont passés
    // Parcours de toutes les cellules de la grille
    for (int i = 0; i < g->getLigne() && test; i++) {  // Parcours des lignes
        for (int j = 0; j < g->getColonne() && test; j++) {  // Parcours des colonnes
            // Si les états des cellules ne correspondent pas entre la grille actuelle et la grille de référence
            if (g->getCell(i, j)->GetEtat() != g2->getCell(i, j)->GetEtat()) {
                test = false;  // L'échec est signalé
                cout << "erreur cellule: " << i << ", " << j << endl;  // Affichage des indices de la cellule qui pose problème
            }
        }
    }
    if (test) {
        cout << "[OK] generation suivante fonctionne" << endl;  // Si tout est correct, on affiche un message de succès
    }
    else {
        cout << "[FAILURE] generation suivante défaillante" << endl;  // Si une erreur a été trouvée, on affiche un message d'erreur
    }
}
