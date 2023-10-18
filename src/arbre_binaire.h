#ifndef ARBRE_BINAIRE_H
#define ARBRE_BINAIRE_H

// Structure pour un nœud de l'arbre binaire
typedef struct Correspondance {
    char *condensat;
    char *chaine;
    struct Correspondance *left;
    struct Correspondance *right;
} Correspondance;


// Prototypes de fonctions
Correspondance *creerNouveauNoeud( char *chaine,  char *condensat);
Correspondance *insererNoeud(Correspondance *racine,  char *chaine,  char *condensat);
void parcourirABR(Correspondance *racine);
void libererABR(Correspondance *racine);
void rechercheParmiCondensats(Correspondance *root,  char *condensatRecherche);

#endif
