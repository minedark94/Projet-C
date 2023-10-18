#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include "arbre_binaire.h"
#include "sha256.h"

// Fonction pour générer la table de correspondance chaine-condensat
void genererTableCorrespondance(char *fichierSortie) {
    FILE *sortie = fopen(fichierSortie, "w");

    if (sortie == NULL) {
        perror("Erreur lors de l'ouverture des fichiers");
        exit(EXIT_FAILURE);
    }

    char *ligne = NULL;
    size_t tailleLigne = 0;

    int i=0;

    //delata temps
    struct timeval start, end;
    double elapsed;
    gettimeofday(&start, NULL);

    while (getline(&ligne, &tailleLigne, stdin) != -1) {
        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le saut de ligne
    
        char *condensat = calculerCondensatSHA256(ligne);
        
        //printf("%d\t%s\t%s\n",i,pass,condensat);
        fprintf(sortie, "%s:%s\n", condensat, ligne);
        free(condensat);
        i++;
    }

    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Temps d'exécution de création du fichier : %f secondes\n", elapsed);

    free(ligne);
    fclose(sortie);
}

// Fonction pour charger un fichier dans un arbre
Correspondance *chargerFichierDansArbre(char *fichierEntree) {
    FILE *entree = fopen(fichierEntree, "r");
    if (entree == NULL) {
        perror("Erreur lors de l'ouverture du fichier");
        exit(EXIT_FAILURE);
    }

    Correspondance *racine = NULL;
    char *ligne = NULL;
    size_t tailleLigne = 0;

    int i = 0;

    struct timeval start, end;
    double elapsed;
    gettimeofday(&start, NULL);

    while (getline(&ligne, &tailleLigne, entree) != -1) {
        

        ligne[strcspn(ligne, "\n")] = '\0'; // Supprimer le saut de ligne

        char *hash = strtok(ligne, ":"); // Extraction du hash
        
        char *pass = strtok(NULL, ":");   // Extraction du mot de passe
        if(pass == NULL){
           pass = "NULL";
        }
        //printf("%d hash: %s pass: %s\n", i, hash, pass);
        // Insérer les données triées dans l'arbre
        racine = insererNoeud(racine, pass, hash);
        i++;
    }

    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Temps d'exécution d'insertion : %f secondes\n", elapsed);
    
    free(ligne);
    fclose(entree);
    return racine;
}

void rechercheCondensatsStdin(Correspondance *root) {

    //calcul temps avant traitement
    struct timeval start, end;
    double elapsed;
    gettimeofday(&start, NULL);

    char *condensatRecherche;
    size_t tailleCondensatRecherche = 0;
    //recherche dans l'arbre du condensat pris dans stdin

    //int i=0;
     while (getline(&condensatRecherche, &tailleCondensatRecherche, stdin) != -1) {
        //printf("%d\n",i);
        condensatRecherche[strcspn(condensatRecherche, "\n")] = '\0'; // Supprimer le saut de ligne
        rechercheParmiCondensats(root, condensatRecherche);
        //i++;
    }
    
    
    gettimeofday(&end, NULL);
    elapsed = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;
    printf("Temps d'exécution de recherche : %f secondes\n", elapsed);
    libererABR(root);
}
