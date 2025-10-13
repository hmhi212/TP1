#include <stdio.h>
#include <stdlib.h>

int main() {
    int seconds;
    printf("entrez nombre de second\n");
    scanf("%d", &seconds);
    int hours = seconds / 3600;
    int minutes = (seconds % 3600) / 60;
    int remaining_seconds = seconds % 60;
    printf("%d heures, %d minutes, %d secondes\n", hours, minutes, remaining_seconds);

    return 0;
}