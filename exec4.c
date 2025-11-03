#include <stdio.h>

int main() {
    int i = 0;
    while (i < 10) {
        printf("%d\n", i++);
    }
    return 0;
}
// il y a une erreur de boucle infinie : la variable 'i' n'est jamais incrémentée à l'intérieur de la boucle while, ce qui entraîne une boucle infinie. le programme devrait inclure une instruction pour incrémenter 'i', par exemple "i++;", à l'intérieur de la boucle.