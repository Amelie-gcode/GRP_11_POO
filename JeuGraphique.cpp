#include "JeuGraphique.h"
#include "Affichage.h"

void JeuGraphique :: run(){
    
    string etat = "Run";
    IFichier* f_ini = new FichierLire(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini->Lire();

    Affichage fenetre(grille_ini->getLigne(), grille_ini->getColonne(),10, 1000);
 
    sf::RenderWindow window(sf::VideoMode(fenetre.get_lo()*fenetre.get_size(), fenetre.get_la()* fenetre.get_size()), "Game of Life");
    sf::RectangleShape cell(sf::Vector2f(10 - 1.0f, 10- 1.0f));

    while (window.isOpen()) {
        fenetre.actualise(grille_ini, window);        // Mise à jour de la grille et affichage
        fenetre.event(grille_ini,window, f_ini ,etat,cell);   //gere les evenements
        grille_ini->generationNext(mode);  // Mise à jour de la grille à la génération suivante
        grille_ini = grille_ini->getNext();  // Assigner la nouvelle grille
        sf::sleep(sf::milliseconds(fenetre.get_time())); // Pause entre chaque génération pour visualiser les changements
    }
    
    delete grille_ini;
};