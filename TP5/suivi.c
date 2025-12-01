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




int humeurBonbons(int nbBonbons)
{
    if (nbBonbons >= 0 && nbBonbons <= 3) return 0;
    if (nbBonbons >= 4 && nbBonbons <= 7) return 1;
    if (nbBonbons >= 8 && nbBonbons <= 12) return 2;
    return 3;
}

int humeurLegumes(int nbLegumes)
{
    if (nbLegumes >= 0 && nbLegumes <= 1) return 0;
    if (nbLegumes >= 2 && nbLegumes <= 4) return 1;
    return 2;
}

int humeurFruits(int nbFruits)
{
    if (nbFruits >= 0 && nbFruits <= 1) return 0;
    if (nbFruits >= 2 && nbFruits <= 4) return 1;
    return 2;
}




void afficherBarre(int valeur, int max)
{
    if (max <= 0) max = 1;

    if (valeur < 0) valeur = 0;
    if (valeur > max) valeur = max;

    int casesPleines = (valeur * 10) / max;
    
    for (int i = 0; i < 10; i++) {
        if (i < casesPleines) {
            printf("#");
        } else {
            printf(".");
        }
    }
}

void afficherResume(int *conso, int size, const char *categories[], const char *emojis_fixes[], const char *h_bonbons[], const char *h_legumes[], const char *h_fruits[], int max_val)
{
    printf("============== Resume du jour ==============\n");
    for (int i = 0; i < size; i++) {
        printf("%s: %2d %s ", categories[i], conso[i], emojis_fixes[i]);
        
        if (i == BONBONS) {
            printf("%s ", h_bonbons[humeurBonbons(conso[i])]);
        } else if (i == LEGUMES) {
            printf("%s ", h_legumes[humeurLegumes(conso[i])]);
        } else if (i == FRUITS) {
            printf("%s ", h_fruits[humeurFruits(conso[i])]);
        }
        
        afficherBarre(conso[i], max_val);
        printf("\n");
    }
    printf("============================================\n");
}




int charger(int *conso, int size)
{
    FILE *f = fopen("consommation.txt", "r");
    if (f == NULL) {
        return 0;
    }

    for (int i = 0; i < size; i++) {
        if (fscanf(f, "%d", &conso[i]) != 1) {
            fclose(f);
            return 0;
        }
    }

    fclose(f);
    return 1;
}




int sauvegarder(int *conso, int size)
{
    FILE *f = fopen("consommation.txt", "w");
    if (f == NULL) {
        return 0;
    }

    for (int i = 0; i < size; i++) {
        fprintf(f, "%d", conso[i]);
        if (i < size - 1) {
            fprintf(f, " ");
        }
    }
    fprintf(f, "\n");

    if (fclose(f) == EOF) {
        return 0;
    }
    
    return 1;
}




int calculerScoreSante(const int *conso, const int *objectifs, int size)
{
    const int EAU_IDX = 0;
    const int CAFE_IDX = 1;
    const int BONBONS_IDX = 2;
    const int LEGUMES_IDX = 4;
    const int FRUITS_IDX = 5;
    const int PROTEINES_IDX = 6;
    
    int score = 50;

    if (conso[EAU_IDX] >= objectifs[EAU_IDX]) score += 10;
    if (conso[LEGUMES_IDX] >= objectifs[LEGUMES_IDX]) score += 10;
    if (conso[FRUITS_IDX] >= objectifs[FRUITS_IDX]) score += 10;
    if (conso[PROTEINES_IDX] >= objectifs[PROTEINES_IDX]) score += 10;

    int malus_bonbons = 0;
    if (conso[BONBONS_IDX] > 5) {
        malus_bonbons = conso[BONBONS_IDX] - 5;
        if (malus_bonbons > 15) malus_bonbons = 15;
    }
    score -= malus_bonbons;

    int malus_cafe = 0;
    if (conso[CAFE_IDX] > 3) {
        malus_cafe = (conso[CAFE_IDX] - 3) * 2;
        if (malus_cafe > 20) malus_cafe = 20;
    }
    score -= malus_cafe;

    if (score < 0) return 0;
    if (score > 100) return 100;
    return score;
}

void afficherObjectifsEtScore(int *conso, const int *objectifs, int size, const char *categories[])
{
    printf("====== Objectifs du jour ======\n");
    printf("Categorie Objectif Atteint ?\n");

    for (int i = 0; i < size; i++) {
        printf("%s: ", categories[i]);
        if (objectifs[i] > 0) {
            printf("%2d", objectifs[i]);
            printf(" %s\n", (conso[i] >= objectifs[i]) ? "O" : "X");
        } else {
            printf("(pas d objectif)\n");
        }
    }
    
    int score = calculerScoreSante(conso, objectifs, size);
    printf("--------------------------------\n");
    printf("Score de sante du jour : %d / 100\n", score);
    printf("================================\n");
}
