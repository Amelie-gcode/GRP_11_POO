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
        std::cout << "rentrer le chemin du fichier ini: ";
        string chemin;
        std::cin >> chemin;
        std::cout << "Voulez vous une grille torique ? 1: oui 2: non";
        int torique;
        std::cin >> torique;
        if (choix == 1) {
        std::cout << "Choisissez le nombre d'iteration: ";
        int n;
        std::cin >> n;
            jeu = new JeuFichier(n,chemin,torique);   // creation du jeu en fonction du choix
        } else {
            jeu = new JeuGraphique(chemin, torique);
        }

        jeu->run();  // Démarrage du jeu
        delete jeu;  // Libération de la mémoire

        return 0;
    }
};
