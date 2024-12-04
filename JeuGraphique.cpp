#include "JeuGraphique.h"
#include "Affichage.h"

void JeuGraphique :: run(){
    int timeInterval = 1000;
    bool inPause = false;
    FichierLire f_ini(chemin);
    Grille *grille_ini=new GrilleJDVL();
    grille_ini =f_ini.Lire();

    Affichage fenetre(grille_ini->getLigne(), grille_ini->getColonne(),10);
 
    sf::RenderWindow window(sf::VideoMode(fenetre.get_lo()*fenetre.get_size(), fenetre.get_la()* fenetre.get_size()), "Game of Life");
    sf::RectangleShape cell(sf::Vector2f(10 - 1.0f, 10- 1.0f));

    while (window.isOpen()) {
        
        
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
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
                if (event.key.code == sf::Keyboard::G)
                {
                    FichierLire f_G("G.txt");
                    grille_ini = f_G.Lire();
                }
                if (event.key.code == sf::Keyboard::Delete) {
                    window.clear();
                    window.display();
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
                        if (event.type == sf::Event::KeyPressed)
                        {
                            if (event.key.code == sf::Keyboard::Space)
                            {
                                inPause = false;
                            }
                            if (event.key.code == sf::Keyboard::Delete) {
                                window.clear();
                                window.display();
                            }
                        }
                        if (event.type == sf::Event::MouseButtonPressed) {
                            int x = event.mouseButton.x / 10;
                            int y = event.mouseButton.y / 10;

                            if (event.mouseButton.button == sf::Mouse::Left) {
                                grille_ini->getCell(y, x)->SetEtat(true);
                                cell.setPosition(x * 10, y * 10);
                                cell.setFillColor(sf::Color::White);
                                window.draw(cell);
                                window.display();
                            }
                            if (event.mouseButton.button == sf::Mouse::Right) {
                                grille_ini->getCell(y, x)->SetEtat(false);
                                cell.setPosition(x * 10, y * 10);
                                cell.setFillColor(sf::Color::Black);
                                window.draw(cell);
                                window.display();
                            }
                        }
                    }   
                }
            }
        }

        // Mise à jour de la grille et affichage
        fenetre.initialise(grille_ini, window);
        grille_ini->generationNext();  // Mise à jour de la grille à la génération suivante
        grille_ini = grille_ini->getNext();  // Assigner la nouvelle grille
        
        sf::sleep(sf::milliseconds(timeInterval));
        // Pause entre chaque génération pour visualiser les changements
        
    }
    
  delete grille_ini;
}