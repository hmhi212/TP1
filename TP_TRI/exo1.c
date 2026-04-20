#include <stdio.h>
#include "exo1.h"

int comparerDates(Date d1, Date d2) {
    if (d1.annee != d2.annee) return d1.annee - d2.annee;
    if (d1.mois != d2.mois) return d1.mois - d2.mois;
    return d1.jour - d2.jour;
}

void saisirEtTrier(Medicament Tab[80]) {
    for (int i = 0; i < 80; i++) {
        scanf("%s %d %d %d %d %d %d %d %f %d %d", Tab[i].nom, &Tab[i].code, &Tab[i].dateFab.jour, &Tab[i].dateFab.mois, &Tab[i].dateFab.annee,&Tab[i].datePeremp.jour, &Tab[i].datePeremp.mois, &Tab[i].datePeremp.annee, &Tab[i].prix, &Tab[i].nbVendus, &Tab[i].nbStock); 
    }

    for (int i = 0; i < 79; i++) {
        for (int j = 0; j < 79 - i; j++) {
            if (comparerDates(Tab[j].datePeremp, Tab[j + 1].datePeremp) > 0) {
                Medicament temp = Tab[j];
                Tab[j] = Tab[j + 1];
                Tab[j + 1] =temp;
            }
        }
    } 
}