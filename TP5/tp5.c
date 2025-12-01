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
    
    initialiser(consommations, NB_CATEGORIES);

    int choix = 0;
    while (choix != 3) {
        afficherMenu();
        choix = lireChoix();

        switch (choix) {
            case 1:
                ajouterConsommation(consommations, NB_CATEGORIES, CATEGORIES);
                break;
            case 2:
                printf("Afficher le resume du jour...\n");
                break;
            case 3:
                printf("Sauvegarder et quitter...\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
                break;
        }
    }

    return 0;
}