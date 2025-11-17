#include <stdio.h>

int main() {
    int n;
    
    printf("Entrez la taille de l'etoile (entre 5 et 10) : ");
    scanf("%d", &n);
    if (n<5 || n>10){
        printf(" entreez une taille valide");
    }
    int width = n * n;
    int max_height = 3* n-1 ;
    char img [11][11] ;
    for (int i=0 ; i<width ; i++){
        for(int j=0 ; j<max_height ; j++){
            img[i][j] ='';
            
        }
    }
}
   