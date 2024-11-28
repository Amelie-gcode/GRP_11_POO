#include "FichierLire.h"


FichierLire::FichierLire(string chemin)
{
    path = chemin;
}

FichierLire::~FichierLire()
{
}

GrilleJDVL FichierLire ::Lire (GrilleJDVL GrilleIni){
    int valeur;
    
    f_in.open(path);
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
    }

    f_in >> valeur;
    GrilleIni.setLigne(valeur);
    f_in >> valeur;
    GrilleIni.setColonne(valeur);

    
    for (int i = 0; i < GrilleIni.getLigne(); i++)
    {
        for (int j = 0; j < GrilleIni.getColonne(); j++)
        {
            if (f_in >> valeur){ 
                GrilleIni.getCell(i,j).SetEtat(valeur);
            }
        }
    }
    
    f_in.close();
    return GrilleIni;
}