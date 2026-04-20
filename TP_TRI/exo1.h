#ifndef MEDICAMENT_H
#define MEDICAMENT_H

typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char nom[50]; 
    int code; 
    Date dateFab; 
    Date datePeremp;
    float prix;
    int nbVendus;
    int nbStock;
} Medicament;

int comparerDates(Date d1, Date d2);
void saisirEtTrier(Medicament Tab[80]); 
void rechercheParacetamol(Medicament Tab[80]); 
#endif