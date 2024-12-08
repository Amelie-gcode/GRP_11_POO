#include "FichierEcrire.h"

// Initialisation du compteur statique à 0
int FichierEcrire::comp = 0;


FichierEcrire::FichierEcrire()
{
    ofstream f_out;  
}

FichierEcrire::~FichierEcrire()
{
}

// Génère un nom de fichier unique en fonction du compteur statique
string FichierEcrire::genere_nom(){
    stringstream nomfichier;  // Utilisation d'un stringstream pour formater le nom du fichier
    comp++;  // Incrémente le compteur à chaque appel pour garantir des noms uniques
    nomfichier << "Grille_out" << comp << ".txt";  // Formate le nom du fichier
    return nomfichier.str();  // Retourne le nom généré
}

// Écrit l'état de la grille dans un fichier texte
void FichierEcrire::Ecrire(Grille* grille){
    // Ouvre un fichier en mode écriture avec le nom généré
    f_out.open(genere_nom(), std::ofstream::out);
    
    // Vérifie si le fichier s'est ouvert correctement
    if (!f_out.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en écriture : " << endl;
        return;  // Si le fichier ne peut pas être ouvert, on quitte la méthode
    }

    // Écrit les dimensions de la grille (nombre de lignes et de colonnes)
    f_out << grille->getLigne() << " " << grille->getColonne() << endl;
    
    // Parcours chaque cellule de la grille pour écrire son état
    for (int i = 0; i < grille->getLigne(); i++) {
        for (int j = 0; j < grille->getColonne(); j++) {
            // Écrit l'état de la cellule (0 ou 1) suivi d'un espace
            f_out << grille->getCell(i, j)->GetEtat(); 
            f_out << "  ";  // Ajoute un espacement entre les valeurs
        }
        f_out << endl;  // Nouvelle ligne après chaque ligne de la grille
    }

    // Ferme le fichier après l'écriture
    f_out.close(); 
}
