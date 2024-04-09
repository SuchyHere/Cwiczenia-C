#include <stdio.h>
int adding(int a, int b){
    int c = a + b;
    return c;
}

float multiplying (int a, int b){
    float c = a * b;
    return c;
}

int subtracting (int a, int b){
    int c = a - b;
    return c;
}
int main() {
    int (*add)(int, int);
    add = & adding;
    float (*multiply) (int, int);
    multiply = & multiplying;
    int (*substract) (int, int);
    substract = & subtracting;

    printf("jaka funkcje chcesz wywolac? dodawanie - 1, odejmowanie - 2, mnozenie - 3");
    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            printf("Wynik dodawania: %d\n", add(2,3));
            break;
        case 2:
            printf("Wynik odejmowania: %d\n", substract(2,3));
            break;
        case 3:
            printf("Wynik mnożenia: %.2f\n", multiply(2, 3));
            break;
        default:
            printf("Niepoprawna opcja.\n");
            break;
    }
}
