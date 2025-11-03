#include <stdio.h>

int main() {
    int a = 10;
    int b = 20;
    printf("a=%d b=%d\n", a, b); 
    return 0;
}
// il y a une erreur d'affichage : la variable 'a' est déclarée mais jamais utilisée dans l'instruction printf. le programme devrait inclure 'a' dans la liste des arguments de printf pour afficher sa valeur, comme ceci : printf("a=%d b=%d\n", a, b);