#include "Lib.h"
#include "GrilleJDVL.h"
class Affichage
{
private:
    int largeur;
    int longueur;
    float tailleCell;
public:
    Affichage(int lo, int la,float size);
    Affichage();
    ~Affichage(){}
    int get_lo(){return longueur;}
    int get_la(){return largeur;}
    float get_size(){return tailleCell;}
    void initialise(Grille* grille,sf::RenderWindow &window);
    void actualise(){}
    void event(sf::RenderWindow &window);
};
Affichage::Affichage(){
    longueur=80;
    largeur=80;
    tailleCell=10;
    //sf::RenderWindow window(sf::VideoMode(longueur*tailleCell, largeur*tailleCell), "JDLV");
}
Affichage::Affichage(int lo, int la,float size)
{
    longueur=lo;
    largeur=la;
    tailleCell=size;
    //sf::RenderWindow window(sf::VideoMode(longueur*tailleCell, largeur*tailleCell), "JDLV");
}
void Affichage:: event(sf::RenderWindow &window){
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
    }
}

void Affichage::initialise(Grille* grille,sf::RenderWindow &window)
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
