#include <stdio.h>

int main() {
    int a = 5;
    int * pA = &a;
    *pA = 3;
    printf("%i, ", a);
    printf("%i", *pA);
}
