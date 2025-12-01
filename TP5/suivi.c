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