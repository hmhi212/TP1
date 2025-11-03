#include <stdio.h>

int main() {
    int tab[10];
    
    for (int i = 0; i < 10; i++) {
        tab[i] = i;  
    }
    for (int i = 0; i < 10; i++) {
        printf("%d\n",tab[i]);  
    }
    printf("fait\n");
    return 0;
}
// il y a une erreur de tab il n'y a que 5 elements dans le tableau mais la boucle for essaye d'acceder a 10 elements.