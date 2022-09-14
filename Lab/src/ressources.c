/*
 *  Création : Houssem Eddine Guezeri
 *  Révision : Francis Bourdeau
 *  Fichier  : ressources.h
 *  Cours    : ELE440
 *
 *
 *  Ce module contient des fonctions utilitaires employées dans le cadre
 *  d'un laboratoire sur l'analyse d'algorithmes.
 *
 *  Les services offerts sont les suivants:
 *
 *      - afficher        : Permet d'afficher le contenu d'un tableau.
 *
 *      - generer_donnees : Permet de créer un tableau de données selon une
 *                          plage de valeur et un niveau de désordre spécifié.
 *
 *      - sauvegarder     : Permet de sauvegarder le temps d'exécution
 *                          expérimental d'un algorithme dans un fichier txt.
 */
#include "ressources.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

/******************************************************************************/
/*                  DEFINITIONS DE TYPES ET DE CONSTANTES                     */
/******************************************************************************/

/******************************************************************************/
/*                  DÉCLARATION DES FONCTIONS PRIVÉES                         */
/******************************************************************************/

/*
 *  COMPARER_ENTIER
 *
 *  Cette fonction permet de comparer deux entiers tel que requis par
 *  stdlib::qsort
 *
 *  Paramètres:
 *      - a	: Le premier entier à comparer.
 *      - b	: Le second entier à comparer.
 *
 *  Retour :
 *      Une valeur < 0 lorsque a est inférieur à b
 *      Une valeur = 0 lorsque a est égale à b
 *      Une valeur > 0 lorsque a est supérieur à b
 */
static int comparer_entier(const void* a, const void* b);

/******************************************************************************/
/*                  IMPLÉMENTATIONS DES FONCTIONS PUBLIQUES                   */
/******************************************************************************/

//
// Permet d'afficher une section d'un tableau à la suite d'une note descriptive.
//
void afficher(char* note, int* un_tableau, int depart, int fin)
{
    int i;                              //Pour parcourir le tableau

    //On affiche la note descriptive
    printf("%s : ", note);

    //On affiche les données du tableau
    for (i = depart; i <= fin; i++)
    {
        printf("%i ", un_tableau[i]);
    }

    printf("\n");
}

//
// Permet de créer N données de rang K ayant un certain niveau de désordre D.
//
int* generer_donnees(int nb_donnees, int rang, int desordre)
{
    int* donnees;                   // Les données générées et leur position original.
    int* position;

    int i, temp;                    // Servira à trier les données générées.

    int m, k;                       // Servira à mélanger les données
    int indice, nb_permutation;

    // On initialise les tableaux
    nb_permutation = nb_donnees / 2;
    donnees = (int*) malloc(nb_donnees * sizeof(int));
    position = (int*) malloc(nb_permutation * sizeof(int));

    // On crée les données aléatoirement.
    for (i = 0; i < nb_donnees; i++)
        donnees[i] = rand() % rang;

    // On trie les données
    qsort(donnees, nb_donnees, sizeof(int), comparer_entier);

    // On initialise les positions des données triées.
    for (i = 0; i < nb_permutation; i++)
        position[i] = i;

    // On déplace les données pour créer le niveau de désordre spécifié.
    m = nb_permutation;
    for (i = 0; i < nb_permutation * desordre / 100; i++)
    {
        k = rand() % m;
        indice = position[k];
        position[k] = position[m - 1];
        m--;

        temp = donnees[nb_permutation - indice - 1];
        donnees[nb_permutation - indice - 1] = donnees[nb_permutation + indice];
        donnees[nb_permutation + indice] = temp;
    }

    free(position);
    return donnees;
}

//
// Permet d'ajouter une série de données au fichier reçu.
//
void sauvegarder(int nb_donnees, int rang, int desordre, double* temps_executions, int nb_temps, char* nom_fichier)
{
    FILE* fichier_id;
    int i;

    // On ouvre le fichier où inscrire les résultats
    fichier_id = fopen(nom_fichier, "a+");

    // On inscrit l'entête
    fprintf(fichier_id, "%d\n", nb_donnees);
    fprintf(fichier_id, "%d\n", rang);
    fprintf(fichier_id, "%d\n", desordre);

    // On inscrit les temps d'exécutions.
    for (i = 0; i < nb_temps; i++)
        fprintf(fichier_id, "%0.0lf ", temps_executions[i]);
    fprintf(fichier_id, "\n");

    // On ferme le fichier.
    fclose(fichier_id);
}

/******************************************************************************/
/*                  IMPLÉMENTATIONS DES FONCTIONS PRIVÉES                     */
/******************************************************************************/

//
// Compare a et b tel que requis par qsort.
//
static int comparer_entier(const void* a, const void* b)
{
    return (*(int*) a - *(int*) b);
}

