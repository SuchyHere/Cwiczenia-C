#include <stdio.h>
void power(int list[10]){
    int temp;
    for (int i = 0; i < 10; i ++){
        temp = 1;
        for (int j = 1; j <= list[i]; j++){
            temp *= j;
        }
        printf("Silnia z %i to %i\n", list[i], temp);
    }
}
int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    power(array);
    return 0;
}
