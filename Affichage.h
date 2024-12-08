#pragma once
#include "Lib.h"
#include "GrilleJDVL.h"
#include "FichierLire.h"
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
    ~Affichage();
    int get_lo(){return longueur;}
    int get_la(){return largeur;}
    float get_size(){return tailleCell;}
    int get_time(){return timeInterval;}
    void actualise(Grille* grille,sf::RenderWindow &window);
    void event(Grille* grille_ini, sf::RenderWindow &window, IFichier *f_ini, string etat, sf::RectangleShape cell);
};