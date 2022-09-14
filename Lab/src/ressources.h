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
#ifndef __ELE440_LAB1_RESSOURCES__
#define __ELE440_LAB1_RESSOURCES__

/******************************************************************************/
/*                  DEFINITIONS DE TYPES ET DE CONSTANTES                     */
/******************************************************************************/

/******************************************************************************/
/*                  DÉCLARATION DES FONCTIONS PUBLIQUES                       */
/******************************************************************************/

/*
 *  AFFICHER
 *
 *  Cette fonction permet d'afficher une section d'un tableau de données
 *  en préfixant les valeurs d'une note informatrice.
 *
 *  Paramètres:
 *      - note       : Le texte à afficher avant les données.
 *      - un_tableau : Le tableau à afficher.
 *      - depart     : L'indice du premier élément à afficher.
 *      - fin        : L'indice du dernier élément à afficher.
 *
 *  Retour :
 *      Aucun.
 */
void afficher(char* note, int* un_tableau, int depart, int fin);

/*
 *  GENERER_DONNEES
 *
 *  Cette fonction gènère dynamiquement un tableau de données selon les
 *  caractéristiques transmises par l'utilisateur. L'utilisateur est
 *  responsable de libérer la mémoire allouée par cette fonction.
 *
 *  Paramètres:
 *      - nb_donnees: Le nb de données générées.
 *      - rang      : La valeur maximale pouvant être générée.
 *      - desordre  : Le niveau de désordre dans les données générées.
 *
 *  Retour :
 *      Un tableau de nb_entier généré aléatoirement.
 */
int* generer_donnees(int nb_donnees, int rang, int desordre);

/*
 *  SAUVEGARDER
 *
 *  Cette fonction ajoute à un fichier texte les données reçu.
 *  Le nb de données, le rang et le niveau de désordre seront inscrit
 *  en entête sur trois lignes distinctes alors que les mesures de performances
 *  seront placées à la suite, sur une seule ligne.
 *
 *  Paramètres:
 *      - nb_donnees        : Le nb de données générées.
 *      - rang              : La valeur maximale pouvant être générée.
 *      - desordre          : Le niveau de désordre dans les données générées.
 *      - temps_executions  : Les mesures à enregistrées dans le fichier.
 *      - nb_temps          : Le nb de mesures à enregistrées.
 *      - nom_fichier       : Le nom du fichier où les mesures seront
 *                            enregistrées.
 *
 *  Retour :
 *      Aucun.
 */
void sauvegarder(int nb_donnees, int rang, int desordre, double* temps_executions, int nb_temps, char* nom_fichier);

#endif
