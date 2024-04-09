#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main() {
    int array[10];
    srand(time(NULL));
    for (int i = 0; i<10; i++){
        array[i] = rand() % 10;
    }
    int *pointer = &array[0];
    for (int i = 0; i<10; i++){
        printf("%i ", *pointer);
        pointer ++;
    }
}
