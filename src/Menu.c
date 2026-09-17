//
// Created by avotra on 15/09/2026.
//

#include "../Include/Menu.h"
#include <string.h>
#include <stdio.h>

void menu () {
    printf("===== GESTIONNAIRE DE TACHES =====\n");

    printf("1. Ajouter une tâche\n");
    printf("2. Afficher toutes les taches\n");
    printf( "3. Afficher la tache prioritaire\n");
    printf("4. Executer la tache prioritaire\n");
    printf("5. Rechercher une tache\n");
    printf("6. Modifier une tache\n");
    printf("7. Supprimer une tache\n");
    printf("8. Quitter\n");

    printf("Votre choix :\n");
}
int choixMenu() {
    int choix;
    while (scanf("%d", &choix) != 1) {
        printf("Entree invalide, veuillez saisir un nombre : ");
        while (getchar() != '\n');
    }
    return choix;
}
void saisirLigne(char *buffer, int taille) {
    fgets(buffer, taille, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}