#  Gestionnaire de tâches intelligent

Gestionnaire de tâches en **C** utilisant une **file de priorité basée sur un Max-Heap** pour organiser et exécuter les tâches selon leur niveau de priorité.

Ce projet a été réalisé dans le cadre de mon apprentissage de l'**algorithmique** et des **structures de données** en 2ᵉ année IGGL.

---

##  Présentation

L'objectif de ce projet est de développer un gestionnaire capable de :

*  Ajouter des tâches
*  Afficher les tâches
*  Identifier la tâche la plus prioritaire
* ️ Exécuter la tâche prioritaire
*  Rechercher une tâche par son ID
* ️ Modifier une tâche
* ️ Supprimer une tâche
*  Organiser automatiquement les tâches grâce à un **Max-Heap**

Chaque tâche possède notamment :

* un identifiant unique
* un titre
* une description
* une priorité de `1` à `5`
* un statut
* un ordre d'arrivée

---

##  Structure de données utilisée

### Max-Heap

Le cœur du projet repose sur un **Max-Heap**.

La tâche ayant la priorité la plus élevée se trouve toujours à la racine du tas.

```text
                 Tâche P5
                /        \
             Tâche P4   Tâche P3
             /    \
          P2      P1
```

Lorsqu'une nouvelle tâche est ajoutée, le Max-Heap est réorganisé automatiquement.

Lorsqu'une tâche prioritaire est exécutée, elle est extraite du tas puis le tas est réorganisé.

### Critère de priorité

Deux critères sont utilisés :

1. La priorité de la tâche.
2. En cas d'égalité, l'ordre d'arrivée.

Ainsi, si deux tâches ont la même priorité, la tâche arrivée en premier est exécutée en premier.

---

## ️ Fonctionnalités

| Fonctionnalité | Description                                 |
| -------------- | ------------------------------------------- |
| Ajouter        | Ajoute une nouvelle tâche                   |
| Afficher       | Affiche toutes les tâches présentes         |
| Prioritaire    | Affiche la tâche ayant la priorité maximale |
| Exécuter       | Extrait la tâche prioritaire                |
| Rechercher     | Recherche une tâche grâce à son ID          |
| Modifier       | Modifie les informations d'une tâche        |
| Supprimer      | Supprime une tâche                          |
| Quitter        | Ferme le programme                          |

---

##  Organisation du projet

```text
Gestionnaire_de_taches_intelligent/
│
├── CMakeLists.txt
├── README.md
├── main.c
│
├── Include/
│   ├── Tache.h
│   └── Menu.h
│
├── src/
│   ├── Tache.c
│   └── Menu.c
│
└── cmake-build-debug/
```

> `cmake-build-debug/` est un dossier généré par CLion et ne devrait normalement pas être envoyé sur GitHub. Il est recommandé de l'ajouter au `.gitignore`.

---

## 🛠️ Technologies utilisées

* **Langage :** C
* **Standard :** C11
* **Build :** CMake
* **IDE :** CLion
* **Système :** Linux / Fedora
* **Structure de données :** Max-Heap
* **Concepts :**

  * structures (`struct`)
  * énumérations (`enum`)
  * pointeurs
  * tableaux
  * fonctions
  * récursivité
  * gestion dynamique de la priorité
  * algorithmique

---

## 🚀 Compilation

### Avec CMake

Depuis la racine du projet :

```bash
mkdir -p cmake-build-debug
cd cmake-build-debug
cmake ..
make
```

Puis :

```bash
./Gestionnaire_de_taches_intelligent
```

### Compilation directe avec GCC

Il est également possible de compiler le projet avec :

```bash
gcc main.c src/Tache.c src/Menu.c -o gestionnaire
```

Puis :

```bash
./gestionnaire
```

---

## 💻 Exemple d'utilisation

```text
========================================
       GESTIONNAIRE DE TACHES
========================================
1. Ajouter une tache
2. Afficher toutes les taches
3. Afficher la tache prioritaire
4. Executer la tache prioritaire
5. Rechercher une tache
6. Modifier une tache
7. Supprimer une tache
8. Quitter
========================================
Votre choix :
```

Exemple de tâches :

```text
ID  Titre                  Priorité
1   Réviser le C              5
2   Faire le rapport          3
3   Lire le cours             2
4   Projet algorithmique      5
```

Le Max-Heap sélectionnera en priorité une tâche de niveau **5**.

Si plusieurs tâches ont la même priorité, l'ordre d'arrivée permet de les départager.

---

## ⏱️ Complexité algorithmique

Pour un Max-Heap contenant `n` tâches :

| Opération                      |                                         Complexité |
| ------------------------------ | -------------------------------------------------: |
| Consulter la tâche prioritaire |                                           **O(1)** |
| Ajouter une tâche              |                                       **O(log n)** |
| Extraire la tâche prioritaire  |                                       **O(log n)** |
| Rechercher par ID              |                                           **O(n)** |
| Supprimer une tâche            | **O(n)** pour la recherche + réorganisation du tas |
| Modifier une tâche             |        **O(n)** pour la recherche + réorganisation |

Cette organisation permet donc de gérer efficacement les opérations liées à la **priorité**.

---

##  Améliorations prévues

Le projet pourra évoluer vers une version plus intelligente avec :

*  ajout des deadlines
*  calcul automatique de l'urgence
*  calcul d'un score intelligent
*  priorité dynamique
*  table de hachage pour accélérer la recherche par ID
*  sauvegarde des tâches dans un fichier
*  statistiques sur les tâches
* ️ interface graphique

Une évolution possible serait notamment :

```text
              Gestionnaire intelligent
                       │
              ┌────────┴────────┐
              ↓                 ↓
         Table de hachage    Max-Heap
         Recherche par ID    Priorité
              │                 │
              └────────┬────────┘
                       ↓
                  Tâche optimale
```

---

## 🎯 Objectifs pédagogiques

Ce projet permet de mettre en pratique :

* la conception d'une structure de données
* les arbres binaires sous forme de tas
* les algorithmes de réorganisation d'un tas
* les fonctions récursives
* la manipulation de structures en C
* la gestion des pointeurs
* l'analyse de complexité
* l'organisation d'un projet C avec plusieurs fichiers
* l'utilisation de **CMake**
* l'utilisation de **Git et GitHub**

---

## Auteur

**Projet universitaire — 2ᵉ année IGGL**

Développé en **C** dans le cadre de l'apprentissage de l'algorithmique et des structures de données.

---

##  Licence

Ce projet est destiné principalement à des fins **éducatives et académiques**.
