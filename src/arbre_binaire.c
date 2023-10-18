#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_binaire.h"

// Fonction pour créer un nouveau nœud
Correspondance *creerNouveauNoeud( char *chaine,  char *condensat) {
    Correspondance *nouveauNoeud = malloc(sizeof(Correspondance));
    if (nouveauNoeud == NULL) {
        fprintf(stderr, "Erreur d'allocation de mémoire\n");
        exit(EXIT_FAILURE);
    }
    //printf("%s\n",chaine);
    nouveauNoeud->chaine = strdup(chaine);
    nouveauNoeud->condensat = strdup(condensat);
    nouveauNoeud->left = NULL;
    nouveauNoeud->right = NULL;
    return nouveauNoeud;
}

// Fonction pour insérer un nœud dans l'ABR
Correspondance *insererNoeud(Correspondance *racine,  char *chaine,  char *condensat) {
    if (racine == NULL) {
        return creerNouveauNoeud(chaine, condensat);
    }
    
    int comparaison = strcmp(condensat, racine->condensat);
    //printf("%d\n", comparaison);
    if (comparaison < 0) {
        racine->left = insererNoeud(racine->left, chaine, condensat);
    } else if (comparaison > 0) {
        racine->right = insererNoeud(racine->right, chaine, condensat);
    }
    
    return racine;
}

// Fonction pour parcourir l'ABR en ordre alphabétique et afficher les condensats triés avec leurs chaînes associées
void parcourirABR(Correspondance *racine) {
    if (racine != NULL) {
        parcourirABR(racine->left);
        printf("Condensat : %s, Chaine : %s\n", racine->condensat, racine->chaine);
        parcourirABR(racine->right);
    }
}

// Fonction pour libérer la mémoire de l'ABR
void libererABR(Correspondance *racine) {
    if (racine != NULL) {
        libererABR(racine->left);
        libererABR(racine->right);
        free(racine->condensat);
        free(racine->chaine);
        free(racine);
    }
}


// Fonction pour rechercher une chaîne parmi les condensats dans un ABR
void rechercheParmiCondensats(Correspondance *root,  char *condensatRecherche) {

    if (root == NULL) {
        printf("kjhfkdshfkhdskhfjdshfj%s\n",root->chaine);
        printf("Correspondance non trouvée : Aucune correspondance dans l'arbre.\n");
        return;
    }

    int comparaison = strcmp(condensatRecherche, root->condensat);
    if (comparaison < 0) {
        rechercheParmiCondensats(root->left, condensatRecherche);
    } else if (comparaison > 0) {
        rechercheParmiCondensats(root->right, condensatRecherche);
    } else {
        printf("Correspondance trouvée : Chaine = %s, Condensat = %s\n", root->chaine, root->condensat);
    }
}
