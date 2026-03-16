#ifndef BLINDTEST
#define BLINDTEST

#define MAX_STR 100

typedef struct {
    char file[MAX_STR];
    char title[MAX_STR];
    char artist[MAX_STR];
} Song;


void trim_newline(char *s);
void normalize_string(char *dest, const char *src);
int string_equals_normalized(const char *a, const char *b);
void play_song_excerpt_at(const char *filename, int start, int seconds);
int load_songs(const char *filename, Song **songs, int *taille);

#endif