#include "RegleJDLV.h"

// Fonction qui définit la règle de mort pour une cellule dans le jeu
bool RegleJDLV::Morte(int nb_cote)
{
    // Si une cellule a exactement 3 voisins vivants, elle devient vivante
    if (nb_cote == 3)
    {
        return true; // La cellule devient vivante
    }
    else 
        return false; // La cellule reste morte
}

// Fonction qui définit la règle de survie pour une cellule dans le jeu
bool RegleJDLV::Vivant(int nb_cote)
{
    // Une cellule survit si elle a 2 ou 3 voisins vivants
    if (nb_cote == 2 || nb_cote == 3)
    {
        return true; // La cellule reste vivante
    }
    else 
        return false; // La cellule meurt
}
