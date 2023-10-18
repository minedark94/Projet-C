#ifndef LECTURE_ECRITURE_H
#define LECTURE_ECRITURE_H

#include "arbre_binaire.h"

//Fonctions pour la lecture et l'écriture de fichiers
void genererTableCorrespondance(char *fichierSortie);
Correspondance *chargerFichierDansArbre(char *fichierEntree);
void rechercheCondensatsStdin(Correspondance *root);

#endif
