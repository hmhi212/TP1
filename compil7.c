#include <stdio.h>

// ici le comilateur ne dit malheureusement rien mais il devrait,
// executer pour essayer de comprendre ce qu'il se passe 
int main() {
    int tableau[5]; 
    int i = 12;
    for (int j = 0; j < 5; j++)
    {
        tableau[j] = 1;
    }
    printf("OK %d\n", tableau[4]);
    return 0;
}
// il y a un dépassement de tableau : la boucle for tente d'accéder à des indices en dehors des limites du tableau 'tableau', ce qui peut entraîner un comportement indéfini. 