#include "geom2d.h"


Point set_point (double x, double y) {
	Point P = {x,y};
	return P;
}

Vecteur set_vect (double x, double y) {
	Vecteur V = {x,y};
	return V;
}

Point add_point (Point P1, Point P2) {
	return set_point(P1.x+P2.x,P1.y+P2.y);
}

Point sub_point (Point P1, Point P2) {
	return set_point(P1.x-P2.x,P1.y-P2.y);
}

Vecteur add_vect (Vecteur V1, Vecteur V2) {
	return set_vect(V1.x+V2.x,V1.y+V2.y);
}

bool egaux (Point P1 , Point P2) {
	return P1.x==P2.x && P1.y==P2.y;
}

Vecteur produit_vect (double a, Vecteur V) {
	return set_vect(a*V.x,a*V.y);
}

Point produit_point (double a, Point P) {
	return set_point (a*P.x,a*P.y);
}
double produit_scalaire (Vecteur V1, Vecteur V2) {
	return V1.x*V2.x+V1.y*V2.y;
}

double norme (Vecteur V1) {
	return sqrt(pow(V1.x,2)+pow(V1.y,2));
}

double distance_point (Point P1, Point P2) {
	return sqrt(pow(P2.x-P1.x,2)+pow(P2.y-P1.y,2));
}

Vecteur vect_bipoint (Point P1, Point P2) {
	return set_vect(P2.x-P1.x,P2.y-P1.y);
}

void print_point (Point P) {
	printf("Point de coordonnees (%5.1f,%5.1f)\n",P.x,P.y);
}

void print_vecteur (Vecteur V) {
	printf("Vecteur de coordonnees (%5.1f,%5.1f)\n",V.x,V.y);
}

void print_segment (Segment S) {
	printf("___Segment___\n");
	print_point(S.p1);
	print_point(S.p2);
}

void print_bezier2 (Bezier2 B) {
	printf("___Bezier2___\n");
	print_point(B.C0);
	print_point(B.C1);
	print_point(B.C2);
}

void print_bezier3 (Bezier3 B) {
	printf("___Bezier3___\n");
	print_point(B.C0);
	print_point(B.C1);
	print_point(B.C2);
	print_point(B.C3);
}
