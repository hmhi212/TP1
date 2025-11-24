#include <stdio.h>

#define MAX_ELEVES 30
#define NBR_CONTROLES 3

void afficher_menu();
int lire_choix();

void afficher_menu()
{
    printf("\n===== GESTION DE NOTES =====\n");
    printf(" 1. Saisir le nombre d'eleves\n");
    printf(" 2. Saisir les notes des eleves\n");
    printf(" 3. Afficher toutes les notes\n");
    printf(" 4. Afficher la moyenne d'un eleve\n");
    printf(" 5. Afficher la moyenne generale\n");
    printf(" 6. Afficher la meilleure note de chaque controle\n");
    printf(" 0. Quitter\n");
}

int lire_choix()
{
    int choix;
    printf("Votre choix: ");
    if (scanf("%d", &choix) != 1) {
        while (getchar() != '\n'); 
        return -1;
    }
    return choix;
}

int main()
{
    int notes[MAX_ELEVES][NBR_CONTROLES];
    int nbEleves = 0; 
    int choix = -1; 

    while (choix != 0) {
        afficher_menu(); 
        choix = lire_choix(); 

        if (choix == 0) {
            printf("Au revoir.\n");
        } else if (choix >= 1 && choix <= 6) {
            printf("Option %d selectionnee.\n", choix);
        } else {
            printf("Choix invalide. Veuillez reessayer.\n");
        }

    }

    return 0;
}