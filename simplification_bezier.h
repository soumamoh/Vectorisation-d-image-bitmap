#ifndef __SIMP_BEZIER_H__
#define __SIMP_BEZIER_H__

#include "image.h"

Point somme_point_bezier2 (Tableau_Point ,int , int );
Bezier2 approx_bezier2 (Tableau_Point , int , int );
Point equation_parametrique_bezier2 (Bezier2 , double );
double distance_point_bezier2 (Point , Bezier2 , double );
Liste_Bezier2 simplification_douglas_peucker_bezier2 (Tableau_Point ,int ,int ,float );

//--------------------------------------------------------------------------------------------

Bezier3 convertion_bezier2_vers_bezier3 (Bezier2 );
double gamma_v2 (double ,double );
Point somme_point_bezier3_C1 (Tableau_Point ,int , int );
Bezier3 approx_bezier3 (Tableau_Point , int , int );
Point equation_parametrique_bezier3 (Bezier3 , double );
double distance_point_bezier3 (Point , Bezier3 , double );	
Liste_Bezier3 simplification_douglas_peucker_bezier3 (Tableau_Point ,int ,int ,float );

#endif
