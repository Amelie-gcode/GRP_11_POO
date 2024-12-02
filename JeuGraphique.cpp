#include "JeuGraphique.h"
#include "Affichage.h"

void JeuGraphique :: run(){
    
    FichierLire f_ini(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();

    Affichage fenetre(grille_ini->getLigne(), grille_ini->getColonne(),10);

    sf::RenderWindow window(sf::VideoMode(fenetre.get_lo()* fenetre.get_size(), fenetre.get_la()* fenetre.get_size()), "Game of Life");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // Mise à jour de la grille et affichage
        fenetre.initialise(grille_ini, window);
        //grille_ini->generationNext();  // Mise à jour de la grille à la génération suivante
        //grille_ini = grille_ini->getNext();  // Assigner la nouvelle grille
        
        // Pause entre chaque génération pour visualiser les changements
        sf::sleep(sf::milliseconds(100));
    }
    
    
    /*for (int i = 0; i < n; i++)
    {
        cout <<"==============="<<endl;
        grille_ini->afficher();
        fenetre.initialise(grille_ini);
        grille_ini->generationNext();
        Grille* grille2= grille_ini->getNext();
        grille_ini=grille2;
    }
    */
}