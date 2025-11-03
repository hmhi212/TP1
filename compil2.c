#include <stdio.h>

int main() {
    int x = 42;
    printf("%d\n", x);
    return 0;
}
/* .\compil2.c: In function 'main':
.\compil2.c:4:13: warning: initialization makes integer from pointer without a cast [-Wint-conversion]
     int x = "42";
     */
// il y a une erreur de type : on essaie d'initialiser un entier avec une chaîne de caractères. le programme devrait initialiser x avec une valeur entière, par exemple int x = 42;