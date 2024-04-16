#ifndef __GEOMETRIE_2D_H__
#define __GEOMETRIE_2D_H__
#include <math.h>
#include <stdio.h>
#include "types_macros.h"

// Creation du type Vecteur

typedef struct Vecteur_ {
	double x, y;
}Vecteur;

// Creation du type Point

typedef struct Point_ {
	double x, y;
}Point;

// Creation d'un segment

typedef struct Segment_ {
	Point p1,p2;
}Segment;

// Creation d'une courbe de Bezier de degre 2

typedef struct Bezier2_ {
	Point C0, C1, C2;
}Bezier2;

// Creation d'une courbe de Bezier de degre 3

typedef struct Bezier3_ {
	Point C0, C1, C2, C3;
}Bezier3;

// Creer le point de coordonnées (x,y)

Point set_point (double , double );

// Creer un vecteur de coordonnées (x,y)

Vecteur set_vect (double , double );

// Produit du réel a par le vecteur V(x,y)

Vecteur produit_vect (double , Vecteur );

// Produit du réel a par le point P(x,y)

Point produit_point (double , Point );

// Produit scalaire entre 2 vecteurs V1(x1,y1) et V2(x2,y2)

double produit_scalaire (Vecteur , Vecteur);

// Norme du vecteur V(x,y)

double norme (Vecteur );

// Distance entre 2 points A(xa,ya) et B(xb,yb);

double distance_point (Point , Point);

// somme P1+P2

Point add_point (Point , Point );

// soustraction P1-P2

Point sub_point (Point , Point);

// somme de 2 vecteurs V1 et V2

Vecteur add_vect (Vecteur , Vecteur);

// vecteur correspondant au bipoint AB

Vecteur vect_bipoint (Point , Point );

// Verifier l'egalité entre 2 points

bool egaux (Point , Point);

// Afficher point de coordonées (x,y)

void print_point(Point );

// Afficher vecteur de coordonnées (x,y)

void print_vecteur(Vecteur );

// Afficher segment S

void print_segment (Segment );

// Affichier les points de la coubre de Bezier

void print_bezier2 (Bezier2 );

// Affichier les points de la coubre de Bezier

void print_bezier3 (Bezier3 );
#endif
