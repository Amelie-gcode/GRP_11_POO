#include "FichierLire.h"

// Constructeur qui initialise le chemin du fichier
FichierLire::FichierLire(string chemin)
{
    path = chemin;  // Définit le chemin du fichier à lire
    ifstream f_in;  // Déclare un flux d'entrée pour la lecture du fichier
}

FichierLire::~FichierLire()
{
}

// Méthode pour lire un fichier et initialiser une grille à partir de ce fichier
Grille* FichierLire::Lire(){
    Grille* GrilleIni;  // Déclare un pointeur pour la grille qui sera retournée
    GrilleIni = new GrilleJDVL();  // Crée une nouvelle instance de GrilleJDVL (sous-classe de Grille)
    int valeur;  // Variable pour stocker les valeurs lues du fichier
    
    // Ouvre le fichier en mode lecture
    f_in.open(path, std::ios::in);

    // Vérifie si le fichier s'est ouvert correctement
    if (!f_in.is_open()) {
        cerr << "Erreur : impossible d'ouvrir le fichier en lecture : " << path << endl;
        return nullptr;  // Retourne un pointeur nul si l'ouverture échoue
    }

    // Lit le nombre de lignes et de colonnes du fichier et les affecte à la grille
    f_in >> valeur;  // Lit le nombre de lignes
    GrilleIni->setLigne(valeur);  // Définit le nombre de lignes de la grille
    f_in >> valeur;  // Lit le nombre de colonnes
    GrilleIni->setColonne(valeur);  // Définit le nombre de colonnes de la grille
    GrilleIni->ini_grille();  // Initialise la grille (probablement pour créer un tableau de cellules)

    // Lit l'état des cellules de la grille depuis le fichier
    for (int i = 0; i < GrilleIni->getLigne(); i++) {
        for (int j = 0; j < GrilleIni->getColonne(); j++) {
            if (f_in >> valeur){  // Si une valeur peut être lue (état de la cellule)
                GrilleIni->getCell(i, j)->SetEtat(valeur);  // Affecte l'état de la cellule
            }
        }
    }

    // Ferme le fichier après lecture
    f_in.close();

    // Retourne la grille initialisée avec les valeurs lues depuis le fichier
    return GrilleIni;
}
