#include <stdio.h>
#include "sequence.h"


int main () {

	Liste_Liste_Point LL = creer_liste_liste_Point_vide ();
	double x,y;
	for (int i = 0; i<3;i++) {
		Liste_Point L = creer_liste_Point_vide ();
		printf("x = ");
		scanf("%lf",&x);
		printf("y = ");
		scanf("%lf",&y);
		L = ajouter_element_liste_Point (L,(Point){x,y});
		L = ajouter_element_liste_Point (L,(Point){x,y});
		LL = ajouter_element_liste_liste_Point (LL,L);
	}
	LL = supprimer_liste_liste_Point (LL);
	afficher_liste_liste(LL);
	printf("taille = %d\n",LL.taille);

	return 0;
}	
