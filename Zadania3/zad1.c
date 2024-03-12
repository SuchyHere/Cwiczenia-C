#include <stdio.h>
long long factorial (int n){
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}
void pascal(int N){
    for (int n = 0; n < N; n++) {
        for (int k = 0; k <= n; k++) {
            printf("%lld ", factorial(n) / (factorial(k) * factorial(n - k)));
        }
        printf("\n");
    }
}

int main() {
    int a;
    printf("podaj wielkosc trojkata");
    scanf("%d", &a);
    pascal(a);
    return 0;
}
