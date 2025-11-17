#include <stdio.h>

int main() {
    int n;
    
    printf("Entrez la taille de l'etoile (entre 5 et 10) : ");
    scanf("%d", &n);
    if (n<5 || n>10){
        printf(" entreez une taille valide");
    }

    int width = n * n;
    int max_height = 100;
    char img[100][100];

    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = ' ';
        }
    }

    int mid = width / 2;

    for (int i = 0; i < n; i++) {
        for (int j = mid - i; j <= mid + i; j++) {
            if (j == mid - i || j == mid + i) {
                img[i][j] = 'A';
            } else {
                img[i][j] = 'S';
            }
        }
    }

    for (int j = 0; j <= mid - n; j++) {
        img[n-1][j] = '_';
    }

    for (int j = mid + n; j < width; j++) {
        img[n-1][j] = '_';
    }

    for (int j = 0; j < width; j++) {
        if (j == 0 || j == width - 1)
            img[n][j] = '"';
        else
            img[n][j] = 'S';
    }


    int ligne_actuelle = n + 1;
    int largeur_corps = width - 4;
    int retrait_par_ligne = 3;

    while (largeur_corps > 0) {

        int largeur_totale_ligne = largeur_corps + 4;
        int debut = (width - largeur_totale_ligne) / 2;
        int fin = debut + largeur_totale_ligne - 1;

        for (int colonne = 0; colonne < width; colonne++)
            img[ligne_actuelle][colonne] = ' ';

        img[ligne_actuelle][debut] = '\'';
        img[ligne_actuelle][debut + 1] = 'V';
        img[ligne_actuelle][fin - 1] = 'V';
        img[ligne_actuelle][fin] = '\'';

        for (int colonne = debut + 2; colonne < fin - 1; colonne++)
            img[ligne_actuelle][colonne] = 'S';

        ligne_actuelle++;
        largeur_corps -= retrait_par_ligne;
    }


    for(int i = 0; i < ligne_actuelle; i++){
        for(int j = 0; j < width; j++){
            printf("%c", img[i][j]);
        }
        printf("\n");
    }

    return 0;
}
