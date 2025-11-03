#include <stdio.h>

int main() {
    if (1) {
        printf("ok\n");
    } else{
        printf("nope\n");
        }
    return 0;
}
/*.\compil11.c:9:5: error: expected identifier or '(' before 'return'
     return 0;
     ^~~~~~
.\compil11.c:10:1: error: expected identifier or '(' before '}' token
 }*/
// il y a une erreur de syntaxe : il y a une accolade fermante '}' en trop à la fin du bloc 'else', ce qui provoque une erreur de compilation. le programme devrait supprimer cette accolade supplémentaire pour corriger l'erreur.