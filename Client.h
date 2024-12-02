#include "JeuGraphique.h"

class Client {
public:
    static int jouer() {
        JeuDeLaVie* jeu;

        // Choix du mode (fichier ou graphique) par exemple
        std::cout << "rentrer le chemin du fichier ini: ";
        string chemin;
        std::cin >> chemin;
        std::cout << "Choisissez le mode (1: Fichier, 2: Graphique): ";
        int choix;
        std::cin >> choix;
        std::cout << "Choisissez le nombre d'iteration: ";
        int n;
        std::cin >> n;
        if (choix == 1) {
            jeu = new JeuFichier(n,chemin);
        } else {
            jeu = new JeuGraphique(n,chemin);
        }

        jeu->run();  // Démarrage du jeu
        delete jeu;  // Libération de la mémoire

        return 0;
    }
};
