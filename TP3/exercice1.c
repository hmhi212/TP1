#include <stdio.h>

int main() {
    int n;
    
    printf("Entrez la taille de l'etoile (entre 5 et 10) : ");
    scanf("%d", &n);
    if (n<5 || n>10){
        printf(" entreez une taille valide");
    }
    int width = n * n;
    int max_height = n + 1;
    char img[100][100];
    for (int i = 0; i < max_height; i++) {
        for (int j = 0; j < width; j++) {
            img[i][j] = ' ';
           
        }
        
    }
   int mid = width / 2;
    for (int i = 0; i < n; i++) {
        for (int j = mid - i; j <= mid + i; j++) {
            if (j == mid - i || j == mid + i) {
                img[i][j] = 'A'; 
            } else {
                img[i][j] = 'S'; 
            }
        }
    }
        for (int j = 0; j <= mid - n; j++) {
    img[n-1][j] = '_';
    }

 
    for (int j = mid + n; j < width; j++) {
        img[n-1][j] = '_';
    }
   
    for (int j = 0; j < width; j++) {
    if (j == 0 || j == width - 1)
        img[n][j] = '"';       
    else
        img[n][j] = 'S';       
}

     for(int i=0; i<= max_height; i++){
        for(int j=0; j<=width; j++){
            printf("%c",img[i][j]);
            
        }
        printf("\n");
    }
 return 0;       
}
   