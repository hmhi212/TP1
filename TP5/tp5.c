#include <stdio.h>
#include <stdlib.h>
#include "suivi.h"

void afficherMenu()
{
    printf("==== Suivi de consommation ====\n");
    printf("1. Ajouter une consommation\n");
    printf("2. Afficher le resume du jour\n");
    printf("3. Afficher les objectifs et le score\n");
    printf("4. Sauvegarder et quitter\n");
    printf("Votre choix : ");
}

int main()
{
    const int NB_CATEGORIES = 7;
    const int EAU_IDX = 0;
    const int CAFE_IDX = 1;
    const int BONBONS_IDX = 2;
    const int GATEAU_IDX = 3;
    const int LEGUMES_IDX = 4;
    const int FRUITS_IDX = 5;
    const int PROTEINES_IDX = 6;
    
    const char* CATEGORIES[] = {
        "Eau      ",
        "Cafe     ",
        "Bonbons  ",
        "Gateau   ",
        "Legumes  ",
        "Fruits   ",
        "Proteines"
    };

    const char* EMOJIS_FIXES[] = {"\u00F0\u0178\u008E\u0097", "\u00E2\u0178\u0098\u00B8", "\u00F0\u0178\u008E\u00A5", "\u00F0\u0178\u008D\u00BC", "\u00F0\u0178\u00AA\u00AE", "\u00F0\u0178\u008D\u008E", "\u00F0\u0178\u00A7\u0099"};
    const char* HUMEUR_BONBONS[] = {"\u00F0\u0178\u0098\u0087", "\u00F0\u0178\u0098\u0082", "\u00F0\u0178\u0098\u0091", "\u00F0\u0178\u0098\u00A1"};
    const char* HUMEUR_LEGUMES[] = {"\u00F0\u0178\u0098\u00B0", "\u00F0\u0178\u0098\u008E", "\u00F0\u0178\u0098\u00A6"};
    const char* HUMEUR_FRUITS[] = {"\u00F0\u0178\u0098\u00A0", "\u00F0\u0178\u0098\u008D", "\u00F0\u0178\u0098\u00B5"};
    
    const int MAX_BARRE = 20;

    int consommations[NB_CATEGORIES];
    int objectifs[NB_CATEGORIES] = {0};
    
    objectifs[EAU_IDX] = 8;
    objectifs[LEGUMES_IDX] = 5;
    objectifs[FRUITS_IDX] = 3;
    objectifs[PROTEINES_IDX] = 2;

    if (charger(consommations, NB_CATEGORIES) == 0) {
        printf("<< Aucune sauvegarde trouvée >>\n");
        initialiser(consommations, NB_CATEGORIES);
    } else {
        printf("Donnees chargees avec succes.\n");
    }

    int choix = 0;
    while (choix != 4) {
        afficherMenu();
        choix = lireChoix();

        switch (choix) {
            case 1:
                ajouterConsommation(consommations, NB_CATEGORIES, CATEGORIES);
                break;
            case 2:
                afficherResume(consommations, NB_CATEGORIES, CATEGORIES, EMOJIS_FIXES, HUMEUR_BONBONS, HUMEUR_LEGUMES, HUMEUR_FRUITS, MAX_BARRE);
                break;
            case 3:
                afficherObjectifsEtScore(consommations, objectifs, NB_CATEGORIES, CATEGORIES);
                break;
            case 4:
                if (sauvegarder(consommations, NB_CATEGORIES) == 1) {
                    printf("Sauvegarde reussie. Au revoir.\n");
                } else {
                    printf("Echec de la sauvegarde. Au revoir.\n");
                }
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }

    return 0;
}