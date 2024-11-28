#include "GrilleJDVL.h"

class FichierLire
{
private:
    ifstream f_in;
    string path; 
public:
    FichierLire(string chemin);
    ~FichierLire();
    GrilleJDVL Lire(GrilleJDVL tab);
};


