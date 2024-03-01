#include <stdio.h>

void multiply(float * d) {
    *d *= 2;
}

int main() {
    float  b = 4.3;
    multiply(&b);
    printf("%f", b);
}



