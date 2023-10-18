#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>
#include <sys/time.h>

//Fonction pour calculer le condensat SHA-256 d'une chaîne
char *calculerCondensatSHA256(char *chaine) {
    unsigned char resultat[32]; // 32 octets pour SHA-256

    SHA256(( unsigned char *)chaine, strlen(chaine), resultat);

    char *condensatHex = malloc(65); // 64 caractères + le caractère nul
    if (condensatHex == NULL) {
        perror("Erreur d'allocation mémoire");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 32; i++) {
        sprintf(&condensatHex[i * 2], "%02x", resultat[i]);
    }

    return condensatHex;
}