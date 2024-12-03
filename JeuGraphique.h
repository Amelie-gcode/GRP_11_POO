#include "JeuFichier.h"
class JeuGraphique:public JeuDeLaVie
{
private:
    string chemin;
public:
    JeuGraphique(string chemin){
        this->chemin= chemin;
    }
    ~JeuGraphique(){}
    void run()override;
};


