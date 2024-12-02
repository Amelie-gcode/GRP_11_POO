#include "Lib.h"

class Interface
{
private:
    sf::RenderWindow window;
    int largeur;
    int longueur;
    int tailleCell;
public:
    Interface(int lo, int la);
    ~Interface();
    void initialise();
    void actualise();
};

Interface::Interface(int lo, int la)
{
    longueur=lo;
    largeur=la;
    sf::RenderWindow window(sf::VideoMode(longueur*tailleCell, largeur*tailleCell), "JDLV");
}

void Interface::initialise()
{
}
