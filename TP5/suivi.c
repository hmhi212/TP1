#include <stdio.h>
#include <stdlib.h>
#include "suivi.h"

void afficherMenu()
{
    printf("==== Suivi de consommation ====\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Sauvegarder et quitter\n");
    printf("Votre choix : ");
}

int lireChoix()
{
    int choix;
    if (scanf("%d", &choix) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return -1;
    }
    return choix;
}

void initialiser(int *conso, int size)
{
    for (int i = 0; i < size; i++) {
        conso[i] = 0;
    }
}

void ajouterConsommation(int *conso, int size, const char *categories[])
{
    int choix_cat;
    int quantite;

    printf("Quelle categorie voulez vous modifier\n");
    for (int i = 0; i < size; i++) {
        printf("%d. %s\n", i + 1, categories[i]);
    }
    printf("Votre choix: ");
    
    if (scanf("%d", &choix_cat) != 1 || choix_cat < 1 || choix_cat > size) {
        printf("Choix de categorie invalide.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    printf("Combien d unites ajouter ? ");
    if (scanf("%d", &quantite) != 1 || quantite < 0) {
        printf("Quantite invalide.\n");
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
        return;
    }

    conso[choix_cat - 1] += quantite;
    printf("Consommation mise a jour.\n");
}


void afficherResume(int *conso, int size, const char *categories[], const char *emojis_fixes[], const char *h_bonbons[], const char *h_legumes[], const char *h_fruits[], int max_val)
{
    
}

int charger(int *conso, int size) { return 0; }
int sauvegarder(int *conso, int size) { return 0; }
void afficherObjectifsEtScore(int *conso, const int *objectifs, int size, const char *categories[]) {}
int calculerScoreSante(const int *conso, const int *objectifs, int size) { return 0; }
int humeurBonbons(int nbBonbons) { return 0; }
int humeurLegumes(int nbLegumes) { return 0; }
int humeurFruits(int nbFruits) { return 0; }
void afficherBarre(int valeur, int max) {}