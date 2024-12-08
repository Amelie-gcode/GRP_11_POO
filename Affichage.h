#include "Lib.h"
#include "GrilleJDVL.h"
class Affichage
{
private:
    int largeur;
    int longueur;
    float tailleCell;
    int timeInterval;
public:
    Affichage(int lo, int la,float size, int time);
    Affichage();
    ~Affichage(){}
    int get_lo(){return longueur;}
    int get_la(){return largeur;}
    float get_size(){return tailleCell;}
    int get_time(){return timeInterval;}
    void actualise(Grille* grille,sf::RenderWindow &window);
    void event(Grille* grille_ini, sf::RenderWindow &window, IFichier *f_ini, string etat, sf::RectangleShape cell);
};
Affichage::Affichage(){
    longueur=80;
    largeur=80;
    tailleCell=10;
}
Affichage::Affichage(int la, int lo,float size, int time)
{
    longueur=lo;
    largeur=la;
    tailleCell=size;
    timeInterval = time;
}
void Affichage::actualise(Grille* grille, sf::RenderWindow &window)
{
    window.clear();  // Efface l'écran avant de redessiner l'affichage
    
    sf::RectangleShape cell(sf::Vector2f(tailleCell - 1.0f, tailleCell - 1.0f)); // Crée une cellule sous forme de rectangle
    // Boucle sur chaque cellule de la grille
    for (int x = 0; x < grille->getLigne(); ++x) {
        for (int y = 0; y < grille->getColonne(); ++y) {
            // Si la cellule est active (son état est vrai)
            if (grille->getCell(x, y)->GetEtat()) {
                cell.setPosition(y * tailleCell, x * tailleCell);  // Positionne la cellule sur la grille
                window.draw(cell);  // Dessine la cellule
            }
        }
    }
    window.display();  // Met à jour l'affichage de la fenêtre
}

void Affichage::event(Grille* grille_ini, sf::RenderWindow &window, IFichier *f_ini, string etat, sf::RectangleShape cell)
{
    sf::Event event;  // Déclare un objet pour gérer les événements
    // Boucle de gestion des événements de la fenêtre
    while (window.pollEvent(event)) {
        // Si la fenêtre est fermée
        if (event.type == sf::Event::Closed) {
            window.close();  // Ferme la fenêtre
        }

        // Si une touche du clavier est pressée
        if (event.type == sf::Event::KeyPressed)
        {
            // Si la touche 'Right' est pressée, réduit l'intervalle de temps
            if (event.key.code == sf::Keyboard::Right)
            {
                timeInterval -= 100;
            }
            // Si la touche 'Left' est pressée, augmente l'intervalle de temps
            if (event.key.code == sf::Keyboard::Left)
            {
                timeInterval += 100;
            }
            // Si la touche 'R' est pressée, recharge la grille à partir du fichier
            if (event.key.code == sf::Keyboard::R)
            {
                delete grille_ini;
                grille_ini = f_ini->Lire();  // Recharge la grille depuis le fichier
                actualise(grille_ini, window);

            }
            // Si la touche 'Delete' est pressée, efface l'écran
            if (event.key.code == sf::Keyboard::D) {
                
                for (int x = 0; x < grille_ini->getLigne(); ++x) {
                    for (int y = 0; y < grille_ini->getColonne(); ++y) {
                        grille_ini->getCell(x, y)->SetEtat(false);  // Met toutes les cellules à "morte"
                    }
                }
                actualise(grille_ini, window);

            }
            // Si la touche 'Space' est pressée, met le jeu en pause
            if (event.key.code == sf::Keyboard::Space)
            {
                etat = "Pause";  // Passe en mode pause
            }
            // Si la touche 'G' est pressée, passe en mode "Glider"
            if (event.key.code == sf::Keyboard::G)
            {
                etat = "Glider";  // Passe en mode glider
            }
            
            // Si le jeu est en pause, on attend que l'utilisateur appuie sur 'Space' pour continuer
            while (etat == "Pause")
            {
                while (window.pollEvent(event))
                {
                    // Si la fenêtre est fermée
                    if (event.type == sf::Event::Closed) {
                        window.close();  // Ferme la fenêtre
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        // Si la touche 'Space' est pressée, passe en mode "Run"
                        if (event.key.code == sf::Keyboard::Space)
                        {
                            etat = "Run";  // Passe en mode exécution
                        }
                        // Si la touche 'Delete' est pressée, efface l'écran
                        if (event.key.code == sf::Keyboard::Delete) {
                            window.clear();  // Efface la fenêtre
                            window.display();  // Met à jour la fenêtre
                        }
                    }
                    // Si un clic de souris est détecté
                    if (event.type == sf::Event::MouseButtonPressed) {
                        int x = event.mouseButton.x / 10;  // Calcule la position en x de la cellule sur la grille
                        int y = event.mouseButton.y / 10;  // Calcule la position en y de la cellule sur la grille
                        // Si le clic est sur le bouton gauche
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            grille_ini->getCell(y, x)->SetEtat(true);  // Active la cellule
                            cell.setPosition(x * 10, y * 10);  // Positionne la cellule
                            cell.setFillColor(sf::Color::White);  // Change la couleur de la cellule en blanc
                            window.draw(cell);  // Dessine la cellule
                            window.display();  // Met à jour la fenêtre
                        }
                        // Si le clic est sur le bouton droit
                        if (event.mouseButton.button == sf::Mouse::Right) {
                            grille_ini->getCell(y, x)->SetEtat(false);  // Désactive la cellule
                            cell.setPosition(x * 10, y * 10);  // Positionne la cellule
                            cell.setFillColor(sf::Color::Black);  // Change la couleur de la cellule en noir
                            window.draw(cell);  // Dessine la cellule
                            window.display();  // Met à jour la fenêtre
                        }
                    }
                }   
            }

            // Si le mode "Glider" est activé, permet de placer un glider
            while (etat == "Glider")
            {
                while (window.pollEvent(event))
                {
                    // Si la fenêtre est fermée
                    if (event.type == sf::Event::Closed) {
                        window.close();  // Ferme la fenêtre
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        // Si la touche 'Delete' est pressée, efface l'écran
                        if (event.key.code == sf::Keyboard::Delete) {
                            window.clear();  // Efface la fenêtre
                            window.display();  // Met à jour la fenêtre
                        }
                        // Si la touche 'G' est pressée, passe en mode "Run"
                        if (event.key.code == sf::Keyboard::G)
                        {
                            etat = "Run";  // Passe en mode exécution
                        }
                    }
                    // Si un clic de souris est détecté
                    if (event.type == sf::Event::MouseButtonPressed) {
                        int x = event.mouseButton.x / 10;  // Calcule la position en x de la cellule sur la grille
                        int y = event.mouseButton.y / 10;  // Calcule la position en y de la cellule sur la grille
                        // Si le clic est sur le bouton gauche
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            int x_min = x - 2;  // Calcule la position minimale pour le glider
                            int y_min = y - 2;  // Calcule la position minimale pour le glider
                            bool dispo = grille_ini->espaceDispo(x_min, y_min, 5, 5);  // Vérifie s'il y a de l'espace pour le glider
                            cout << "glider" << endl;
                            if (dispo == true) {
                                Grille *glider = new GrilleJDVL();  // Crée une nouvelle grille pour le glider
                                FichierLire f_Glider("Glider.txt");  // Ouvre le fichier du glider
                                glider = f_Glider.Lire();  // Charge le glider depuis le fichier
                                grille_ini->fusionGrille(glider, x_min, y_min);  // Fusionne le glider avec la grille principale
                                actualise(grille_ini, window);  // Met à jour l'affichage de la grille
                                cout << "glider2" << endl;
                            }
                        }
                    }   
                }
            }
        }
    }
}
