#include <stdio.h>

int main() {
    char c = 'A';
    printf("c = %c\n", c);
    return 0;
}
// il y a une erreur de type : on essaie d'afficher un caractère en utilisant le format de chaîne de caractères (%s). le programme devrait utiliser le format de caractère (%c) pour afficher la variable 'c', comme ceci : printf("c = %c\n", c);