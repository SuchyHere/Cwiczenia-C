#include <stdio.h>

union u {
    int i;
    float f;
    char c;
};

int main() {
    union u u;

    u.i = 10;
    printf("int : %d\n", u.i);

    u.f = 220.5;
    printf("float : %f\n", u.f);

    u.c = 'A';
    printf("char : %c\n", u.c);

    return 0;
}
