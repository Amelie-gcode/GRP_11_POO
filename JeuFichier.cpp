#include "JeuFichier.h"

// Fonction principale de gestion du jeu, où tout le processus est exécuté
void JeuFichier::run(){
    
    // Création d'un objet FichierLire pour lire le fichier de départ
    FichierLire f_ini(chemin);
    
    // Création d'une grille vide (GrilleJDVL) qui sera remplie avec les données du fichier
    Grille *grille_ini = new GrilleJDVL();
    
    // Lecture du fichier d'initialisation et remplissage de la grille
    grille_ini = f_ini.Lire();
    
    // Création d'un objet FichierEcrire pour écrire les résultats dans un fichier de sortie
    FichierEcrire f_deux;

    // Boucle pour exécuter n itérations (générations du jeu)
    for (int i = 0; i < n; i++)
    {
        cout << "===============" << endl;  // Affiche un séparateur entre les générations
        
        // Affichage de l'état de la grille actuelle dans la console
        grille_ini->afficher();
        
        // Calcul et génération de l'état suivant de la grille (en fonction du mode)
        grille_ini->generationNext(mode);
        
        // Met à jour la grille actuelle avec la grille suivante (qui a été générée)
        grille_ini = grille_ini->getNext();
        
        cout << "===============" << endl;  // Affiche un séparateur après l'affichage de la génération
        
        // Écriture de l'état actuel de la grille dans un fichier de sortie
        f_deux.Ecrire(grille_ini);
    }

    // Libération de la mémoire allouée pour la grille une fois l'exécution terminée
    delete grille_ini;
}
