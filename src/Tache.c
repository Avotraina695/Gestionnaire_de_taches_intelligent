//
// Created by avotra on 15/09/2026.
//
#include "../Include/Tache.h"

#include <stdio.h>
#include <string.h>

void initialiserTasTaches(TasTache *tas) {
    tas -> taille = 0;
}

void echangerTache(Tache *a , Tache *b) {
    Tache temp = *a ;
    *a = *b;
    *b = temp;
}

int estPlusPriotitaire(Tache a , Tache b) {
    if (a.priorite > b.priorite) {
        return 1;
    }
    if (a.priorite == b.priorite && a.id < b.id) {
        return 1;
    }
    return 0;
}

void entasserHaut(TasTache * tas , int i) {
    if (i <= 0) return;
    int pere = (i -1)/ 2;
    if (estPlusPriotitaire(tas->tab[i] , tas->tab[pere])) {
        echangerTache(&tas->tab[i] , &tas->tab[pere]);
        entasserHaut(tas , pere);
    }
}
int ajouterTache(TasTache * tas , int id , char const titre[] , char const description[], int priorite , Status status) {
    if (tas -> taille >= MAX) {
        printf("Ajout de tache impossible : le tas est plein.\n");
        return 0;
    }
    if (priorite < 1 || priorite > 5) {
        printf("Erreur : la priorite doit etre comprise entre 1 et 5.\n");
        return 0;
    }
    if (rechercherTaches(tas , id) == 1) {
        printf("L'id doit etre unique a chaque tache.\n");
        return 0;
    }
    int i = tas -> taille;
    tas -> tab[i].id = id;
    tas -> tab[i].priorite = priorite;
    strncpy( tas->tab[i].titre, titre, TAILLE_TITRE - 1 ); tas->tab[i].titre[TAILLE_TITRE - 1] = '\0';
    strncpy( tas->tab[i].description, description, TAILLE_DESCRIPTION - 1 ); tas->tab[i].description[TAILLE_DESCRIPTION - 1] = '\0';
    tas -> tab[i].status = status;
    tas ->tab[i].ordreArrivee = tas -> prochaineOrdre;
    tas -> taille++;
    entasserHaut(tas , i );
    return 1;
}

void entasserBas(TasTache *tas , int i) {
    int plusGrand = i;
    int gauche = (2*i) + 1;
    int droite = (2*i) + 2;
    if (gauche < tas-> taille &&estPlusPriotitaire(tas->tab[gauche] , tas->tab[plusGrand])) {
        plusGrand = gauche;
    }
    if (droite < tas-> taille && estPlusPriotitaire(tas->tab[droite] , tas->tab[plusGrand])) {
        plusGrand = droite;
    }
    if (plusGrand != i) {
        echangerTache(&tas->tab[i] , &tas -> tab[plusGrand]);
        entasserBas(tas , plusGrand);
    }
}

Tache extraireMax (TasTache * tas) {
    if (tas -> taille <= 0) {
        printf("Aucune tâche disponible.\n");
        Tache vide = {-1, "" , "" , -1, -1};
        return vide;
    }
    Tache racine = tas->tab[0];
    tas->tab[0] = tas -> tab[tas->taille - 1];
    tas -> taille--;
    if (tas -> taille > 0) {
        entasserBas(tas , 0);
    }
    return racine;
}

void afficherTache(Tache tache) {
    printf("----------------------------------------\n");
    printf("ID : %d\n", tache.id);
    printf("Titre : %s\n", tache.titre);
    printf("Description : %s\n", tache.description);
    printf("Priorite : %d/5\n", tache.priorite);
    printf("Statut : ");
    switch (tache.status) {
        case A_FAIRE :
            printf("A faire\n");
            break;
        case EN_COURS :
            printf("En cours\n");
            break;
        case TERMINEE :
            printf("Terminee \n");
            break;
        default:
            printf("Inconnue\n");
            break;
    }
    printf("--------------------------------------------\n");
}
void afficherToutesLesTaches(TasTache *tas) {
    printf("\n===========Taches==========\n");
    if (tas -> taille <= 0) {
        printf("Aucune tache disponible.\n");
        return;
    }
    for (int i = 0 ; i < tas->taille ; i++) {
        Tache afficher = tas->tab[i];
        afficherTache(afficher);
    }
}

int rechercherTaches(TasTache *tas, int id) {
    if (tas->taille <= 0) {
        printf("Aucune tache disponible.\n");
        return -1;
    }
    for (int i = 0; i < tas->taille; i++) {
        if (tas->tab[i].id == id) {
            return i;
        }
    }
    return -1;
}

int modifierTache(TasTache *tas, int id, char const nouveauTitre[], char const nouvelleDescription[], int nouvellePriorite, Status nouveauStatus) {
    int indice = rechercherTaches(tas, id);
    if (indice == -1) {
        printf("Tache introuvable.\n");
        return 0;
    }

    tas->tab[indice].priorite = nouvellePriorite;
    strncpy(tas->tab[indice].titre, nouveauTitre, TAILLE_TITRE - 1);
    tas->tab[indice].titre[TAILLE_TITRE - 1] = '\0';
    strncpy(tas->tab[indice].description, nouvelleDescription, TAILLE_DESCRIPTION - 1);
    tas->tab[indice].description[TAILLE_DESCRIPTION - 1] = '\0';
    tas->tab[indice].status = nouveauStatus;
    return 1;
}