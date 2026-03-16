#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "blindtest.h"

int main() {
    int taille = 10;
    int nb_songs = 0;
    Song *ma_liste = malloc(sizeof(Song) * taille);
    char reponse[MAX_STR];

    srand(time(NULL));

    
    nb_songs = load_songs("songs.txt", &ma_liste, &taille);

    if (nb_songs <= 0) {
        printf("Aucune chanson chargée. Fin du programme.\n");
        free(ma_liste);
        return 1;
    }

    printf("Bienvenue dans le Blind Test ! %d chansons chargées.\n", nb_songs);

    
    int index = rand() % nb_songs;
    
    printf("Écoutez l'extrait...\n");
    play_song_excerpt_at(ma_liste[index].file, 30, 10); 

    
    printf("Quel est le titre de cette chanson ? ");
    fgets(reponse, MAX_STR, stdin);
    trim_newline(reponse);

    if (string_equals_normalized(reponse, ma_liste[index].title)) {
        printf("BRAVO ! C'était bien '%s' de %s.\n", ma_liste[index].title, ma_liste[index].artist);
    } else {
        printf("Dommage... La réponse était '%s'.\n", ma_liste[index].title);
    }

    free(ma_liste);
    return 0;
}