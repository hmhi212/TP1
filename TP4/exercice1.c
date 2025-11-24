#include <stdio.h>

#define MAX_ELEVES 30
#define NBR_CONTROLES 3


void afficher_menu();


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

int main()
{
    
    afficher_menu(); 
    
    return 0;
}