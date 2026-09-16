#include <stdio.h>
#include <string.h>
#include "Include/Tache.h"
#include "Include/Menu.h"


void saisirLigne(char *buffer, int taille) {
    fgets(buffer, taille, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

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
                scanf("%d", &id);
                getchar();

                printf("Titre : ");
                saisirLigne(titre, TAILLE_TITRE);

                printf("Description : ");
                saisirLigne(description, TAILLE_DESCRIPTION);

                printf("Priorite (1-5) : ");
                scanf("%d", &priorite);
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
                scanf("%d", &id);
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
                int id, priorite;
                char titre[TAILLE_TITRE], description[TAILLE_DESCRIPTION];

                printf("ID de la tache a modifier : ");
                scanf("%d", &id);
                getchar();

                printf("Nouveau titre : ");
                saisirLigne(titre, TAILLE_TITRE);

                printf("Nouvelle description : ");
                saisirLigne(description, TAILLE_DESCRIPTION);

                printf("Nouvelle priorite (1-5) : ");
                scanf("%d", &priorite);
                getchar();

                modifierTache(&tas, id, titre, description, priorite, A_FAIRE);
                break;
            }
            case 7: // Supprimer une tache
                printf("Fonction pas encore implementee.\n");
                break;

            case 8:
                printf("Au revoir !\n");
                break;
        }

    } while (choix != 8);

    return 0;
}