#include <stdio.h>

int main() {
    int t[3] = {10, 20, 30};
    int i = 0;
    printf("%d\n", t[i]); 
    return 0;
}
// il y a une erreur de syntaxe : la variable 'i' est déclarée sans être initialisée, ce qui provoque une erreur lors de la compilation. le programme devrait initialiser 'i' avec une valeur entière, par exemple "int i = 0;". 