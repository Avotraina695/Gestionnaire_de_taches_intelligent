//
// Created by avotra on 15/09/2026.
//

#include "../Include/Menu.h"

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
    do {
        scanf("%d" , &choix);
    }while (choix < 1 || choix > 8);
    return choix;
}