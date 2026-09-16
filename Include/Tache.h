//
// Created by avotra on 15/09/2026.
//

#ifndef GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H
#define GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H
#define MAX 100
#define TAILLE_TITRE  100
#define TAILLE_DESCRIPTION 200

typedef enum {
    A_FAIRE = 0,
    EN_COURS = 1,
    TERMINEE = 2,
}Status;

typedef struct {
    int id;
    char titre[TAILLE_TITRE];
    char description[TAILLE_DESCRIPTION];
    int priorite;
    Status status;
    int ordreArrivee;
}Tache;
typedef struct {
    Tache tab[MAX];
    int taille;
    int prochaineOrdre;
}TasTache;

void initialiserTasTaches(TasTache *tas);
void echangerTache(Tache *a , Tache *b);
int estPlusPriotitaire(Tache a , Tache b);
void entasserHaut(TasTache * tas , int i);
void entasserBas(TasTache *tas , int i);
int ajouterTache(TasTache * tas , int id , char const titre[] , char const description[] , int priorite , Status status);
Tache extraireMax (TasTache *tas);
void afficherTache(Tache tache);
int modifierTache(TasTache *tas, int id, char const nouveauTitre[], char const nouvelleDescription[], int nouvellePriorite, Status nouveauStatus) ;
int rechercherTaches(TasTache *tas , int id);
void afficherToutesLesTaches(TasTache *tas);

#endif //GESTIONNAIRE_DE_TACHES_INTELLIGENT_TACHE_H