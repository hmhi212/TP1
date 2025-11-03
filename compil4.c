#include <stdio.h>

int main {
    printf("Test\n");
    return 0;
}
/* .\compil4.c:3:10: error: expected '=', ',', ';', 'asm' or '__attribute__' before '{' token
 int main {
          ^
*/
// il manque des parenthèses après main pour définir la fonction correctement. le programme devrait être corrigé en ajoutant des parenthèses vides, comme ceci : int main() {