#include <stdio.h>

void change(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void print(int *a, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void permute(int *a, int start, int end) {
    if (start == end) {
        print(a, end + 1);
    } else {
        for (int i = start; i <= end; i++) {
            change(&a[start], &a[i]);
            permute(a, start + 1, end);
            change(&a[start], &a[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    permute(arr, 0, (sizeof(arr)/sizeof(arr[0])) - 1);
    return 0;
}
