#include "GrilleJDVL.h"

// Constructeur de GrilleJDVL : initialise une grille de 5x5 et une règle
GrilleJDVL::GrilleJDVL()
{
    nb_colonne = 5;  // Définit le nombre de colonnes de la grille
    nb_ligne = 5;    // Définit le nombre de lignes de la grille 
    ini_grille();    // Initialise la grille (alloue et configure les cellules)
}

// Destructeur de GrilleJDVL : libère la mémoire allouée pour chaque cellule
GrilleJDVL::~GrilleJDVL()
{
    for (int i = 0; i < nb_ligne; i++) {  // Parcours chaque ligne
        for (int j = 0; j < nb_colonne; j++) {  // Parcours chaque colonne
            delete tab[i][j];  // Libère la mémoire de chaque cellule
        }
    }
}

// Méthode pour initialiser la grille en allouant de la mémoire pour chaque cellule
void GrilleJDVL::ini_grille()
{
    // Alloue une grille de cellules de taille nb_ligne x nb_colonne
    tab = vector <vector<Cell*>>(nb_ligne, vector<Cell*>(nb_colonne));  
    // Parcours chaque ligne et colonne pour créer les cellules
    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonne; j++) {
            tab[i][j] = new Cell();  // Alloue une nouvelle cellule à chaque position
        }
    }
}

// Méthode pour afficher l'état des cellules dans la grille
void GrilleJDVL::afficher()
{
    for (int i = 0; i < nb_ligne; i++) {  // Parcours chaque ligne
        for (int j = 0; j < nb_colonne; j++) {  // Parcours chaque colonne
            cout << tab[i][j]->GetEtat() << "  ";  // Affiche l'état de chaque cellule
        }
        cout << " " << endl;  // Nouvelle ligne pour afficher la prochaine ligne de cellules
    }
}

// Méthode pour compter le nombre de voisins vivants autour d'une cellule (voisins directs)
int GrilleJDVL::nb_cote(int i, int j){
    int compt = 0;  // Compteur de voisins vivants
    // Parcours des voisins directs autour de la cellule (i, j)
    for (int k = i - 1; k <= i + 1; k++) {
        for (int q = j - 1; q <= j + 1; q++) {
            if (k >= 0 && k < nb_ligne && q >= 0 && q < nb_colonne && !(k == i && q == j)) {
                if (tab[k][q]->GetEtat()) {  // Si un voisin est vivant, on incrémente le compteur
                    compt++;
                }
            }
        }
    }
    return compt;  // Retourne le nombre de voisins vivants
}

// Méthode pour compter le nombre de voisins vivants autour d'une cellule avec toricité (voisins sur bords)
int GrilleJDVL::nb_cote_torique(int i, int j){
    int compt = 0;  // Compteur de voisins vivants
    // Parcours des voisins autour de la cellule (i, j), avec toricité
    for (int k = i - 1; k <= i + 1; k++) {
        for (int q = j - 1; q <= j + 1; q++) {
            if (!(k == i && q == j)) {
                int a  = (k + nb_ligne) % nb_ligne;  // Coordonnée avec toricité sur les lignes
                int b =  (q + nb_colonne) % nb_colonne;  // Coordonnée avec toricité sur les colonnes
                if (tab[a][b]->GetEtat()) {  // Si un voisin est vivant, on incrémente le compteur
                    compt++;
                }
            }
        }
    }
    return compt;  // Retourne le nombre de voisins vivants avec toricité
}

// Méthode pour générer l'état suivant de la grille en fonction des règles de vie
void GrilleJDVL::generationNext(int mode){
    int cote = 0;  // Variable pour stocker le nombre de voisins vivants
    regle = new RegleJDLV();  // Crée une nouvelle règle (probablement une règle spécifique pour ce type de grille)
    Grille* temp = new GrilleJDVL();  // Crée une nouvelle grille temporaire pour stocker le prochain état
    temp->setLigne(this->getLigne());  // Définit le nombre de lignes de la grille temporaire
    temp->setColonne(this->getColonne());  // Définit le nombre de colonnes de la grille temporaire
    temp->ini_grille();  // Initialise la grille temporaire

    // Parcours chaque cellule de la grille pour déterminer son état suivant
    for (int i = 0; i < nb_ligne; i++) {
        for (int j = 0; j < nb_colonne; j++) {
            if (mode == 1) {
                cote = nb_cote_torique(i, j);  // Utilise la fonction avec toricité si le mode est 1
            } else {
                cote = nb_cote(i, j);  // Sinon, utilise la fonction sans toricité
            }
            // Applique les règles de la grille pour déterminer l'état suivant de chaque cellule
            if (tab[i][j]->GetEtat()) {  
                temp->getCell(i, j)->SetEtat(regle->Vivant(cote));  // Si la cellule est vivante, applique la règle "Vivant"
            } else {
                temp->getCell(i, j)->SetEtat(regle->Morte(cote));  // Si la cellule est morte, applique la règle "Morte"
            }
        }
    }
    next = temp;  // Assigne la grille temporaire à la grille "next" pour la génération suivante
}

// Méthode pour vérifier si une surface de cellules peut être placée à une position donnée
bool GrilleJDVL::espaceDispo(int x, int y, int surface_long, int surface_larg){
    // Vérifie si les coordonnées de la surface dépassent les dimensions de la grille
    if (x < 0 || y < 0 || x + surface_long > this->getLigne() || y + surface_larg > this->getColonne()) {
        return false;  // Retourne false si la surface dépasse les bords de la grille
    }
    
    // Parcours chaque cellule de la surface pour vérifier si elle est disponible
    for (int i = 0; i < surface_long; i++) {
        for (int j = 0; j < surface_larg; j++) {
            if (this->getCell(y + j, x + i)->GetEtat() == true) {  // Si une cellule est vivante, l'espace est indisponible
                return false;
            }
        }
    }
    return true;  // Retourne true si l'espace est disponible
}

// Méthode pour fusionner une grille avec la grille courante à une position donnée
void GrilleJDVL::fusionGrille(Grille* ajout, int x, int y){
    // Parcours chaque cellule de la grille à ajouter et copie son état dans la grille actuelle
    for (int i = 0; i < ajout->getLigne(); i++) {
        for (int j = 0; j < ajout->getColonne(); j++) {
            this->getCell(y + j, x + i)->SetEtat(ajout->getCell(j, i)->GetEtat());  // Fusionne les cellules
        }
    }
}
