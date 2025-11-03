#include <stdio.h>

int main() {
    char nom[6];
    printf("Nom ? ");
    scanf("%s", &nom); 
    printf("Bonjour %s\n", nom);
    return 0;
}
// il y a une erreur de scanf : l'adresse de la variable 'nom' est incorrectement obtenue en utilisant '&nom', ce qui peut provoquer un comportement indéfini. le programme devrait utiliser simplement 'nom' sans l'opérateur '&' dans l'appel à scanf, comme ceci : scanf("%s", nom);
