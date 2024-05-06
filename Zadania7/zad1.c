#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int findNumber(char *word) {
    if (strcmp(word, "zero") == 0) return 0;
    else if (strcmp(word, "one") == 0) return 1;
    else if (strcmp(word, "two") == 0) return 2;
    else if (strcmp(word, "three") == 0) return 3;
    else if (strcmp(word, "four") == 0) return 4;
    else if (strcmp(word, "five") == 0) return 5;
    else if (strcmp(word, "six") == 0) return 6;
    else if (strcmp(word, "seven") == 0) return 7;
    else if (strcmp(word, "eight") == 0) return 8;
    else if (strcmp(word, "nine") == 0) return 9;
    else return -1;
}

int main() {
    char line[100];

    FILE *filePointer;

    filePointer = fopen("/Users/suchy/Downloads/input.txt", "r");
    if (filePointer == NULL) {
        printf("zla nazwa pliku\n");
        return 1;
    }

    while (fgets(line, 100, filePointer) != NULL) {
        int first = -1, last = -1;

        for (int i = 0; line[i] != '\0'; i++) {
            char character = line[i];
            if (isdigit(character)) {
                if (first == -1) first = character - '0';
                last = character - '0';
            } else if (isalpha(character)) {
                char word[6];
                for (int j = 0; j < 5 && (i + j) < 100; j++) {
                    word[j] = line[i + j];
                    word[j + 1] = '\0';
                    int number = findNumber(word);
                    if (number != -1) {
                        if (first == -1) first = number;
                        else last = number;
                    }
                }
            }
        }

        printf("%s : %d%d\n", line, first, last);
    }
    fclose(filePointer);

    return 0;
}
