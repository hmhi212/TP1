#include <stdio.h>

#define MAX_ELEVES 30
#define NBR_CONTROLES 3

void afficher_menu();
int lire_choix();
int saisir_nombre_eleves();
void saisir_notes(int nbEleves, int notes[][NBR_CONTROLES]);

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


void saisir_notes(int nbEleves, int notes[][NBR_CONTROLES])
{
    if (nbEleves == 0) {
        printf("Veuillez d'abord saisir le nombre d'eleves (Option 1).\n");
        return;
    }

    printf("Saisie des notes pour %d eleves et %d controles.\n", nbEleves, NBR_CONTROLES);

    for (int i = 0; i < nbEleves; i++) {
        printf("Eleve %d:\n", i + 1);
        for (int j = 0; j < NBR_CONTROLES; j++) {
            int note = -1; 
            
            while (note < 0 || note > 20) {
                printf("Note du controle %d (0 a 20): ", j + 1);
                if (scanf("%d", &note) != 1) {
                    printf("Note invalide. Doit etre entre 0 et 20.\n");
                    while (getchar() != '\n');
                    note = -1; 
                } else if (note < 0 || note > 20) {
                    printf("Note invalide. Doit etre entre 0 et 20.\n");
                }
            }
            notes[i][j] = note;
        }
    }
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
        } else if (choix == 2) {
           
            saisir_notes(nbEleves, notes);
        } else if (choix >= 3 && choix <= 6) {
            printf("Option %d selectionnee. Non encore implementee.\n", choix);
        } else {
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}