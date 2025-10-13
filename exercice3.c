#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define MAX_ERREURS 6


const char *PENDU[] = {
    "\n\n\n\n\n\n\n-------\n",
    "\n |\n |\n |\n |\n |\n |\n-------\n",
    " -------\n | |\n |\n |\n |\n |\n-------\n",
    " -------\n | |\n | O\n |\n |\n |\n-------\n",
    " -------\n | |\n | O\n | |\n |\n |\n-------\n",
    " -------\n | |\n | O\n | /|\\\n |\n |\n-------\n",
    " -------\n | |\n | O\n | /|\\\n | / \\\n |\n-------\n"
};

int main() {
    char motSecret[50] = "ordinateur";   
    char motTrouve[50];
    int longueur = strlen(motSecret);
    int erreurs = 0;
    int gagne = 0;

    
    for (int i = 0; i < longueur; i++)
        motTrouve[i] = '_';
    motTrouve[longueur] = '\0';

    printf(" Bienvenue dans le jeu du Pendu !\n");
    printf("Le mot à deviner contient %d lettres.\n\n", longueur);

    while (erreurs < MAX_ERREURS && !gagne) {
        printf("%s\n", PENDU[erreurs]);
        printf("Mot à deviner : %s\n", motTrouve);

        printf("Entrez une lettre : ");
        char lettre;
        scanf(" %c", &lettre);
        lettre = tolower(lettre); 

        int trouve = 0;
        for (int i = 0; i < longueur; i++) {
            if (motSecret[i] == lettre && motTrouve[i] == '_') {
                motTrouve[i] = lettre;
                trouve = 1;
            }
        }

        if (!trouve) {
            erreurs++;
            printf(" Mauvaise lettre ! (%d/%d)\n", erreurs, MAX_ERREURS);
        } else {
            printf(" Bonne lettre !\n");
        }

        
        if (strcmp(motTrouve, motSecret) == 0)
            gagne = 1;
    }

    
    if (gagne) {
        printf("\n Bravo ! Vous avez trouvé le mot : %s\n", motSecret);
    } else {
        printf("%s\n", PENDU[MAX_ERREURS]);
        printf("\n Vous avez perdu ! Le mot était : %s\n", motSecret);
    }

    return 0;
}
