#include "JeuDeLaVie.h"
#pragma once
class JeuGraphique:public JeuDeLaVie
{
private:
    string chemin;
    int mode;
public:
    JeuGraphique(string chemin, int mode){
        this->chemin= chemin;
        this->mode=mode;
    }
    ~JeuGraphique()override{}
    void run()override;
};


