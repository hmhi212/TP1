#ifndef SUIVI_H
#define SUIVI_H

typedef enum {
    EAU,
    CAFE,
    BONBONS,
    GATEAU,
    LEGUMES,
    FRUITS,
    PROTEINES,
    NB_CATEGORIES
} Categorie;

void afficherMenu();
int lireChoix();
void initialiser(int *conso, int size);
void ajouterConsommation(int *conso, int size, const char *categories[], const char *emojis[]);
void afficherResume(int *conso, int size, const char *categories[], const char *emojis_fixes[], const char *h_bonbons[], const char *h_legumes[], const char *h_fruits[], int max_val);
int charger(int *conso, int size);
int sauvegarder(int *conso, int size);
void afficherObjectifsEtScore(int *conso, const int *objectifs, int size, const char *categories[]);
int calculerScoreSante(const int *conso, const int *objectifs, int size);

int humeurBonbons(int nbBonbons);
int humeurLegumes(int nbLegumes);
int humeurFruits(int nbFruits);

void afficherBarre(int valeur, int max);
void utf8();

#endif
