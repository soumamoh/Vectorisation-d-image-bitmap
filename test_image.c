#include "contour.h"
#include "simplification_segment.h"
#include "simplification_bezier.h"

int main (int argc, char *argv[]) {

	Image I;
	Liste_Contour LC = creer_liste_liste_Point_vide();
	Liste_Contour_Segment LS = creer_liste_liste_Segment_vide ();
	Liste_Contour_Bezier2 LB2 = creer_liste_liste_Bezier2_vide ();
	Liste_Contour_Bezier3 LB3 = creer_liste_liste_Bezier3_vide ();
        float densite = 0.0;
	int ret = 0;

	if (argc < 4) 
		ERREUR_FATALE(" Usage : <Fichier_image> <Densité> <fill(F)/stroke(S)> ");
	
	ret = sscanf(argv[2],"%f",&densite);
	int extension_correct = est_extension_fichier_pbm (argv[1]);

	if ( !extension_correct )
		ERREUR_FATALE(" ERROR : EXTENSION_FICHIER_INCORRECT (PBM)");
	
	if (!ret) 
		ERREUR_FATALE(" ERROR : LECTEURE_DENSITE")

	I = lire_fichier_image(argv[1]);
	LC = contours_image (I);
	printf("__CONTOURS__\nnbElements = %d\n",LC.taille);
	printf("__POINTS__\n");
	printf("nbElements = %d\n",nombre_segments(LC));
	LS = contours_segment_image(LC,densite);
	printf("__SEGMENT__\n");
	printf("nbElements = %d\n",nombre_points((Liste_Contour) {LS.taille,LS.Lfirst,LS.Llast}));
	printf("__BEZIER2__\n");
	LB2 = contours_bezier2_image (LC,densite);
	printf("nbElements = %d\n",nombre_points((Liste_Contour) {LB2.taille,LB2.Lfirst,LB2.Llast}));
    printf("__BEZIER3__\n");
	LB3 = contours_bezier3_image (LC,densite);
    printf("nbElements = %d\n",nombre_points((Liste_Contour) {LB3.taille,LB3.Lfirst,LB3.Llast}));
	
	char mode_affichage;
	ret = sscanf(argv[3],"%c",&mode_affichage);
	if ( !ret )
		ERREUR_FATALE(" ERROR : LECTEURE_MODE_AFFICHAGE ")

    if (mode_affichage != 'F' && mode_affichage != 'S')
		ERREUR_FATALE(" ERROR : MODE_AFFICHAGE (S/F) ")

	mode_segment(argv[1],mode_affichage,LS,0,0,I.L,I.H);
	mode_normal(argv[1],mode_affichage,LC,0,0,I.L,I.H);
	mode_bezier3(argv[1],mode_affichage,LB3,0,0,I.L,I.H);
	mode_bezier2(argv[1],mode_affichage,LB2,0,0,I.L,I.H);

	return 0;
}
