#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "blindtest.h"

int main() {
    int taille = 10;
    int nb_songs = 0;
    int score = 0;
    Song *ma_liste = malloc(sizeof(Song) * taille);
    char reponse[MAX_STR];
    char pseudo[MAX_STR];

    srand(time(NULL));

   
    nb_songs = load_songs("songs.txt", &ma_liste, &taille);

    if (nb_songs <= 0) {
        printf("Aucune chanson chargée. Fin du programme.\n");
        if (ma_liste) free(ma_liste);
        return 1;
    }

   
    melanger_chansons(ma_liste, nb_songs);

    printf("Bienvenue dans le Blind Test !\n");
    printf("Entrez votre pseudo : ");
    fgets(pseudo, MAX_STR, stdin);
    trim_newline(pseudo);

   
    for (int i = 0; i < nb_songs; i++) {
        printf("\n--- Chanson %d / %d ---\n", i + 1, nb_songs);
        
       
        printf("Écoutez l'extrait...\n");
        play_song_excerpt_at(ma_liste[i].file, 30, 10); 

        printf("Quel est le titre de cette chanson ? ");
        fgets(reponse, MAX_STR, stdin);
        trim_newline(reponse);

        if (string_equals_normalized(reponse, ma_liste[i].title)) {
            printf("BRAVO ! +1 point.\n");
            score++;
        } else {
            printf("Dommage... La réponse était '%s' de %s.\n", ma_liste[i].title, ma_liste[i].artist);
        }
    }

    
    printf("\nPartie terminée, %s ! Votre score final est : %d/%d\n", pseudo, score, nb_songs);

    
    free(ma_liste);
    return 0;
}