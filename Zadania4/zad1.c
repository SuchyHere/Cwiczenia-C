#include <stdio.h>

unsigned long long factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}
int main() {
    int number;
    printf("podaj liczbe ktorej silnie chcesz oblicztc: ");
    scanf("%d", &number);
    if (number < 0) {
        printf("nie ma silni z liczby ujemnej\n");
    } else {
        printf("silnia z %d = %llu\n", number, factorial(number));
    }

    return 0;
}


