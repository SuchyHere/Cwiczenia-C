#include <stdio.h>

int main() {
    int number;
    int count = 0;
    printf("podaj liczbe: ");
    // test czy wpisana rzecz to int
    if (scanf("%d", &number) == 1) {
        if (number % 3 == 0 && number % 5 == 0){
            // zwracanie podanej liczby jesli jest podzielna przez 3 i 5
            printf("%i", number);
        }
        else if(number < 0){
            // zwracanie 0 gdy liczba jest ujemna
            printf("0");
        }
        else{
            for (int i = 1; i < number; i++)
            {
                // zliczanie sumy wielokrotnosci 3 i 5 nizszych niz podana liczba
                if (i % 3 == 0 | i % 5 == 0){
                    count += i;
                }
            }
            printf("%i", count);
        }
    } else {
        printf("podano cos innego niz liczbe");
    }
}

