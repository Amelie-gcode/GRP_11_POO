#include "FichierLire.h"
class FichierEcrire: public IFichier
{
private:
    static int comp;
public:
    FichierEcrire();
    ~FichierEcrire();
    void Ecrire(Grille *grille);
    string genere_nom();
};
