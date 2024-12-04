#############################################################################
# Fichier Makefile 
#############################################################################
# utilisation des variables internes $@ $< $^ $*
# $@ : correspond au nom de la cible
# $< : correspond au nom de la premiere dependance
# $^ : correspond � toutes les d�pendances
# $* : correspond au nom du fichier sans extension 
#       (dans les regles generiques uniquement)
#############################################################################
# information sur la regle executee avec la commande @echo
# (une commande commancant par @ n'est pas affichee a l'ecran)
#############################################################################


#############################################################################
# definition des variables locales
#############################################################################

# compilateur C
CC = clang

# chemin d'acces aux librairies (interfaces)
INCDIR = .

# chemin d'acces aux librairies (binaires)
LIBDIR = .

# options pour l'�dition des liens
LDOPTS = -L$(LIBDIR) -lm

# options pour la recherche des fichiers .o et .h
INCLUDEOPTS = -I$(INCDIR)

# options de compilation
COMPILOPTS = -g -Wall $(INCLUDEOPTS)

# liste des executables
EXECUTABLES = test_image


#############################################################################
# definition des regles
#############################################################################

########################################################
# la r�gle par d�faut
all : $(EXECUTABLES)

########################################################
# regle generique : 
#  remplace les regles de compilation separee de la forme
#	module.o : module.c module.h
#		$(CC) -c $(COMPILOPTS) module.c
%.o : %.c %.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module "$*
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de compilation separee de modules
# n'ayant pas de fichier .h ET/OU dependant d'autres modules
image.o : image.c image.h types_macros.h geom2d.h robot.h sequence.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

robot.o : robot.c robot.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module robot"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

contour.o : contour.c contour.h image.h
	  @echo ""
	  @echo "---------------------------------------------"
	  @echo "Compilation du module contour"
	  @echo "---------------------------------------------"
	  $(CC) -c $(COMPILOPTS) $<

test_image.o : test_image.c image.h robot.h types_macros.h contour.h sequence.h simplification_segment.h simplification_bezier.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module test_image"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<

sequence.o : sequence.c sequence.h geom2d.h types_macros.h
	@echo ""
	@echo "---------------------------------------------"
	@echo "Compilation du module sequence"
	@echo "---------------------------------------------"
	$(CC) -c $(COMPILOPTS) $<	

geom2d.o : geom2d.c geom2d.h types_macros.h
	 @echo ""
	 @echo "-------------------------------------------"
	 @echo "Compilation du module geom2d"
	 @echo "-------------------------------------------"
	 $(CC) -c $(COMPILOPTS) $< 

simplification_segment.o: simplification_segment.c simplification_segment.h image.h
	 @echo ""
	 @echo "---------------------------------------------"
	 @echo "Compilation du module simplification_segment"
	 @echo "---------------------------------------------"
	 $(CC) -c $(COMPILOPTS) $<

simplification_bezier.o: simplification_bezier.c simplification_bezier.h image.h
	 @echo ""
	 @echo "---------------------------------------------"
	 @echo "Compilation du module simplification_bezier"
	 @echo "---------------------------------------------"
	 $(CC) -c $(COMPILOPTS) $<

########################################################
# regles explicites de creation des executables

test_image : test_image.o image.o geom2d.o contour.o robot.o sequence.o simplification_segment.o simplification_bezier.o
	@echo ""
	@echo "---------------------------------------------"
	@echo "Creation de l'executable "$@
	@echo "---------------------------------------------"
	$(CC) $^ $(LDOPTS) -o $@ 


# regle pour "nettoyer" le repertoire
clean:
	rm -fR $(EXECUTABLES) *.o 
