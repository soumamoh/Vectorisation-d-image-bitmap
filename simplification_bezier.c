#include "simplification_bezier.h"


Point somme_point_bezier2 (Tableau_Point T,int n, int j1) {
	Point P = {0.0,0.0};
	for (int i = 1; i < n; i++)  
		P = add_point (P,T.tab[i+j1]);
	return P;
}

Bezier2 approx_bezier2 (Tableau_Point T, int j1, int j2) {
	
	Bezier2 B;
	B.C0 = T.tab[j1];
	B.C2 = T.tab[j2];
	int n = j2 - j1;

	if ( n == 1 )
		B.C1= produit_point (1.0/2.0,add_point(B.C0,B.C2));
	else {
		double alpha = ( 3*(double) n ) / ( pow ((double) n,2) - 1 );
		double beta = ( 1 - 2*(double) n ) / ( 2*((double) n + 1 ) );
		B.C1 = add_point(produit_point(alpha,somme_point_bezier2(T,n,j1)), produit_point(beta,add_point(B.C0,B.C2))); 
	}
	return B;
}

Point equation_parametrique_bezier2 (Bezier2 B, double t) {
	return add_point(add_point(produit_point(pow((1 - t),2),B.C0),produit_point(2*t*(1 - t),B.C1)),produit_point(pow(t,2),B.C2));
}

double distance_point_bezier2 (Point Pj, Bezier2 B, double ti) {
    return distance_point (Pj,equation_parametrique_bezier2(B,ti));	
}

Liste_Bezier2 simplification_douglas_peucker_bezier2 (Tableau_Point T,int j1,int j2,float d) {
	
	Liste_Bezier2 L = creer_liste_Bezier2_vide ();
	Liste_Bezier2 L1 = creer_liste_Bezier2_vide ();
	Liste_Bezier2 L2 = creer_liste_Bezier2_vide ();
	Bezier2 B = approx_bezier2 (T,j1,j2); 
	int n = j2 - j1, k = j1;
	double dmax = 0.0, dj = 0.0;

	for ( int j = j1+1; j<=j2; j++) {
		int i = j - j1;
		double ti = (double) i / (double) n;
		dj = distance_point_bezier2 (T.tab[j],B,ti);
		if (dmax < dj) {
			dmax = dj;
			k = j;
		}
	}

	if ( dmax <= d ) 
		L = ajouter_element_liste_Bezier2 (L,B);
	else {
		L1 = simplification_douglas_peucker_bezier2 (T,j1,k,d);
		L2 = simplification_douglas_peucker_bezier2 (T,k,j2,d);
		L = concatener_liste_Bezier2(L1,L2);
	}	
	return L;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------- */

Bezier3 convertion_bezier2_vers_bezier3 (Bezier2 B) {
	return (Bezier3) { B.C0,produit_point(1.0/3.0,add_point(B.C0,produit_point(2.0,B.C1))), produit_point(1.0/3.0,add_point(produit_point(2.0,B.C1),B.C2)), B.C2 };
}

double gamma_v2 (double k,double n) {
	return 6*pow(k,4) - 8*n*pow(k,3) + 6*pow(k,2) - 4*n*k + pow(n,4) - pow(n,2);
}

Point somme_point_bezier3_C1 (Tableau_Point T,int n, int j1) {
	Point P = {0.0,0.0};
	for (int i = 1; i < n; i++)  
		P = add_point (P,produit_point(gamma_v2((double)i,(double)n),T.tab[i+j1]));
	return P;
}

Point somme_point_bezier3_C2 (Tableau_Point T,int n, int j1) {
	Point P = {0.0,0.0};
	for (int i = 1; i < n; i++)  
		P = add_point (P,produit_point(gamma_v2((double)n-i,(double)n),T.tab[i+j1]));
	return P;
}

Bezier3 approx_bezier3 (Tableau_Point T, int j1, int j2) {
	
	Bezier3 B;
	int n = j2 - j1;

	if ( n == 1 || n == 2) {
		Bezier2 B2 = approx_bezier2 (T,j1,j2);
		B = convertion_bezier2_vers_bezier3 (B2);
	}
	else {
		B.C0 = T.tab[j1];
	    B.C3 = T.tab[j2];
		double denominateur_alpha_beta = 3*( ( n + 2 ) * ( 3*pow (n,2) + 1 ));
		double alpha = ( -15*(pow((double) n,3)) + 5*(pow((double) n,2)) + 2*n + 4 ) / denominateur_alpha_beta;
		double beta = ( 10*(pow((double) n,3)) - 15*(pow((double) n,2)) + n + 2 ) / denominateur_alpha_beta;
		double lambda = ( 70*n ) / ( 3*( (pow((double) n,2) - 1)) * ( pow((double) n,2) - 4 ) * ( 3*(pow ((double) n,2) ) + 1) );
		B.C1 = add_point(add_point (produit_point(alpha,B.C0),produit_point(lambda,somme_point_bezier3_C1(T,n,j1))),produit_point(beta,B.C3));
		B.C2 = add_point(add_point (produit_point(beta,B.C0),produit_point(lambda,somme_point_bezier3_C2(T,n,j1))),produit_point(alpha,B.C3));
	}
	return B;
}

Point equation_parametrique_bezier3 (Bezier3 B, double t) {
	return add_point(add_point(add_point(produit_point(pow((1 - t),3),B.C0),produit_point(3*t*(pow((1 - t),2)),B.C1)),produit_point(3*pow(t,2)*(1 - t),B.C2)),produit_point(pow(t,3),B.C3));
}

double distance_point_bezier3 (Point Pj, Bezier3 B, double ti) {
    return distance_point (Pj,equation_parametrique_bezier3(B,ti));	
}

Liste_Bezier3 simplification_douglas_peucker_bezier3 (Tableau_Point T,int j1,int j2,float d) {
	
	Liste_Bezier3 L = creer_liste_Bezier3_vide ();
	Liste_Bezier3 L1 = creer_liste_Bezier3_vide ();
	Liste_Bezier3 L2 = creer_liste_Bezier3_vide ();
	Bezier3 B = approx_bezier3 (T,j1,j2); 
	int n = j2 - j1, k = j1;
	double dmax = 0.0, dj = 0.0;

	for ( int j = j1+1; j<=j2; j++) {
		int i = j - j1;
		double ti = (double) i / (double) n;
		dj = distance_point_bezier3 (T.tab[j],B,ti);
		if (dmax < dj) {
			dmax = dj;
			k = j;
		}
	}

	if ( dmax <= d ) 
		L = ajouter_element_liste_Bezier3 (L,B);
	else {
		L1 = simplification_douglas_peucker_bezier3 (T,j1,k,d);
		L2 = simplification_douglas_peucker_bezier3 (T,k,j2,d);
		L = concatener_liste_Bezier3(L1,L2);
	}	
	return L;
}