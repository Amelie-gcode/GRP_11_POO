#include "FichierLire.h"
class FichierEcrire
{
private:
    ofstream f_out;
    string path;
    static int comp;
public:
    FichierEcrire(string p);
    ~FichierEcrire();
    void Ecrire(GrilleJDVL *grille);
    string genere_nom();
};
