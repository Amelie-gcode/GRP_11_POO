#include "JeuGraphique.h"
#include "Affichage.h"

void JeuGraphique :: run(){
    int timeInterval = 1000;
    bool inPause = false;
    FichierLire f_ini("Grille_ini.txt");
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();

    Affichage fenetre(grille_ini->getLigne(), grille_ini->getColonne(),10);
 
    sf::RenderWindow window(sf::VideoMode(fenetre.get_lo()*fenetre.get_size(), fenetre.get_la()* fenetre.get_size()), "Game of Life");
    while (window.isOpen()) {
        
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grille_ini->getCell(x / 10, y / 10)->SetEtat(true);
                }
                if (event.mouseButton.button == sf::Mouse::Right) {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grille_ini->getCell(x / 10, y / 10)->SetEtat(false);
                }
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Right)
                {
                    timeInterval -= 100;
                }
                if (event.key.code == sf::Keyboard::Left)
                {
                    timeInterval += 100;
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    grille_ini = f_ini.Lire();
                }
                if (event.key.code == sf::Keyboard::Space)
                {
                    inPause = !inPause;
                }
                while (inPause)
                {
                    while (window.pollEvent(event))
                    {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                        }
                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
                        {
                            
                            inPause = false;
                        }   
                    }   
                }
            }
        }

        // Mise à jour de la grille et affichage
        fenetre.initialise(grille_ini, window);
        grille_ini->generationNext();  // Mise à jour de la grille à la génération suivante
        grille_ini = grille_ini->getNext();  // Assigner la nouvelle grille
        
        // Pause entre chaque génération pour visualiser les changements
        sf::sleep(sf::milliseconds(timeInterval));
        
    }
    
  
}