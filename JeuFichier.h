#pragma once
#include "JeuDeLaVie.h"

class JeuFichier : public JeuDeLaVie
{
private:
    int n; //nombre d'iteration
    string chemin;
    int mode;
public:
    JeuFichier(int a, string chemin, int mode){
        this->n=a;
        this->chemin = chemin;
        this->mode = mode;
    }
    ~JeuFichier()override{}
    void run()override;
};

 