#include "JeuGraphique.h"
#include "Affichage.h"

// Fonction principale de gestion du jeu avec une interface graphique
void JeuGraphique::run(){
    
    // Initialisation de l'état du jeu (par défaut "Run")
    string etat = "Run";
    
    // Création d'un objet FichierLire pour lire le fichier d'initialisation
    IFichier* f_ini = new FichierLire(chemin);
    
    // Création d'une grille vide (GrilleJDVL) et remplissage avec les données du fichier
    Grille *grille_ini = new GrilleJDVL();
    grille_ini = f_ini->Lire();

    // Création d'un objet Affichage pour gérer la fenêtre et l'affichage de la grille
    Affichage fenetre(grille_ini->getLigne(), grille_ini->getColonne(), 10, 1000);
    
    // Création de la fenêtre graphique avec SFML, en fonction de la taille de la grille
    sf::RenderWindow window(sf::VideoMode(fenetre.get_lo() * fenetre.get_size(), fenetre.get_la() * fenetre.get_size()), "Game of Life");
    
    // Création d'un rectangle pour représenter chaque cellule de la grille à afficher
    sf::RectangleShape cell(sf::Vector2f(10 - 1.0f, 10 - 1.0f));

    // Boucle principale du programme, qui s'exécute tant que la fenêtre est ouverte
    while (window.isOpen()) {
        
        // Gestion des événements comme les interactions avec la fenêtre (clics, touches, etc.)
        fenetre.event(grille_ini, window, f_ini, etat, cell);
        
        // Mise à jour de l'affichage avec la grille actuelle
        fenetre.actualise(grille_ini, window);
        // Mise à jour de la grille pour la génération suivante
        grille_ini->generationNext(mode);
        
        // Mise à jour de la grille courante avec la nouvelle grille générée
        grille_ini = grille_ini->getNext();
        
        // Pause entre chaque génération pour permettre à l'utilisateur de visualiser les changements
        sf::sleep(sf::milliseconds(fenetre.get_time()));
    }
    
    // Libération de la mémoire allouée pour la grille à la fin du programme
    delete grille_ini;
}
