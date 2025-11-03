#include <stdio.h>

int main() {
    int x = 10;
    printf("x = %d\n", x);
    return 0;
}
/*  .\compil8.c: In function 'main':
.\compil8.c:5:24: error: 'y' undeclared (first use in this function)
     printf("x = %d\n", y);
                        ^
.\compil8.c:5:24: note: each undeclared identifier is reported only once for each function it appears in
*/
// il y a une erreur de déclaration : la variable 'y' est utilisée sans avoir été déclarée au préalable. donc faut mettre x a la place de y .