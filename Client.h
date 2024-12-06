#pragma once
#include "JeuGraphique.h"
#include "JeuFichier.h"
class Client {
public:
    static int jouer() {
        JeuDeLaVie* jeu;

        // Choix du mode (fichier ou graphique) par exemple
        std::cout << "Choisissez le mode (1: Fichier, 2: Graphique): ";
        int choix;
        std::cin >> choix;
        /*std::cout << "rentrer le chemin du fichier ini: ";
        string chemin;
        std::cin >> chemin;*/
        if (choix == 1) {
        std::cout << "Choisissez le nombre d'iteration: ";
        int n;
        std::cin >> n;
            jeu = new JeuFichier(n,"Grille_ini.txt");
        } else {
            jeu = new JeuGraphique("Grille_ini.txt");
        }

        jeu->run();  // Démarrage du jeu
        delete jeu;  // Libération de la mémoire

        return 0;
    }
};
