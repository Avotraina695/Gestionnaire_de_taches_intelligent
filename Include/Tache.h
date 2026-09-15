//
// Created by avotra on 15/09/2026.
//

#ifndef GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H
#define GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H
#define MAX 100

typedef struct {
    int id;
    char titre[100];
    char description[100];
    int priorite;
    int status;
}Tache;
typedef struct {
    Tache tab[MAX];
    int taille;
}TasTache;

void initialiserTasTaches(TasTache *tas);
void echangerTache(Tache *a , Tache *b);
int estPlusPriotitaire(Tache a , Tache b);
void entasserHaut(TasTache * tas , int i);
void entasserBas(TasTache *tas , int i);
void ajouterTache(TasTache * tas , int id , char const titre[] , char const description[] , int priorite , int status);
Tache extraireMax (TasTache * tas);


#endif //GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H