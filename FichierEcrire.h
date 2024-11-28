#include "GrilleJDVL.h"
class FichierEcrire
{
private:
    ofstream f_out;
    string path;
public:
    FichierEcrire(string p);
    ~FichierEcrire();
    void Ecrire(GrilleJDVL grille);
};
