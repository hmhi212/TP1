#include "blindtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void trim_newline(char *s) {
    size_t len = strlen(s);
    while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
        s[len - 1] = '\0';
        len--;
    }
}

void normalize_string(char *dest, const char *src) {
    int i = 0, j = 0, prev_space = 0;
    while (src[i] != '\0' && isspace((unsigned char)src[i])) i++;
    while (src[i] != '\0') {
        unsigned char c = (unsigned char)src[i];
        if (isspace(c)) {
            prev_space = 1;
        } else {
            if (prev_space && j > 0) dest[j++] = ' ';
            dest[j++] = (char)tolower(c);
            prev_space = 0;
        }
        i++;
    }
    dest[j] = '\0';
}

int string_equals_normalized(const char *a, const char *b) {
    char na[256], nb[256];
    normalize_string(na, a);
    normalize_string(nb, b);
    return strcmp(na, nb) == 0;
}

void play_song_excerpt_at(const char *filename, int start, int seconds) {
    char command[1024];
    snprintf(command, sizeof(command),
             "ffplay -nodisp -autoexit -loglevel quiet -ss %d -t %d \"%s\"",
             start, seconds, filename);
    system(command);
}

int load_songs(const char *filename, Song **songs, int *taille) {
    FILE *f = fopen(filename, "r");
    if (!f) {
        perror("Erreur ouverture fichier");
        return -1;
    }

    char line[1024];
    int count = 0;
    while (fgets(line, sizeof(line), f)) {
        trim_newline(line);
        if (strlen(line) == 0) continue;

        char *file = strtok(line, ";");
        char *title = strtok(NULL, ";");
        char *artist = strtok(NULL, ";");

        if (file && title && artist) {
            if (count >= *taille) {
                *taille *= 2;
                *songs = realloc(*songs, sizeof(Song) * (*taille));
            }
            strncpy((*songs)[count].file, file, MAX_STR);
            strncpy((*songs)[count].title, title, MAX_STR);
            strncpy((*songs)[count].artist, artist, MAX_STR);
            count++;
        }
    }
    fclose(f);
    return count;
}