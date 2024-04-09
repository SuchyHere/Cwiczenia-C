#include <stdio.h>
float adding(int a, int b){
    int c = a + b;
    return c;
}

float multiplying (int a, int b){
    float c = a * b;
    return c;
}

float subtracting (int a, int b){
    int c = a - b;
    return c;
}
int main() {
    float (*pointer) (int, int);

    printf("jaka funkcje chcesz wywolac? dodawanie - 1, odejmowanie - 2, mnozenie - 3");
    int option;
    scanf("%d", &option);

    switch (option) {
        case 1:
            pointer = & adding;
            printf("Wynik dodawania: %.2f\n", pointer(2,3));
            break;
        case 2:
            pointer = & subtracting;
            printf("Wynik odejmowania: %.2f\n", pointer(2,3));
            break;
        case 3:
            pointer = &multiplying;
            printf("Wynik mnożenia: %.2f\n", pointer(2, 3));
            break;
        default:
            printf("Niepoprawna opcja.\n");
            break;
    }
}
