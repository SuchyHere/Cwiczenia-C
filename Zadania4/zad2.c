#include <stdio.h>

int search(int array[], int l, int r, int x) {
    if (r >= l) {
        int mid = r / 2;
        if (array[mid] == x) return mid;
        if (array[mid] > x) return search(array, l, mid - 1, x);
        return search(array, mid + 1, r, x);
    }
    return -1;
}

int main() {
    int array[] = {2, 3, 4,7, 9, 10, 40, 50, 80};
    int n = (sizeof(array) / sizeof(array[0])) - 1;
    int x = 9; // zmienna ktorej szukamy w tablicy
    int result = search(array, 0, n, x);

    if (result == -1)
        printf("nie ma takiego elementu w tablicy");
    else
        printf("element znajduje sie na pozycji: %d", result);

    return 0;
}
