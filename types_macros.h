/****************************************************************************** 
  declaration de differents types et macros
******************************************************************************/
 
#ifndef _TYPES_MACROS_H_
#define _TYPES_MACROS_H_

#include <stdio.h>
#include <stdlib.h>

/* type booleen */
typedef char bool;
#define false 0
#define true  1

/* type entier positif */
typedef unsigned int UINT;

/* macro affichant le message _m_ et s'arretant */
#define ERREUR_FATALE(_m_) \
{ \
fprintf(stderr, "%s\n", _m_); \
exit(1); \
}

/* macro definissant l'en_tête d'un fichier .eps */
#define EN_TETE_EPS "%%!PS-Adobe-3.0 EPSF-3.0\n"


#endif
