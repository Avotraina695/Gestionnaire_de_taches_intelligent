//
// Created by avotra on 17/09/2026.
//
#include "../Include/Stockage.h"

#include <stdio.h>

void sauvegarderTaches(const TasTache * tas , char const nomFichier[]) {
    FILE *fichier = fopen(nomFichier, "w");
    if (fichier == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier !\n");
        return;
    }
    for (int i =  0 ; i < tas-> taille ; i++) {
        Tache temp = tas->tab[i];
        fprintf(fichier, "%d|%s|%s|%d|%d|%d\n",
                temp.id, temp.titre, temp.description, temp.priorite, temp.status, temp.ordreArrivee);
    }
    fclose(fichier);
    printf("Taches sauvegardees dans %s\n" , nomFichier);
}

void chargesTaches(TasTache * tas , char const nomFichier[]) {
    FILE * fichier = fopen(nomFichier , "r");
    if (fichier == NULL) {
        printf("Aucun fichier.\n");
        return;
    }
    int id, priorite, status, ordreArrivee;
    char titre[TAILLE_TITRE], description[TAILLE_DESCRIPTION];

    while (fscanf(fichier, "%d|%[^|]|%[^|]|%d|%d|%d\n",
                  &id, titre, description, &priorite, &status, &ordreArrivee) == 6) {
        ajouterTache(tas, id, titre, description, priorite, (Status)status);
                  }
    fclose(fichier);
    printf("Taches chargees depuis %s\n" , nomFichier);
}