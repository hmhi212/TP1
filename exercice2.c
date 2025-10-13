#include <stdio.h>
#include <math.h>

int main() {
    int pret;
    float taux_interet;
    int duree;
    int mensualite;
    printf("Entrez le montant du pret : ");
    scanf("%d", &pret);
    printf("Entrez le taux d'interet (en pourcentage) : ");
    scanf("%f", &taux_interet);
    printf("Entrez la durée du pret (en années) : ");
    scanf("%d", &duree);
    taux_interet = taux_interet / 100; 
    mensualite = (pret * (taux_interet/12)) / 1 - pow(1 + taux_interet/12, -(duree) * 12);
    printf("La mensualité est de : %d\n", mensualite);
    printf("Le coût total du crédit est de : %d\n", mensualite * duree * 12);

return 0;
}