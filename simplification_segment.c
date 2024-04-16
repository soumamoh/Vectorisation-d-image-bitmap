#include "simplification_segment.h"


double distance_point_segment (Point P, Segment S) {
    
       if (egaux(S.p1,S.p2))
	       return distance_point(S.p1,P);
       else {
	       Point Q;
	       double lambda;
	       lambda = produit_scalaire (vect_bipoint(S.p1,P),vect_bipoint(S.p1,S.p2));
		   lambda /= produit_scalaire (vect_bipoint(S.p1,S.p2),vect_bipoint(S.p1,S.p2));
		   Q = add_point (S.p1,produit_point(lambda,sub_point(S.p2,S.p1)));
		   if ( lambda < 0 )
		   		return distance_point(S.p1,P);
		   else if ( lambda > 1 )
				return distance_point(S.p2,P);
		   else
		        return distance_point(Q,P);
	   }

}

Liste_Segment simplification_douglas_peucker_segment (Tableau_Point P,int j1,int j2,float d) {
	
	Liste_Segment L = creer_liste_Segment_vide ();
	Liste_Segment L1 = creer_liste_Segment_vide ();
	Liste_Segment L2 = creer_liste_Segment_vide ();
	Segment S = {P.tab[j1],P.tab[j2]};
	
	int k = j1;
	double dmax = 0.0, dj = 0.0;

	for ( int j = j1+1; j<=j2;j++) {
		dj = distance_point_segment(P.tab[j],S);
		if (dmax < dj) {
			dmax = dj;
			k = j;
		}
	}
 
	if ( dmax <= d ) 
		L = ajouter_element_liste_Segment (L,S);
	else {
		L1 = simplification_douglas_peucker_segment (P,j1,k,d);
		L2 = simplification_douglas_peucker_segment (P,k,j2,d);
		L = concatener_liste_Segment (L1,L2);
	}	
	return L;
}
