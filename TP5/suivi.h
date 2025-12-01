#ifndef SUIVI_H
#define SUIVI_H

void afficherMenu();
int lireChoix();
void initialiser(int *conso, int size);
void ajouterConsommation(int *conso, int size, const char *categories[]);
void afficherResume(int *conso, int size, const char *categories[], const char *emojis_fixes[], const char *h_bonbons[], const char *h_legumes[], const char *h_fruits[], int max_val);
#endif