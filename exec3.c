#include <stdio.h>

int main() {
    int x = 10;
    int y = x + 5;  
    printf("%d\n", y);
    return 0;
}
// il y a une erreur de syntaxe : la variable 'x' est déclarée sans être initialisée, ce qui provoque une erreur lors de la compilation. le programme devrait initialiser 'x' avec une valeur entière, par exemple "int x = 0;".