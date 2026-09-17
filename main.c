#include <stdio.h>

#include "Include/Tache.h"
#include "Include/Menu.h"



int main() {
    TasTache tas;
    initialiserTasTaches(&tas);

    int choix;
    do {
        menu();
        choix = choixMenu();
        getchar();

        switch (choix) {
            case 1: {
                int id, priorite;
                char titre[TAILLE_TITRE], description[TAILLE_DESCRIPTION];
                printf("ID de la tache : ");
                while (scanf("%d", &id) != 1) {
                    printf("Entree invalide, veuillez saisir un nombre : ");
                    while (getchar() != '\n');
                }
                getchar();
                printf("Titre : ");
                saisirLigne(titre, TAILLE_TITRE);

                printf("Description : ");
                saisirLigne(description, TAILLE_DESCRIPTION);

                do {
                    printf("Priorite (1-5) : ");
                    scanf("%d", &priorite);
                }while (priorite < 1 || priorite > 5);
                getchar();
                ajouterTache(&tas, id, titre, description, priorite, A_FAIRE);
                break;
            }
            case 2: // Afficher toutes les taches
                afficherToutesLesTaches(&tas);
                break;

            case 3: // Afficher la tache prioritaire (sans la retirer)
                if (tas.taille > 0) {
                    afficherTache(tas.tab[0]);
                } else {
                    printf("Aucune tache disponible.\n");
                }
                break;

            case 4: { // Executer (extraire) la tache prioritaire
                Tache t = extraireMax(&tas);
                if (t.id != -1) {
                    printf("Tache executee :\n");
                    afficherTache(t);
                }
                break;
            }
            case 5: { // Rechercher une tache
                int id;
                printf("ID a rechercher : ");
                while (scanf("%d", &id) != 1) {
                    printf("Entree invalide, veuillez saisir un nombre : ");
                    while (getchar() != '\n');
                }
                getchar();

                int indice = rechercherTaches(&tas, id);
                if (indice != -1) {
                    afficherTache(tas.tab[indice]);
                } else {
                    printf("Tache introuvable.\n");
                }
                break;
            }
            case 6: { // Modifier une tache
                int id, priorite , choixStatus;
                char titre[TAILLE_TITRE], description[TAILLE_DESCRIPTION];
                Status nouveauStatus;

                printf("ID de la tache a modifier : ");
                while (scanf("%d", &id) != 1) {
                    printf("Entree invalide, veuillez saisir un nombre : ");
                    while (getchar() != '\n');
                }
                getchar();
                printf("Nouveau titre : ");
                saisirLigne(titre, TAILLE_TITRE);

                printf("Nouvelle description : ");
                saisirLigne(description, TAILLE_DESCRIPTION);

                printf("Nouvelle priorite (1-5) : ");
                do {
                    while (scanf("%d", &priorite) != 1) {
                        printf("Entree invalide, veuillez saisir un nombre : ");
                        while (getchar() != '\n'); // vider le buffer
                    }
                }while (priorite < 1 || priorite > 5);
                getchar();
                printf("Nouveau status :\n ");
                printf("0 - A faire\n");
                printf("1 - En cours\n");
                printf("2 - Terminee\n");
                printf("Votre choix : ");
                do {
                    scanf("%d", &choixStatus);
                }while (choixStatus < 1 || choixStatus > 3);
                switch (choixStatus) {
                    case 1 : nouveauStatus = A_FAIRE; break;
                    case 2 : nouveauStatus =  EN_COURS; break;
                    case 3 : nouveauStatus =  TERMINEE; break;
                }

                modifierTache(&tas, id, titre, description, priorite, nouveauStatus);
                break;
            }
            case 7: // Supprimer une tache
                int id;
                printf("ID a supprimer :");
                while (scanf("%d", &id) != 1) {
                    printf("Entree invalide, veuillez saisir un nombre : ");
                    while (getchar() != '\n');
                }
                getchar();
                if (supprimerTache(&tas,id)) {
                    printf("Tache supprimer avec succes.\n");
                }
                break;

            case 8:
                printf("Au revoir !\n");
                break;
            default:
                printf("Erreur.\n");
        }

    } while (choix != 8);

    return 0;
}