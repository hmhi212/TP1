#include <stdio.h>

int main() {
    char s[5];
    s[0] = 'H';
    s[1] = 'e';
    s[2] = 'y';
    s[3] = '!';
    s[4] = '\0';
    printf("%s\n", s); 
    return 0;
}
//il faut rajouter un caractere de fin de chaine '\0' a la fin du tableau de caracteres pour que printf puisse afficher correctement la chaine.