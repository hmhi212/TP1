#include <stdio.h>

int main() {
    int x = 10;
    if (x == 5) {
        printf("x vaut 5\n");
    }
    return 0;
}
// il y a une erreur de comparaison : l'opérateur d'égalité '==' est utilisé au lieu de l'opérateur d'affectation '='. le programme devrait utiliser '=' pour assigner la valeur 5 à la variable x, comme ceci : if (x = 5) { ... }