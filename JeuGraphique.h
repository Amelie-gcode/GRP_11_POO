#include "JeuFichier.h"
class JeuGraphique:public JeuDeLaVie
{
private:
    int n; //nombre d'iteration
    string chemin;
public:
    JeuGraphique(int a,string chemin){
        this->n=a;
        this->chemin= chemin;
    }
    ~JeuGraphique(){}
    void run()override;
};


