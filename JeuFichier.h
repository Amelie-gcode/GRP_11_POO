#pragma once
#include "JeuDeLaVie.h"

class JeuFichier : public JeuDeLaVie
{
private:
    int n; //nombre d'iteration
    string chemin;
public:
    JeuFichier(int a, string chemin){
        this->n=a;
        this->chemin=chemin;
    }
    ~JeuFichier()override{}
    void run()override;
};

