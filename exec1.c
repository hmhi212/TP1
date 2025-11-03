#include <stdio.h>

int main() {
    int a = 2;
    int b = 10;
    int c = a / b;  // crash / comportement indéfini
    printf("%d\n", c);
    return 0;
}

/*Exception has occurred.
Arithmetic exception
*/
// il y a une erreur d'arithmétique : le programme tente de diviser un entier par zéro, ce qui provoque une exception d'exécution. le programme devrait vérifier que le dénominateur n'est pas zéro avant d'effectuer la division.