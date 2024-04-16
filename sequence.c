#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"

int est_liste_vide_segment (Liste_Segment S) {
	return (S.taille == 0) ? true : false;
}

int est_liste_vide_point (Liste_Point L) {
	return (L.taille == 0 ) ? true : false;
}

int est_liste_liste_vide (Liste_Liste_Point LL) {
	return (LL.taille == 0 ) ? true : false;
}

int est_liste_liste_segment_vide (Liste_Liste_Segment LL) {
	return (LL.taille == 0 ) ? true : false;
}

int est_liste_liste_bezier2_vide (Liste_Contour_Bezier2 LL) {
	return (LL.taille == 0 ) ? true : false;
}

int est_liste_liste_bezier3_vide (Liste_Contour_Bezier3 LL) {
	return (LL.taille == 0 ) ? true : false;
}

int est_liste_vide_bezier2 (Liste_Bezier2 B) {
	return (B.taille == 0) ? true : false;
}

int est_liste_vide_bezier3 (Liste_Bezier3 B) {
	return (B.taille == 0) ? true : false;
}

Cellule_Liste_Bezier2 *creer_element_liste_Bezier2 (Bezier2 B) {

	Cellule_Liste_Bezier2 *Cell = (Cellule_Liste_Bezier2 *)malloc(sizeof(Cellule_Liste_Bezier2));
	if ( !Cell ) 
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->B = B;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Bezier3 *creer_element_liste_Bezier3 (Bezier3 B) {

	Cellule_Liste_Bezier3 *Cell = (Cellule_Liste_Bezier3 *)malloc(sizeof(Cellule_Liste_Bezier3));
	if ( !Cell ) 
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->B = B;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Segment *creer_element_liste_Segment (Segment S) {

	Cellule_Liste_Segment *Cell = (Cellule_Liste_Segment *)malloc(sizeof(Cellule_Liste_Segment));
	if ( !Cell ) 
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->S = S;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Point *creer_element_liste_Point (Point P) {

	Cellule_Liste_Point *Cell = (Cellule_Liste_Point *)malloc(sizeof(Cellule_Liste_Point));
	if ( !Cell ) 
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->data = P;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Liste_Point *creer_element_liste_liste_Point (Liste_Point L) {
	Cellule_Liste_Liste_Point *Cell = (Cellule_Liste_Liste_Point *)malloc(sizeof(Cellule_Liste_Liste_Point));
	if ( !Cell )
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->Liste = L;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Liste_Segment *creer_element_liste_liste_Segment (Liste_Segment L) {
	Cellule_Liste_Liste_Segment *Cell = (Cellule_Liste_Liste_Segment *)malloc(sizeof(Cellule_Liste_Liste_Segment));
	if ( !Cell )
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->Liste = L;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Liste_Bezier2 *creer_element_liste_liste_Bezier2 (Liste_Bezier2 L) {
	Cellule_Liste_Liste_Bezier2 *Cell = (Cellule_Liste_Liste_Bezier2 *)malloc(sizeof(Cellule_Liste_Liste_Bezier2));
	if ( !Cell )
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->Liste = L;
	Cell->suiv = NULL;
	return Cell;
}

Cellule_Liste_Liste_Bezier3 *creer_element_liste_liste_Bezier3 (Liste_Bezier3 L) {
	Cellule_Liste_Liste_Bezier3 *Cell = (Cellule_Liste_Liste_Bezier3 *)malloc(sizeof(Cellule_Liste_Liste_Bezier3));
	if ( !Cell )
		ERREUR_FATALE("PROBLEME D'ALLOCATION MEMOIRE\n");
	Cell->Liste = L;
	Cell->suiv = NULL;
	return Cell;
}

Liste_Bezier2 creer_liste_Bezier2_vide () {
	return (Liste_Bezier2){0,NULL,NULL};
}

Liste_Bezier3 creer_liste_Bezier3_vide () {
	return (Liste_Bezier3){0,NULL,NULL};
}

Liste_Segment creer_liste_Segment_vide () {
	return (Liste_Segment){0,NULL,NULL};
}

Liste_Point creer_liste_Point_vide () {
	return (Liste_Point){0,NULL,NULL};
}

Liste_Liste_Point creer_liste_liste_Point_vide () {
	return (Liste_Liste_Point){0,NULL,NULL};
}

Liste_Liste_Segment creer_liste_liste_Segment_vide () {
	return (Liste_Liste_Segment){0,NULL,NULL};
}

Liste_Liste_Bezier2 creer_liste_liste_Bezier2_vide () {
	return (Liste_Liste_Bezier2){0,NULL,NULL};
}

Liste_Liste_Bezier3 creer_liste_liste_Bezier3_vide () {
	return (Liste_Liste_Bezier3){0,NULL,NULL};
}

Liste_Bezier2 ajouter_element_liste_Bezier2 (Liste_Bezier2 L, Bezier2 B) {

	Cellule_Liste_Bezier2 *Cell = creer_element_liste_Bezier2(B);
	if ( est_liste_vide_bezier2(L) ) {
		L.first = Cell;
		L.last = Cell;
	}
	else {
		L.last->suiv = Cell;
		L.last = Cell;
	}
	L.taille++;
	return L;
}

Liste_Bezier3 ajouter_element_liste_Bezier3 (Liste_Bezier3 L, Bezier3 B) {

	Cellule_Liste_Bezier3 *Cell = creer_element_liste_Bezier3(B);
	if ( est_liste_vide_bezier3(L) ) {
		L.first = Cell;
		L.last = Cell;
	}
	else {
		L.last->suiv = Cell;
		L.last = Cell;
	}
	L.taille++;
	return L;
}

Liste_Segment ajouter_element_liste_Segment (Liste_Segment L, Segment S) {

	Cellule_Liste_Segment *Cell = creer_element_liste_Segment(S);
	if ( est_liste_vide_segment(L) ) {
		L.first = Cell;
		L.last = Cell;
	}
	else {
		L.last->suiv = Cell;
		L.last = Cell;
	}
	L.taille++;
	return L;
}

Liste_Point ajouter_element_liste_Point (Liste_Point L, Point P) {

	Cellule_Liste_Point *Cell = creer_element_liste_Point(P);
	if ( est_liste_vide_point(L) ) {
		L.first = Cell;
		L.last = Cell;
	}
	else {
		L.last->suiv = Cell;
		L.last = Cell;
	}
	L.taille++;
	return L;
}

Liste_Liste_Point ajouter_element_liste_liste_Point (Liste_Liste_Point LL, Liste_Point L) {
	Cellule_Liste_Liste_Point *Cell = creer_element_liste_liste_Point (L);

	if ( est_liste_liste_vide(LL) ) {
		LL.Lfirst = Cell;
		LL.Llast = Cell;
	}
	else {
		LL.Llast->suiv = Cell;
		LL.Llast = Cell;
	}
	LL.taille++;
	return LL;
}

Liste_Liste_Segment ajouter_element_liste_liste_Segment (Liste_Liste_Segment LL, Liste_Segment L) {
	Cellule_Liste_Liste_Segment *Cell = creer_element_liste_liste_Segment (L);

	if ( est_liste_liste_segment_vide(LL) ) {
		LL.Lfirst = Cell;
		LL.Llast = Cell;
	}
	else {
		LL.Llast->suiv = Cell;
		LL.Llast = Cell;
	}
	LL.taille++;
	return LL;
}

Liste_Liste_Bezier2 ajouter_element_liste_liste_Bezier2 (Liste_Liste_Bezier2 LL, Liste_Bezier2 L) {
	Cellule_Liste_Liste_Bezier2 *Cell = creer_element_liste_liste_Bezier2 (L);

	if ( est_liste_liste_bezier2_vide(LL) ) {
		LL.Lfirst = Cell;
		LL.Llast = Cell;
	}
	else {
		LL.Llast->suiv = Cell;
		LL.Llast = Cell;
	}
	LL.taille++;
	return LL;
}

Liste_Liste_Bezier3 ajouter_element_liste_liste_Bezier3 (Liste_Liste_Bezier3 LL, Liste_Bezier3 L) {
	Cellule_Liste_Liste_Bezier3 *Cell = creer_element_liste_liste_Bezier3 (L);

	if ( est_liste_liste_bezier3_vide(LL) ) {
		LL.Lfirst = Cell;
		LL.Llast = Cell;
	}
	else {
		LL.Llast->suiv = Cell;
		LL.Llast = Cell;
	}
	LL.taille++;
	return LL;
}

Liste_Bezier2 supprimer_liste_Bezier2 (Liste_Bezier2 L ) {

	Cellule_Liste_Bezier2 *el = L.first, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		free(el);
		el = suiv;
	}
	return (Liste_Bezier2){0,NULL,NULL};
}

Liste_Bezier3 supprimer_liste_Bezier3 (Liste_Bezier3 L ) {

	Cellule_Liste_Bezier3 *el = L.first, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		free(el);
		el = suiv;
	}
	return (Liste_Bezier3){0,NULL,NULL};
}

Liste_Segment supprimer_liste_Segment (Liste_Segment L ) {

	Cellule_Liste_Segment *el = L.first, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		free(el);
		el = suiv;
	}
	return (Liste_Segment){0,NULL,NULL};
}

Liste_Point supprimer_liste_Point (Liste_Point L) {
	
	Cellule_Liste_Point *el = L.first, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		free(el);
		el = suiv;
	}
	return (Liste_Point){0,NULL,NULL};
}

Liste_Liste_Point supprimer_liste_liste_Point (Liste_Liste_Point L) {
	
	Cellule_Liste_Liste_Point *el = L.Lfirst, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		el->Liste = supprimer_liste_Point (el->Liste);
		free(el);
		el = suiv;
	}
	return (Liste_Liste_Point){0,NULL,NULL};
}

Liste_Liste_Segment supprimer_liste_liste_Segment (Liste_Liste_Segment L) {
	
	Cellule_Liste_Liste_Segment *el = L.Lfirst, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		el->Liste = supprimer_liste_Segment (el->Liste);
		free(el);
		el = suiv;
	}
	return (Liste_Liste_Segment){0,NULL,NULL};
}

Liste_Liste_Bezier2 supprimer_liste_liste_Bezier2 (Liste_Liste_Bezier2 L) {
	
	Cellule_Liste_Liste_Bezier2 *el = L.Lfirst, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		el->Liste = supprimer_liste_Bezier2 (el->Liste);
		free(el);
		el = suiv;
	}
	return (Liste_Liste_Bezier2){0,NULL,NULL};
}

Liste_Liste_Bezier3 supprimer_liste_liste_Bezier3 (Liste_Liste_Bezier3 L) {
	
	Cellule_Liste_Liste_Bezier3 *el = L.Lfirst, *suiv = NULL;
	while ( el ) {
		suiv = el->suiv;
		el->Liste = supprimer_liste_Bezier3 (el->Liste);
		free(el);
		el = suiv;
	}
	return (Liste_Liste_Bezier3){0,NULL,NULL};
}

Liste_Bezier2 concatener_liste_Bezier2 (Liste_Bezier2 L1, Liste_Bezier2 L2) {

	if ( est_liste_vide_bezier2 (L1) ) return L2;
	if ( est_liste_vide_bezier2 (L2) ) return L1;
	L1.last->suiv = L2.first;
	L1.last = L2.last;
	L1.taille += L2.taille;
	return L1;
}

Liste_Bezier3 concatener_liste_Bezier3 (Liste_Bezier3 L1, Liste_Bezier3 L2) {

	if ( est_liste_vide_bezier3 (L1) ) return L2;
	if ( est_liste_vide_bezier3 (L2) ) return L1;
	L1.last->suiv = L2.first;
	L1.last = L2.last;
	L1.taille += L2.taille;
	return L1;
}

Liste_Segment concatener_liste_Segment (Liste_Segment L1, Liste_Segment L2) {

	if ( est_liste_vide_segment (L1) ) return L2;
	if ( est_liste_vide_segment (L2) ) return L1;
	L1.last->suiv = L2.first;
	L1.last = L2.last;
	L1.taille += L2.taille;
	return L1;
}

Liste_Point concatener_liste_Point (Liste_Point L1, Liste_Point L2) {

	if ( est_liste_vide_point (L1) ) return L2;
	if ( est_liste_vide_point (L2) ) return L1;
	L1.last->suiv = L2.first;
	L1.last = L2.last;
	L1.taille += L2.taille;
	return L1;
}

Liste_Liste_Point concatener_liste_liste_Point (Liste_Liste_Point L1, Liste_Liste_Point L2) {
	if ( est_liste_liste_vide (L1) ) return L2;
	if ( est_liste_liste_vide (L2) ) return L1;
	L1.Llast->suiv = L2.Lfirst;
	L1.Llast = L2.Llast;
	L1.taille += L2.taille;
	return L1;
}

Liste_Liste_Segment concatener_liste_liste_Segment (Liste_Liste_Segment L1, Liste_Liste_Segment L2) {
	if ( est_liste_liste_segment_vide (L1) ) return L2;
	if ( est_liste_liste_segment_vide (L2) ) return L1;
	L1.Llast->suiv = L2.Lfirst;
	L1.Llast = L2.Llast;
	L1.taille += L2.taille;
	return L1;
}

Liste_Liste_Bezier2 concatener_liste_liste_Bezier2 (Liste_Liste_Bezier2 L1, Liste_Liste_Bezier2 L2) {
	if ( est_liste_liste_bezier2_vide (L1) ) return L2;
	if ( est_liste_liste_bezier2_vide (L2) ) return L1;
	L1.Llast->suiv = L2.Lfirst;
	L1.Llast = L2.Llast;
	L1.taille += L2.taille;
	return L1;
}

Point indice (Contour C, int i) {
	
	Cellule_Liste_Point *P = C.first;
	if (i==0) 
		return P->data;
	C.first = P->suiv;
	return indice (C,i-1);
}

void afficher_liste_Point (Liste_Point L) {

	Cellule_Liste_Point *el = L.first;

	while ( el ) {
		print_point (el->data);
		el = el->suiv;
	}
}

void afficher_liste_liste (Liste_Liste_Point L) {
	Cellule_Liste_Liste_Point *el = L.Lfirst;
	while ( el ) {
		afficher_liste_Point(el->Liste);
		printf("\n");
		el = el->suiv;
	}
}

void afficher_liste_liste_Segment (Liste_Liste_Segment L) {
	Cellule_Liste_Liste_Segment *el = L.Lfirst;
	while ( el ) {
		afficher_liste_Segment(el->Liste);
		printf("\n");
		el = el->suiv;
	}
}

void afficher_liste_liste_Bezier2 (Liste_Liste_Bezier2 L) {
	Cellule_Liste_Liste_Bezier2 *el = L.Lfirst;
	while ( el ) {
		afficher_liste_Bezier2(el->Liste);
		printf("\n");
		el = el->suiv;
	}
}

void afficher_liste_liste_Bezier3 (Liste_Liste_Bezier3 L) {
	Cellule_Liste_Liste_Bezier3 *el = L.Lfirst;
	while ( el ) {
		afficher_liste_Bezier3(el->Liste);
		printf("\n");
		el = el->suiv;
	}
}

void afficher_liste_Segment (Liste_Segment L) {

	Cellule_Liste_Segment*el = L.first;

	while ( el ) {
		print_segment (el->S);
		el = el->suiv;
	}
}

void afficher_liste_Bezier2 (Liste_Bezier2 L) {

	Cellule_Liste_Bezier2 *el = L.first;

	while ( el ) {
		print_bezier2 (el->B);
		el = el->suiv;
	}
}

void afficher_liste_Bezier3 (Liste_Bezier3 L) {

	Cellule_Liste_Bezier3 *el = L.first;

	while ( el ) {
		print_bezier3 (el->B);
		el = el->suiv;
	}
}

Tableau_Point sequence_points_liste_vers_tableau (Liste_Point L) {
	
	Tableau_Point T;
	T.taille = L.taille;
	T.tab = malloc(sizeof(Point)*T.taille);

	if ( !T.tab ) 
		ERREUR_FATALE("sequence_points_tableau_vers_tableau : allocation impossible");
	int k = 0;
	Cellule_Liste_Point *el = L.first;

	while ( el ) {
		T.tab[k] = el->data;
		k++;
		el = el->suiv;
	}
	return T;
}

