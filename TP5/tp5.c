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

    const char* EMOJIS_FIXES[] = {"\u00F0\u0178\u008E\u0097", "\u00E2\u0178\u0098\u00B8", "\u00F0\u0178\u008E\u00A5", "\u00F0\u0178\u008D\u00BC", "\u00F0\u0178\u00AA\u00AE", "\u00F0\u0178\u008D\u008E", "\u00F0\u0178\u00A7\u0099"};
    const char* HUMEUR_BONBONS[] = {"\u00F0\u0178\u0098\u0087", "\u00F0\u0178\u0098\u0082", "\u00F0\u0178\u0098\u0091", "\u00F0\u0178\u0098\u00A1"};
    const char* HUMEUR_LEGUMES[] = {"\u00F0\u0178\u0098\u00B0", "\u00F0\u0178\u0098\u008E", "\u00F0\u0178\u0098\u00A6"};
    const char* HUMEUR_FRUITS[] = {"\u00F0\u0178\u0098\u00A0", "\u00F0\u0178\u0098\u008D", "\u00F0\u0178\u0098\u00B5"};
    
    const int MAX_BARRE = 20;

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
                afficherResume(consommations, NB_CATEGORIES, CATEGORIES, EMOJIS_FIXES, HUMEUR_BONBONS, HUMEUR_LEGUMES, HUMEUR_FRUITS, MAX_BARRE); 
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