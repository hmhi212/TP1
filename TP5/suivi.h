#ifndef SUIVI_H
#define SUIVI_H

void afficherMenu();
int lireChoix();
void initialiser(int *conso, int size);
void ajouterConsommation(int *conso, int size, const char *categories[]);
#endif