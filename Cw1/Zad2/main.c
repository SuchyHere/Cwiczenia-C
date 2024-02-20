#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {
    int grades[2][5];
    float mathsum = 0;
    float phissum = 0;
    // Inicjalizacja generatora liczb losowych
    srand(time(NULL));

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 5; j++) {
            // Przypisanie losowej wartości do każdej oceny
            grades[i][j] = rand() % 5 + 1;
        }
    }

    for (int i = 0; i < 5; i++) {
        mathsum += grades[0][i];
        phissum += grades[1][i];
    }
    printf("Srednia z matematyki: %.2f, Srednia z fizyki: %.2f\n",mathsum / 5, phissum / 5);

    return 0;
}
