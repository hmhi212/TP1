#include <stdio.h>
#include <stdlib.h>
#include "suivi.h"

int main()
{
    const int NB_CATEGORIES = 7;
    const char* CATEGORIES[] = {
        "Eau      ",
        "Cafe     ",
        "Bonbons  ",
        "Gateau   ",
        "Legumes  ",
        "Fruits   ",
        "Proteines"
    };

    int consommations[NB_CATEGORIES];
    
    if (charger(consommations, NB_CATEGORIES) == 0) {
        printf("<< Aucune sauvegarde trouvée >>\n");
        initialiser(consommations, NB_CATEGORIES);
    } else {
        printf("Donnees chargees avec succes.\n");
    }

    int choix = 0;
    while (choix != 3) {
        afficherMenu();
        choix = lireChoix();

        switch (choix) {
            case 1:
                ajouterConsommation(consommations, NB_CATEGORIES, CATEGORIES);
                break;
            case 2:
                afficherResume(consommations, NB_CATEGORIES, CATEGORIES, NULL, NULL, NULL, NULL, 0); 
                break;
            case 3:
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