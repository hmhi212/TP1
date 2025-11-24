#include <stdio.h>

#define MAX_ELEVES 30
#define NBR_CONTROLES 3

void afficher_menu();
int lire_choix();
int saisir_nombre_eleves();

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


int saisir_nombre_eleves()
{
    int nb = 0;
    
    
    while (nb < 1 || nb > MAX_ELEVES) {
        printf("Entrez le nombre d'eleves (1 a %d): ", MAX_ELEVES);
        if (scanf("%d", &nb) != 1) {
            printf("Valeur invalide.\n");
            while (getchar() != '\n');
            nb = 0; 
        } else if (nb < 1 || nb > MAX_ELEVES) {
            printf("Valeur invalide.\n");
        }
    }

    return nb;
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
        } else if (choix == 1) {
            nbEleves = saisir_nombre_eleves();
            printf("Nombre d'eleves defini : %d\n", nbEleves);
        } else if (choix >= 2 && choix <= 6) {
            printf("Option %d selectionnee. Non encore implementee.\n", choix);
        } else {
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}