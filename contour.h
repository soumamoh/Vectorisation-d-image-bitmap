#ifndef __CONTOUR_H__
#define __CONTOUR_H__

#include "image.h"
#include "simplification_segment.h"
#include "simplification_bezier.h"

void trouver_pixel_depart (Image ,int* , int* , bool* );
Contour contours (Image , int , int , Image*);
Image image_masque (Image );
Liste_Contour contours_image (Image I);
void nouvelle_orientation (Robot* , Pixel, Pixel );
void mode_normal (char *fichier, char mode_affichage, Liste_Contour C, int xmin, int ymin, int xmax, int ymax);
void mode_segment (char *fichier, char mode_affichage, Liste_Contour_Segment C, int xmin, int ymin, int xmax, int ymax);
void mode_bezier3 (char *fichier, char mode_affichage, Liste_Contour_Bezier3 C, int xmin, int ymin, int xmax, int ymax);
void mode_bezier2 (char *fichier, char mode_affichage, Liste_Contour_Bezier2 C, int xmin, int  ymin, int xmax, int ymax);
char *recup_nom_fichier (char *fichier, char *methode);
int est_extension_fichier_pbm (char *fichier);
int nombre_points (Liste_Contour );
int nombre_segments (Liste_Contour );

//----------------------------------------------------------------------------------

Liste_Contour_Segment contours_segment_image (Liste_Contour , float);
Liste_Contour_Bezier2 contours_bezier2_image (Liste_Contour , float);
Liste_Contour_Bezier3 contours_bezier3_image (Liste_Contour , float);

#endif
