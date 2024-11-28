#include "Cell.h"
class Grille
{
protected:
    vector <vector<Cell>> tab;
public:
    Grille(){}
    ~Grille(){}
    virtual void afficher()=0;
};

