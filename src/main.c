#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_binaire.h"
#include "lecture_ecriture.h"
#include "sha256.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Utilisation mode G: %s -G -o <fichier_sortie>\nUtilisation mode L: %s -L -i <fichier_entree>\n", argv[0], argv[0]);
        return EXIT_FAILURE;
    }

    char *mode = argv[1];
    char *modeDeFichier = argv[2];

    //Mode G
    if (strcmp(mode, "-G") == 0) {
         if (strcmp(modeDeFichier, "-o") == 0) {
            char *fichier = argv[3];
            genererTableCorrespondance(fichier);
        }
        else{
            fprintf(stderr, "Utilisation mode G: %s -G -o <fichier_sortie>\n", argv[0]);
        }

    //Mode L
    } else if (strcmp(mode, "-L") == 0) {
        if (strcmp(modeDeFichier, "-i") == 0) {
            char *fichier = argv[3];
            Correspondance *arbre = chargerFichierDansArbre(fichier);

            

            rechercheCondensatsStdin(arbre);

     
            //calcul temps après traitement

        }
        else{
            fprintf(stderr, "Utilisation mode L: %s -L -i <fichier_sortie>\n", argv[0]);
        }

    } else {
        fprintf(stderr, "Mode non reconnu : %s\n", mode);
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}