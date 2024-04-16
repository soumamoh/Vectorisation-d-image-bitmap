#ifndef __SEQENCE_H__
#define __SEQENCE_H__

#include "geom2d.h"
#include "types_macros.h"

typedef struct Tableau_Point_ 
{
	unsigned int taille;
	Point *tab;
}Tableau_Point;


// Le type cellule de segment

typedef struct Cellule_Liste_Segment_ {
	Segment S;
	struct Cellule_Liste_Segment_ *suiv;
}Cellule_Liste_Segment;

// Le type cellule de bezier2

typedef struct Cellule_Liste_Bezier2_ {
	Bezier2 B;
	struct Cellule_Liste_Bezier2_ *suiv;
}Cellule_Liste_Bezier2;

// Le type cellule de bezier3

typedef struct Cellule_Liste_Bezier3_ {
	Bezier3 B;
	struct Cellule_Liste_Bezier3_ *suiv;
}Cellule_Liste_Bezier3;

// Le type liste de bezier2

typedef struct Liste_Bezier2_ {
	UINT taille;
	Cellule_Liste_Bezier2 *first;
	Cellule_Liste_Bezier2 *last;
}Liste_Bezier2;

// Le type liste de bezier3

typedef struct Liste_Bezier3_ {
	UINT taille;
	Cellule_Liste_Bezier3 *first;
	Cellule_Liste_Bezier3 *last;
}Liste_Bezier3;

// Le type liste de segment

typedef struct Liste_Segment_ {
	UINT taille;
	Cellule_Liste_Segment *first;
	Cellule_Liste_Segment *last;
}Liste_Segment;

// Le type cellule de point 

typedef struct Cellule_Liste_Point_ {
	Point data;
	struct Cellule_Liste_Point_ *suiv;
} Cellule_Liste_Point;

// Le type liste de point

typedef struct Liste_Point_ {
	UINT taille;
	Cellule_Liste_Point *first;
	Cellule_Liste_Point *last;
}Liste_Point;

// Le type liste de liste de segment

typedef struct Cellule_Liste_Liste_Segment_ {
	Liste_Segment Liste;
	struct Cellule_Liste_Liste_Segment_ *suiv;
}Cellule_Liste_Liste_Segment;

typedef struct Liste_Liste_Segment_ {
	UINT taille;
	Cellule_Liste_Liste_Segment *Lfirst;
	Cellule_Liste_Liste_Segment *Llast;
}Liste_Liste_Segment;

// Le type liste de liste de Bezier2

typedef struct Cellule_Liste_Liste_Bezier2_ {
	Liste_Bezier2 Liste;
	struct Cellule_Liste_Liste_Bezier2_ *suiv;
}Cellule_Liste_Liste_Bezier2;

typedef struct Liste_Liste_Bezier2_ {
	UINT taille;
	Cellule_Liste_Liste_Bezier2 *Lfirst;
	Cellule_Liste_Liste_Bezier2 *Llast;
}Liste_Liste_Bezier2;

// Le type liste de liste de Bezier3

typedef struct Cellule_Liste_Liste_Bezier3_ {
	Liste_Bezier3 Liste;
	struct Cellule_Liste_Liste_Bezier3_ *suiv;
}Cellule_Liste_Liste_Bezier3;

typedef struct Liste_Liste_Bezier3_ {
	UINT taille;
	Cellule_Liste_Liste_Bezier3 *Lfirst;
	Cellule_Liste_Liste_Bezier3 *Llast;
}Liste_Liste_Bezier3;

// Le type liste de liste de point

typedef struct Cellule_Liste_Liste_Point_ {
	Liste_Point Liste;
	struct Cellule_Liste_Liste_Point_ *suiv;
}Cellule_Liste_Liste_Point;

typedef struct Liste_Liste_Point_ {
	UINT taille;
	Cellule_Liste_Liste_Point *Lfirst;
	Cellule_Liste_Liste_Point *Llast;
}Liste_Liste_Point;


typedef Liste_Point Contour;

typedef Liste_Liste_Point Liste_Contour;

typedef Liste_Liste_Segment Liste_Contour_Segment;

typedef Liste_Liste_Bezier2 Liste_Contour_Bezier2;

typedef Liste_Liste_Bezier3 Liste_Contour_Bezier3;

/* Verifier si la liste est vide */
int est_liste_vide_bezier3 (Liste_Bezier3 );

/* Verifier si la liste est vide */
int est_liste_vide_bezier2 (Liste_Bezier2 );

/* Verifier si la liste est vide */
int est_liste_vide_segment (Liste_Segment );

/* Verifier si la liste est vide */
int est_liste_vide_point (Liste_Point );

/* Verifier si la liste de liste est vide */
int est_liste_liste_vide (Liste_Liste_Point );

/* Verifier si la liste de contour segment est vide */
int est_liste_liste_segment_vide (Liste_Contour_Segment );

/* Verifier si la liste de contour bezier2 est vide */
int est_liste_liste_bezier2_vide (Liste_Contour_Bezier2 );

/* Verifier si la liste de contour bezier3 est vide */
int est_liste_liste_bezier3_vide (Liste_Contour_Bezier3 );

/* creer une cellule de liste avec l'element v renvoie le pointeur 
 * sur la cellule de la liste de bezier3 creee la fonction s'arrete si la 
 * fonction n'a pas pu se faire */
Cellule_Liste_Bezier3 *creer_element_liste_Bezier3 (Bezier3 );

/* creer une cellule de liste avec l'element v renvoie le pointeur 
 * sur la cellule de la liste de bezier2 creee la fonction s'arrete si la 
 * fonction n'a pas pu se faire */
Cellule_Liste_Bezier2 *creer_element_liste_Bezier2 (Bezier2 );

/* creer une cellule de liste avec l'element v renvoie le pointeur 
 * sur la cellule de la liste de segment creee la fonction s'arrete si la 
 * fonction n'a pas pu se faire */
Cellule_Liste_Segment *creer_element_liste_Segment (Segment );

/* creer une cellule de liste avec l'element v renvoie le pointeur 
 * sur la cellule de la liste de point creee la fonction s'arrete si la 
 * fonction n'a pas pu se faire */
Cellule_Liste_Point *creer_element_liste_Point (Point );

/* creer une cellule de liste avec la liste L renvoie le pointeur
 * sur la cellule de la liste creee la fonction s'arrete si la
 * fonction n'a pas pu se faire */

Cellule_Liste_Liste_Point *creer_element_liste_liste_Point (Liste_Point );

/* creer une cellule de liste avec la liste L renvoie le pointeur
 * sur la cellule de la liste creee la fonction s'arrete si la
 * fonction n'a pas pu se faire */

Cellule_Liste_Liste_Segment *creer_element_liste_liste_Segment (Liste_Segment );

/* creer une cellule de liste avec la liste L renvoie le pointeur
 * sur la cellule de la liste creee la fonction s'arrete si la
 * fonction n'a pas pu se faire */

Cellule_Liste_Liste_Bezier2 *creer_element_liste_liste_Bezier2 (Liste_Bezier2 );

/* creer une cellule de liste avec la liste L renvoie le pointeur
 * sur la cellule de la liste creee la fonction s'arrete si la
 * fonction n'a pas pu se faire */

Cellule_Liste_Liste_Bezier3 *creer_element_liste_liste_Bezier3 (Liste_Bezier3 );

/* creer une liste de bezier3 vide */
Liste_Bezier3 creer_liste_Bezier3_vide ();

/* creer une liste de bezier2 vide */
Liste_Bezier2 creer_liste_Bezier2_vide ();

/* creer une liste de segment vide */
Liste_Segment creer_liste_Segment_vide ();

/* creer une liste de point vide */
Liste_Point creer_liste_Point_vide ();

/* creer une liste de liste vide */
Liste_Liste_Point creer_liste_liste_Point_vide ();

/* creer une liste contour segment vide */
Liste_Liste_Segment creer_liste_liste_Segment_vide ();

/* creer une liste contour bezier2 vide */
Liste_Liste_Bezier2 creer_liste_liste_Bezier2_vide ();

/* creer une liste contour bezier2 vide */
Liste_Liste_Bezier3 creer_liste_liste_Bezier3_vide ();

/* ajouter l'element e en fin de la liste de bezier3 L, renvoie la liste de segment L modifiee */
Liste_Bezier3 ajouter_element_liste_Bezier3 (Liste_Bezier3 , Bezier3 );

/* ajouter l'element e en fin de la liste de bezier2 L, renvoie la liste de segment L modifiee */
Liste_Bezier2 ajouter_element_liste_Bezier2 (Liste_Bezier2 , Bezier2 );

/* ajouter l'element e en fin de la liste de segment L, renvoie la liste de segment L modifiee */
Liste_Segment ajouter_element_liste_Segment (Liste_Segment , Segment );

/* ajouter l'element e en fin de la liste de point L, renvoie la liste de point L modifiee */
Liste_Point ajouter_element_liste_Point (Liste_Point , Point );

/*ajouter l'element l en fin de la liste de liste L, renvoie la liste L modifiee */
Liste_Liste_Point ajouter_element_liste_liste_Point (Liste_Liste_Point , Liste_Point);

/*ajouter l'element l en fin de la liste contour segment, renvoie la liste L modifiee */
Liste_Liste_Segment ajouter_element_liste_liste_Segment (Liste_Liste_Segment , Liste_Segment);

/*ajouter l'element l en fin de la liste contour bezier2, renvoie la liste L modifiee */
Liste_Liste_Bezier2 ajouter_element_liste_liste_Bezier2 (Liste_Liste_Bezier2 , Liste_Bezier2);

/*ajouter l'element l en fin de la liste contour bezier3, renvoie la liste L modifiee */
Liste_Liste_Bezier3 ajouter_element_liste_liste_Bezier3 (Liste_Liste_Bezier3 , Liste_Bezier3);

/* suppression de tous les elements de la liste de bezier3, renvoie la liste de segment L vide */
Liste_Bezier3 supprimer_liste_Bezier3 (Liste_Bezier3 );

/* suppression de tous les elements de la liste de bezier2, renvoie la liste de segment L vide */
Liste_Bezier2 supprimer_liste_Bezier2 (Liste_Bezier2 );

/* suppression de tous les elements de la liste de segment, renvoie la liste de segment L vide */
Liste_Segment supprimer_liste_Segment (Liste_Segment );

/* suppression de tous les elements de la liste, renvoie la liste L vide */
Liste_Point supprimer_liste_Point (Liste_Point );

/* suppression de tous les elements de la liste de liste, renvoie a liste L vide */
Liste_Liste_Point supprimer_liste_liste_Point (Liste_Liste_Point );

/* suppression de tous les elements de la liste contour segment, renvoie a liste L vide */
Liste_Liste_Segment supprimer_liste_liste_Segment (Liste_Liste_Segment );

/* suppression de tous les elements de la liste contour bezier2, renvoie a liste L vide */
Liste_Liste_Bezier2 supprimer_liste_liste_Bezier2 (Liste_Liste_Bezier2 );

/* suppression de tous les elements de la liste contour bezier3, renvoie a liste L vide */
Liste_Liste_Bezier3 supprimer_liste_liste_Bezier3 (Liste_Liste_Bezier3 );

/* concatene L2 a la suite de L1, renvoie la liste de bezier3 L1 modifiee */
Liste_Bezier3 concatener_liste_Bezier3 (Liste_Bezier3 , Liste_Bezier3 );

/* concatene L2 a la suite de L1, renvoie la liste de bezier2 L1 modifiee */
Liste_Bezier2 concatener_liste_Bezier2 (Liste_Bezier2 , Liste_Bezier2 );

/* concatene L2 a la suite de L1, renvoie la liste de segment L1 modifiee */
Liste_Segment concatener_liste_Segment (Liste_Segment , Liste_Segment );

/* concatene L2 a la suite de L1, renvoie la liste de point L1 modifiee */
Liste_Point concatener_liste_Point (Liste_Point , Liste_Point );

/* concatene L2 a la suite de L1, renvoie la liste de liste de point L1 modifiee */
Liste_Liste_Point concatener_liste_liste_Point (Liste_Liste_Point , Liste_Liste_Point );

/* concatene L2 a la suite de L1, renvoie la liste contour segment de point L1 modifiee */
Liste_Liste_Segment concatener_liste_liste_Segment (Liste_Liste_Segment , Liste_Liste_Segment );

/* concatene L2 a la suite de L1, renvoie la liste contour bezier2 de point L1 modifiee */
Liste_Liste_Bezier2 concatener_liste_liste_Bezier2 (Liste_Liste_Bezier2 , Liste_Liste_Bezier2 );

/* concatene L2 a la suite de L1, renvoie la liste contour bezier3 de point L1 modifiee */
Liste_Liste_Bezier3 concatener_liste_liste_Bezier3 (Liste_Liste_Bezier3 , Liste_Liste_Bezier3 );

/* renvoyer un element de la liste à un indice donné */

Point indice ( Contour , int );

/* Afficher le contenu de la liste L */
void afficher_liste_Point (Liste_Point );
void afficher_liste_liste (Liste_Liste_Point );
void afficher_liste_liste_Segment (Liste_Liste_Segment );
void afficher_liste_liste_Bezier2 (Liste_Liste_Bezier2 );
void afficher_liste_liste_Bezier3 (Liste_Liste_Bezier3 );
void afficher_liste_Segment (Liste_Segment );
void afficher_liste_Bezier2 (Liste_Bezier2 );
void afficher_liste_Bezier3 (Liste_Bezier3 );

Tableau_Point sequence_points_liste_vers_tableau (Liste_Point );

#endif
