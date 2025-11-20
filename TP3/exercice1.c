#include <stdio.h>
#include <math.h>

int main() {
    int n;
    printf("Entrez la taille de l'etoile (entre 5 et 10) : ");
    if (scanf("%d", &n) != 1) return 0;
    if (n < 5 || n > 10) return 0;

    int width = 2 * (n + n) + 1;
    if (width > 100) width = 100;
    int height = 4 * n;

    char img[100][100];

    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            img[i][j] = ' ';

    int mid = width / 2;
    int ligne = 0;

    for (int i = 0; i < n; i++) {
        for (int j = mid - i; j <= mid + i; j++)
            img[ligne][j] = (j == mid - i || j == mid + i) ? 'A' : 'S';
        ligne++;
    }

    for (int j = 0; j <= mid - n; j++)
        img[ligne - 1][j] = '_';
    for (int j = mid + n; j < width; j++)
        img[ligne - 1][j] = '_';

    for (int j = 0; j < width; j++)
        img[ligne][j] = (j == 0 || j == width - 1) ? '"' : 'S';

    ligne++;

    int largeur = width - 2;
    int retrait;

    if (n <= 6) retrait = 4;
    else if (n <= 8) retrait = 5;
    else retrait = 6;
    
    int largeur_cible = 2 * retrait;
    
    while (largeur - retrait > largeur_cible) {
        int debut = (width - largeur) / 2;
        int fin = debut + largeur - 1;

        img[ligne][debut] = '\'';
        img[ligne][debut + 1] = 'V';
        img[ligne][fin - 1] = 'V';
        img[ligne][fin] = '\'';

        for (int j = debut + 2; j < fin - 1; j++)
            img[ligne][j] = 'S';

        largeur -= retrait;
        ligne++;
    }

    int pos_gauche = mid - n;
    int pos_droite = mid + n;

    for (int i = 0; i < n; i++) {
        int largeur_jambe = n - i;

        int debut_gauche = pos_gauche - i;
        int fin_gauche = debut_gauche + largeur_jambe - 1;

        int fin_droite = pos_droite + i;
        int debut_droite = fin_droite - largeur_jambe + 1;

        img[ligne][debut_gauche] = '.';
        for (int j = debut_gauche + 1; j < fin_gauche; j++)
            img[ligne][j] = 'S';
        img[ligne][fin_gauche] = '"';

        img[ligne][debut_droite] = '"';
        for (int j = debut_droite + 1; j < fin_droite; j++)
            img[ligne][j] = 'S';
        img[ligne][fin_droite] = '.';

        ligne++;
    }

    for (int i = 0; i < ligne; i++) {
        for (int j = 0; j < width; j++)
            printf("%c", img[i][j]);
        printf("\n");
    }

    return 0;
}
