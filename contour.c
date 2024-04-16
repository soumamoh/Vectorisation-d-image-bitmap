#include "contour.h"

void trouver_pixel_depart (Image I, int *x, int *y, bool *est_image_blanche) {
	int L = largeur_image(I),H = hauteur_image(I);	
	int j = 1, i;
	for (i = 1; i < L*H; i++) {
		if ( get_pixel_image(I,i,j) ) {
			*x = i;
			*y = j;
			return;
		}
		if ( i == L ) {
		       j++;
	       	       i = 0;
		}
		if ( j == (H+1) ) {
			*est_image_blanche = true;
			return;
		}
	}
}


void nouvelle_orientation (Robot *r, Pixel G, Pixel D) {
	
	if ( G == BLANC && D == BLANC )
		tourner_a_droite (r);
	else if ( ( G == NOIR && D == BLANC ) || ( G == NOIR && D == NOIR  ) )
		tourner_a_gauche (r);
	else
		return;
}

Contour contours (Image I, int x, int y, Image *M) {

	int x0, y0;
	Robot r;
	Contour C = creer_liste_Point_vide();
	x0 = x-1;
	y0 = y-1;
	init_robot (&r,x0,y0,Est);
	int boucle = true;

	while ( boucle ) {
		C = ajouter_element_liste_Point(C,(Point){(double)r.x,(double)r.y});
		if ( r.o == Est )
			set_pixel_image (*M,r.x+1,r.y+1,BLANC);
		avancer(&r);
		nouvelle_orientation(&r,pixel_gauche (I,r.x,r.y,r.o),pixel_droit (I,r.x,r.y,r.o));
		if ( x0 == abscisse(r) && y0 == ordonnee(r) && orient(r) == Est )
			boucle = false;;
	}
	C = ajouter_element_liste_Point(C,(Point){(double)r.x,(double)r.y});
	return C;
}

Image image_masque (Image I) {
	int L = largeur_image(I),H = hauteur_image(I);
	Image M = creer_image(L,H);	
	int j = 1, i;
	int sortir = 0;
	for (i = 1; i < L*H && !sortir; i++) {
		if ( get_pixel_image(I,i,j) && !get_pixel_image(I,i,j-1) )
			set_pixel_image(M,i,j,NOIR);
		if ( i == L ) {
		       j++;
	       	       i = 0;
		}
		if ( j == (H+1) )
			sortir = 1;
	}
	return M;
}

Liste_Contour contours_image (Image I) {
	
	Image M = image_masque (I);
	Liste_Contour C = creer_liste_liste_Point_vide ();
	bool est_image_blanche = false;
	int x,y;	
	while ( !est_image_blanche ) {
		trouver_pixel_depart (M,&x,&y,&est_image_blanche);
		if ( !est_image_blanche )
			C = ajouter_element_liste_liste_Point(C,contours(I,x,y,&M));
	}
	return C;
}

Liste_Contour_Segment contours_segment_image (Liste_Contour C, float d) {

	Liste_Contour_Segment LS = creer_liste_liste_Segment_vide ();
	Cellule_Liste_Liste_Point *LLP = C.Lfirst;
	Liste_Segment S = creer_liste_Segment_vide ();

	while ( LLP ) {
	    S = simplification_douglas_peucker_segment (sequence_points_liste_vers_tableau(LLP->Liste),0,(LLP->Liste).taille-1,d);
		LS = ajouter_element_liste_liste_Segment (LS,S);
		LLP = LLP->suiv;
	}	
    
	return LS;
}

Liste_Contour_Bezier2 contours_bezier2_image (Liste_Contour C, float d) {
	
	Liste_Contour_Bezier2 LB2 = creer_liste_liste_Bezier2_vide ();
	Cellule_Liste_Liste_Point *LLP = C.Lfirst;
	Liste_Bezier2 B2 = creer_liste_Bezier2_vide ();

	while ( LLP ) {
		B2 = simplification_douglas_peucker_bezier2 (sequence_points_liste_vers_tableau(LLP->Liste),0,(LLP->Liste).taille-1,d);
		LB2 = ajouter_element_liste_liste_Bezier2 (LB2,B2);
		LLP = LLP->suiv;
	}
	return LB2;
}

Liste_Contour_Bezier3 contours_bezier3_image (Liste_Contour C, float d) {
	
	Liste_Contour_Bezier3 LB3 = creer_liste_liste_Bezier3_vide ();
	Cellule_Liste_Liste_Point *LLP = C.Lfirst;
	Liste_Bezier3 B3 = creer_liste_Bezier3_vide ();

	while ( LLP ) {
		B3 = simplification_douglas_peucker_bezier3 (sequence_points_liste_vers_tableau(LLP->Liste),0,(LLP->Liste).taille-1,d);
		LB3 = ajouter_element_liste_liste_Bezier3 (LB3,B3);
		LLP = LLP->suiv;
	}
	return LB3;
}

char *recup_nom_fichier (char *fichier,char *methode) {
	int i=0;
	while ( fichier[i] != '\0' ) {
		if ( fichier[i] == '.' ) {
			fichier[i] = '\0';
			strcat(&fichier[i],methode);
			strcat(&fichier[i+strlen(methode)],".eps");
			return fichier;
		}
		i++;
	}
	return NULL;
}

int est_extension_fichier_pbm (char *fichier) {
	int i=0;
	while ( fichier[i] != '\0' ) {
		if ( fichier[i] == '.' ) 
			return !strcmp(&fichier[i+1],"pbm");
		i++;
	}
	return 0;
}

int nombre_points (Liste_Contour C) {
	if ( !C.Lfirst )
		return 0;
	return C.Lfirst->Liste.taille + nombre_points ((Liste_Contour) {C.taille,C.Lfirst->suiv,C.Llast});
}

int nombre_segments (Liste_Contour C ) {
	return nombre_points (C) - 1 ;
}

void mode_normal (char *fichier, char mode_affichage, Liste_Contour C, int xmin, int  ymin, int xmax, int ymax) {

	char *nom_fichier = malloc(sizeof(char)*(strlen(fichier)+strlen("_Normal")));
	strcpy(nom_fichier,fichier);
	nom_fichier = recup_nom_fichier (nom_fichier,"_Normal");
	
	if (!nom_fichier)
		ERREUR_FATALE("ERREUR_FICHIER");

	FILE *f = NULL;
	if ( !(f = fopen(nom_fichier,"w") ) ) {
		fprintf(stderr,"Fichier <%s> inaccessible\n",fichier);
		exit (EXIT_FAILURE);
	}

	fprintf(f,EN_TETE_EPS);
	fprintf(f,"%%%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);

	Cellule_Liste_Point *L = NULL;
	Cellule_Liste_Liste_Point *LL = C.Lfirst;

	while ( LL ) {
		L = LL->Liste.first;
		fprintf(f,"\n%f %f moveto",((L->data).x),ymax-((L->data).y));
		L = L->suiv;
	
		while ( L ) {
				
			fprintf(f," %f %f lineto",((L->data).x),ymax-((L->data).y));
			L = L->suiv;
		}
		LL = LL->suiv;
	}
	if (mode_affichage == 'F')
		fprintf(f,"\nfill\n");
	else
		fprintf(f,"\nstroke\n");
		
	fprintf(f,"showpage\n");

	free(nom_fichier);
	fclose(f);
}

void mode_segment (char *fichier, char mode_affichage, Liste_Contour_Segment C, int xmin, int  ymin, int xmax, int ymax) {

	char *nom_fichier = malloc(sizeof(char)*(strlen(fichier)+strlen("_Segment")));
	strcpy(nom_fichier,fichier);
	nom_fichier = recup_nom_fichier (nom_fichier,"_Segment");
	
	if (!nom_fichier)
		ERREUR_FATALE("ERREUR_FICHIER");

	FILE *f = NULL;
	if ( !(f = fopen(nom_fichier,"w") ) ) {
		fprintf(stderr,"Fichier <%s> inaccessible\n",fichier);
		exit (EXIT_FAILURE);
	}

	fprintf(f,EN_TETE_EPS);
	fprintf(f,"%%%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);

	Cellule_Liste_Segment *L = NULL;
	Cellule_Liste_Liste_Segment *LL = C.Lfirst;

	while ( LL ) {
		L = LL->Liste.first;
		fprintf(f,"\n%f %f moveto",((L->S).p1.x),ymax-((L->S).p1.y));
		fprintf(f,"\n%f %f lineto",((L->S).p2.x),ymax-((L->S).p2.y));
		L = L->suiv;
	
		while ( L ) {
				
			fprintf(f," %f %f lineto",((L->S).p1.x),ymax-((L->S).p1.y));
			fprintf(f," %f %f lineto",((L->S).p2.x),ymax-((L->S).p2.y));
			L = L->suiv;
		}
		LL = LL->suiv;
	}

	if (mode_affichage == 'F')
		fprintf(f,"\nfill\n");
	else
		fprintf(f,"\nstroke\n");
		
	fprintf(f,"showpage\n");

	free(nom_fichier);
	fclose(f);
}

void mode_bezier3 (char *fichier, char mode_affichage, Liste_Contour_Bezier3 C, int xmin, int  ymin, int xmax, int ymax) {

	char *nom_fichier = malloc(sizeof(char)*(strlen(fichier)+strlen("_Bezier3")));
	strcpy(nom_fichier,fichier);
	nom_fichier = recup_nom_fichier (nom_fichier,"_Bezier3");
	
	if (!nom_fichier)
		ERREUR_FATALE("ERREUR_FICHIER");

	FILE *f = NULL;
	if ( !(f = fopen(nom_fichier,"w") ) ) {
		fprintf(stderr,"Fichier <%s> inaccessible\n",fichier);
		exit (EXIT_FAILURE);
	}

	fprintf(f,EN_TETE_EPS);
	fprintf(f,"%%%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);

	Cellule_Liste_Bezier3 *L = NULL;
	Cellule_Liste_Liste_Bezier3 *LL = C.Lfirst;

	while ( LL ) {
		L = LL->Liste.first;
		fprintf(f,"\n%f %f moveto",((L->B).C0.x),ymax-((L->B).C0.y));
		while ( L ) {
			fprintf(f," %f %f %f %f %f %f curveto",((L->B).C1.x),ymax-((L->B).C1.y),((L->B).C2.x),ymax-((L->B).C2.y),((L->B).C3.x),ymax-((L->B).C3.y));
			L = L->suiv;
		}
		LL = LL->suiv;
		
	}
	
	if (mode_affichage == 'F')
		fprintf(f,"\nfill\n");
	else
		fprintf(f,"\nstroke\n");

	fprintf(f,"showpage\n");

	free(nom_fichier);
	fclose(f);
}

void mode_bezier2 (char *fichier, char mode_affichage, Liste_Contour_Bezier2 C, int xmin, int  ymin, int xmax, int ymax) {

	char *nom_fichier = malloc(sizeof(char)*(strlen(fichier)+strlen("_Bezier2")));
	strcpy(nom_fichier,fichier);
	nom_fichier = recup_nom_fichier (nom_fichier,"_Bezier2");
	
	if (!nom_fichier)
		ERREUR_FATALE("ERREUR_FICHIER");

	FILE *f = NULL;
	if ( !(f = fopen(nom_fichier,"w") ) ) {
		fprintf(stderr,"Fichier <%s> inaccessible\n",fichier);
		exit (EXIT_FAILURE);
	}

	fprintf(f,EN_TETE_EPS);
	fprintf(f,"%%%%BoundingBox: %d %d %d %d\n",xmin,ymin,xmax,ymax);
    
	Bezier3 B;
	Cellule_Liste_Bezier2 *L = NULL;
	Cellule_Liste_Liste_Bezier2 *LL = C.Lfirst;

	while ( LL ) {
		L = LL->Liste.first;
		B = convertion_bezier2_vers_bezier3 (LL->Liste.first->B);
		fprintf(f,"\n%f %f moveto",(B.C0.x),ymax-(B.C0.y));
		while ( L ) {
			B = convertion_bezier2_vers_bezier3 (L->B);
			fprintf(f," %f %f %f %f %f %f curveto",(B.C1.x),ymax-(B.C1.y),(B.C2.x),ymax-(B.C2.y),(B.C3.x),ymax-(B.C3.y));
			L = L->suiv;
		}
		LL = LL->suiv;
		
	}
	
	if (mode_affichage == 'F')
		fprintf(f,"\nfill\n");
	else
		fprintf(f,"\nstroke\n");

	fprintf(f,"showpage\n");

	free(nom_fichier);
	fclose(f);
}

