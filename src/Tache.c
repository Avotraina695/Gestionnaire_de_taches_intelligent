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
void ajouterTache(TasTache * tas , int id , char const titre[] , char const description[], int priorite , int status) {
    if (tas -> taille >= MAX) {
        printf("Ajout de tache impossible : le tas est plein.\n");
        return;
    }
    int i = tas -> taille;
    tas -> tab[i].id = id;
    tas -> tab[i].priorite = priorite;
    strncpy(tas->tab[i].titre, titre,
        sizeof(tas->tab[i].titre) - 1);
    tas->tab[i].titre[sizeof(tas->tab[i].titre) - 1] = '\0';

    strncpy(tas->tab[i].description, description,
            sizeof(tas->tab[i].description) - 1);
    tas->tab[i].description[sizeof(tas->tab[i].description) - 1] = '\0';
    tas -> tab[i].status = status;
    tas -> taille++;
    entasserHaut(tas , i );
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
        entasserHaut(tas , plusGrand);
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

    entasserBas(tas , 0);
    return racine;
}