#include <stdio.h>

int main() {
    char s[6] = "Hello";
    printf("%s\n", s);
    return 0;
}
/*.\compil9.c: In function 'main':
.\compil9.c:4:17: warning: initializer-string for array of chars is too long
     char s[3] = "Hello";
*/
// il y a une erreur de taille de tableau : le tableau 's' est déclaré avec une taille de 3, mais la chaîne "Hello" nécessite au moins 6 emplacements (5 caractères plus le caractère nul de fin). le programme devrait déclarer 's' avec une taille suffisante, par exemple "char s[6] = "Hello";".