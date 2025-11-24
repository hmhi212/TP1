#include <stdio.h>

void afficher_menu();
int lire_choix();
int saisir_nombre_eleves(int MAX_E);
void saisir_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E]);
void afficher_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E]);
float calculer_moyenne_eleve(int indiceEleve, int NBR_C, int MAX_E, int notes[][MAX_E]);
float calculer_moyenne_generale(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E]);
int trouver_meilleure_note_controle(int indiceControle, int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E]);
void afficher_meilleures_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E]);

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

int saisir_nombre_eleves(int MAX_E)
{
    int nb = 0;
    
    while (nb < 1 || nb > MAX_E) {
        printf("Entrez le nombre d'eleves (1 a %d): ", MAX_E);
        if (scanf("%d", &nb) != 1) {
            printf("Valeur invalide.\n");
            while (getchar() != '\n');
            nb = 0;
        } else if (nb < 1 || nb > MAX_E) {
            printf("Valeur invalide.\n");
        }
    }

    return nb;
}

void saisir_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    if (nbEleves == 0) {
        printf("Veuillez d'abord saisir le nombre d'eleves (Option 1).\n");
        return;
    }

    printf("Saisie des notes pour %d eleves et %d controles.\n", nbEleves, NBR_C);

    for (int i = 0; i < nbEleves; i++) {
        printf("Eleve %d:\n", i + 1);
        for (int j = 0; j < NBR_C; j++) {
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

void afficher_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    if (nbEleves == 0) {
        printf("Aucune note saisie.\n");
        return;
    }
    
    printf("\n--- Tableau des notes ---\n");
    printf("Eleve\tC1\tC2\tC3\n"); 
    printf("---------------------------\n");

    for (int i = 0; i < nbEleves; i++) {
        printf("%d\t", i + 1);
        for (int j = 0; j < NBR_C; j++) {
            printf("%d\t", notes[i][j]);
        }
        printf("\n");
    }
}

float calculer_moyenne_eleve(int indiceEleve, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    int somme = 0;
    for (int j = 0; j < NBR_C; j++) {
        somme += notes[indiceEleve][j]; 
    }
    return (float)somme / NBR_C; 
}

float calculer_moyenne_generale(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    if (nbEleves == 0) return 0.0f;
    
    float somme_moyennes = 0.0f;
    
    for (int i = 0; i < nbEleves; i++) {
        somme_moyennes += calculer_moyenne_eleve(i, NBR_C, MAX_E, notes);
    }
    
    return somme_moyennes / nbEleves;
}

int trouver_meilleure_note_controle(int indiceControle, int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    if (nbEleves == 0) return -1;

    int max_note = -1;
    
    for (int i = 0; i < nbEleves; i++) {
        if (notes[i][indiceControle] > max_note) {
            max_note = notes[i][indiceControle];
        }
    }
    return max_note;
}

void afficher_meilleures_notes(int nbEleves, int NBR_C, int MAX_E, int notes[][MAX_E])
{
    if (nbEleves == 0) {
        printf("Veuillez d'abord saisir les notes.\n");
        return;
    }

    for (int j = 0; j < NBR_C; j++) {
        int meilleure_note = trouver_meilleure_note_controle(j, nbEleves, NBR_C, MAX_E, notes);
        printf("Meilleure note au controle %d: %d\n", j + 1, meilleure_note);
    }
}

int main()
{
    const int MAX_ELEVES = 30;
    const int NBR_CONTROLES_LOCAL = 3;
    
    int notes[MAX_ELEVES][NBR_CONTROLES_LOCAL];
    int nbEleves = 0;
    int choix = -1;

    while (choix != 0) {
        afficher_menu(); 
        choix = lire_choix(); 

        if (choix == 0) {
            printf("Au revoir.\n");
        } else if (choix == 1) {
            nbEleves = saisir_nombre_eleves(MAX_ELEVES);
            printf("Nombre d'eleves defini : %d\n", nbEleves);
        } else if (choix == 2) {
            saisir_notes(nbEleves, NBR_CONTROLES_LOCAL, MAX_ELEVES, notes);
        } else if (choix == 3) {
            afficher_notes(nbEleves, NBR_CONTROLES_LOCAL, MAX_ELEVES, notes);
        } else if (choix == 4) {
            if (nbEleves == 0) {
                printf("Aucune note saisie.\n");
            } else {
                int indice;
                printf("Entrez l'indice de l'eleve (1 a %d): ", nbEleves);
                if (scanf("%d", &indice) == 1 && indice >= 1 && indice <= nbEleves) {
                    float moyenne = calculer_moyenne_eleve(indice - 1, NBR_CONTROLES_LOCAL, MAX_ELEVES, notes); 
                    printf("Moyenne de l'eleve %d: %.2f\n", indice, moyenne);
                } else {
                    printf("Indice d'eleve invalide.\n");
                    while (getchar() != '\n'); 
                }
            }
        } else if (choix == 5) {
            if (nbEleves == 0) {
                printf("Aucune note saisie.\n");
            } else {
                float moyenne_g = calculer_moyenne_generale(nbEleves, NBR_CONTROLES_LOCAL, MAX_ELEVES, notes);
                printf("Moyenne generale de la classe: %.2f\n", moyenne_g); 
            }
        } else if (choix == 6) {
            afficher_meilleures_notes(nbEleves, NBR_CONTROLES_LOCAL, MAX_ELEVES, notes);
        } else {
            printf("Choix invalide. Veuillez reessayer.\n");
        }
    }

    return 0;
}