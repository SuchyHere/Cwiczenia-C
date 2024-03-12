#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int ** matrix(int rows, int col){
    int **matrix = (int **) malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++){
        matrix[i] = (int*)malloc(col * sizeof(int));

    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j< col; j++){
            int r = rand() % 10;
            matrix[i][j] = r;
        }
    }
    return matrix;

}
int main() {
    srand(time(NULL));
    int x, y;
    printf("podaj ilosc wierszy w macierzy:");
    scanf("%d", &x);
    printf("podaj ilosc kolumn w macierzy:");
    scanf("%d", &y);
    int ** testMatrix = matrix(x,y);

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            printf("%d ", testMatrix[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < x; i++) {
        free(testMatrix[i]);
    }
    free(testMatrix);

    return 0;

}
