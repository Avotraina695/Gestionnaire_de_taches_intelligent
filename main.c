
#include <stdio.h>
#include "Include/Tache.h"
#include "Include/Menu.h"

int main(void) {

    TasTache tas;
    initialiserTasTaches(&tas);

    /*
     * Données de démonstration
     * Priorité : 1 (faible) → 5 (urgente)
     */
    ajouterTache(&tas, 1,
                 "Revision C",
                 "Reviser les structures en C",
                 3, 0);

    ajouterTache(&tas, 2,
                 "Projet IGGL",
                 "Avancer sur le gestionnaire de taches",
                 5, 0);

    ajouterTache(&tas, 3,
                 "Algorithmique",
                 "Faire les exercices sur les graphes",
                 2, 0);

    ajouterTache(&tas, 4,
                 "Structures de donnees",
                 "Etudier les tas et files de priorite",
                 5, 0);

    ajouterTache(&tas, 5,
                 "Linux",
                 "Pratiquer les commandes du terminal",
                 4, 0);

    printf("\n========================================\n");
    printf("     GESTIONNAIRE DE TACHES INTELLIGENT\n");
    printf("========================================\n");

    printf("\nNombre de taches : %d\n", tas.taille);

    printf("\n--- Tache la plus prioritaire ---\n");

    if (tas.taille > 0) {
        Tache prioritaire = tas.tab[0];

        printf("ID        : %d\n", prioritaire.id);
        printf("Titre     : %s\n", prioritaire.titre);
        printf("Priorite  : %d\n", prioritaire.priorite);
        printf("Statut    : %d\n", prioritaire.status);
    }

    printf("\n--- Extraction des taches par priorite ---\n");

    while (tas.taille > 0) {

        Tache tache = extraireMax(&tas);

        printf("ID: %d | %-25s | Priorite: %d\n",
               tache.id,
               tache.titre,
               tache.priorite);
    }

    printf("\nToutes les taches ont ete traitees.\n");

    return 0;
}
