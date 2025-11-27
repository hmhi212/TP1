#include <stdio.h>

void afficher_menu();
int saisir_montant();
int montant_valide(int montant);
void calcul_distribution(int montant);

int main() {
    int choix = 0;
    int montant_retire = 0;

    do {
        afficher_menu();
        
        printf("Votre choix : ");
        if (scanf("%d", &choix) != 1) {
            while (getchar() != '\n');
            choix = -1; 
        }
        
        switch (choix) {
            case 1: 
                montant_retire = saisir_montant();
                
                if (montant_retire != -1 && montant_valide(montant_retire)) {
                    calcul_distribution(montant_retire);
                }
                break;
            case 2: 
                printf("Au revoir.\n");
                break;
            default: 
                if (choix != -1) {
                    printf("Choix invalide. Veuillez reessayer.\n");
                }
                break;
        }
        
    } while (choix != 2);

    return 0;
}

void afficher_menu() {
    printf("\n=== BANQUE DISTRIBUTEUR ===\n");
    printf("1. Faire un retrait\n");
    printf("2. Quitter\n");
}

int saisir_montant() {
    int montant;
    printf("Montant a retirer: ");
    if (scanf("%d", &montant) != 1) {
        while (getchar() != '\n');
        return -1;
    }
    return montant;
}

int montant_valide(int montant) {
    if (montant % 5 != 0) {
        printf("Erreur: montant invalide.\n");
        printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5.\n");
        return 0;
    }
    if (montant < 5) {
        printf("Erreur: montant invalide.\n");
        printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5.\n");
        return 0;
    }
    if (montant > 1000) {
        printf("Erreur: montant invalide.\n");
        printf("Le montant doit etre entre 5 euros et 1000 euros, divisible par 5.\n");
        return 0;
    }
    return 1;
}

void calcul_distribution(int montant) {
    int nb_50 = 0;
    int nb_20 = 0;
    int nb_10 = 0;
    int nb_5 = 0;
    
    printf("Billets distribues:\n");

    nb_50 = montant / 50;
    if (nb_50 > 0) {
        printf("%d billets de 50 euros\n", nb_50);
        montant %= 50;
    }

    nb_20 = montant / 20;
    if (nb_20 > 0) {
        printf("%d billets de 20 euros\n", nb_20);
        montant %= 20;
    }

    nb_10 = montant / 10;
    if (nb_10 > 0) {
        printf("%d billets de 10 euros\n", nb_10);
        montant %= 10;
    }

    nb_5 = montant / 5;
    if (nb_5 > 0) {
        printf("%d billets de 5 euros\n", nb_5);
        montant %= 5;
    }
}