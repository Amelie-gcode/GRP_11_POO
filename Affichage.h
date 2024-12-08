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

void Affichage::actualise(Grille* grille,sf::RenderWindow &window)
{
    window.clear();
    
     sf::RectangleShape cell(sf::Vector2f(tailleCell - 1.0f, tailleCell- 1.0f));
     for (int x = 0; x < grille->getLigne(); ++x) {
        for (int y = 0; y < grille->getColonne(); ++y) {
            if (grille->getCell(x,y)->GetEtat()) {
                cell.setPosition(y * tailleCell, x * tailleCell);
                window.draw(cell);
            }
        }
    }
    window.display();

}
void Affichage :: event(Grille* grille_ini, sf::RenderWindow &window, IFichier *f_ini, string etat, sf::RectangleShape cell){
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
                grille_ini = f_ini->Lire();
            }
            if (event.key.code == sf::Keyboard::Delete) {
                window.clear();
                window.display();
            }
            if (event.key.code == sf::Keyboard::Space)
            {
                etat = "Pause";
            }
            if (event.key.code == sf::Keyboard::G)
            {
                etat = "Glider";
            }
            
            while (etat == "Pause")
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
                            etat = "Run";
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
            while (etat == "Glider")
            {
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed) {
                        window.close();
                    }
                    if (event.type == sf::Event::KeyPressed)
                    {
                        if (event.key.code == sf::Keyboard::Delete) {
                            window.clear();
                            window.display();
                        }
                        if (event.key.code == sf::Keyboard::G)
                        {
                            etat = "Run";
                        }
                    }
                    if (event.type == sf::Event::MouseButtonPressed) {
                        
                        int x = event.mouseButton.x / 10;
                        int y = event.mouseButton.y / 10;
                        if (event.mouseButton.button == sf::Mouse::Left) {
                            int x_min = x - 2;
                            int y_min = y - 2;
                            bool dispo = grille_ini->espaceDispo(x_min, y_min, 5, 5);
                            cout<< "glider"<< endl;
                            if (dispo == true) {
                                Grille *glider=new GrilleJDVL();
                                FichierLire f_Glider("Glider.txt");
                                glider = f_Glider.Lire();  
                                grille_ini->fusionGrille(glider, x_min, y_min);
                                actualise(grille_ini, window);
                                cout<< "glider2"<< endl;
                            }
                        }
                    }   
                }
            }
        }
    }
}
