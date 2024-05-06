#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void update_count(char *token, int *r, int *g, int *b) {
    char *ptr = token;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            int count = strtol(ptr, &ptr, 10);
            while (*ptr == ' ') ptr++;
            if (strncmp(ptr, "red", 3) == 0 && count > *r) {
                *r = count;
                ptr += 3;
            } else if (strncmp(ptr, "green", 5) == 0 && count > *g) {
                *g = count;
                ptr += 5;
            } else if (strncmp(ptr, "blue", 4) == 0 && count > *b) {
                *b = count;
                ptr += 4;
            }
        } else {
            ptr++;
        }
    }
}

int main() {
    FILE *file = fopen("/Users/suchy/Downloads/input_2.txt", "r");
    if (file == NULL) {
        printf("Nie można otworzyć pliku.\n");
        return 1;
    }

    char line[256];
    int game_count = 1;

    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = '\0';

        char *token = strtok(line, ";");
        int turn_count = 1;
        int impossible = 0;

        int max_red = 0, max_green = 0, max_blue = 0;

        printf("Gra %d:\n", game_count);

        while (token != NULL) {
            if (turn_count == 1) {
                token += 9;
            }

            int r = 0, g = 0, b = 0;
            update_count(token, &r, &g, &b);

            if (red > 12 || green > 13 || blue > 14) {
                impossible = 1;
            }

            if (r > max_red) max_red = red;
            if (g > max_green) max_green = green;
            if (b > max_blue) max_blue = blue;

            printf(" %d: %s\n", turn_count, token);

            token = strtok(NULL, ";");
            turn_count++;
        }

        printf("Do rozegrania gry potrzeba: %d czerwonych, %d zielonych, %d niebieskich kostek\n", max_red, max_green, max_blue);

        if (impossible) {
            printf("Gra %d jest niemozliwa\n", game_count);
        }

        game_count++;
    }

    fclose(file);
    return 0;
}
