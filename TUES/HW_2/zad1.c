#include <stdio.h>

#define DEBUG
#define ARRSIZE 10

void sortAndFindSum(int arr[], int n) {
    int temp;
    int s = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    for (int i = 3; i < n; i+=3) {
            s += arr[i];
    }
    printf("%d\n", s);

    #ifdef DEBUG
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        for (int i = 3; i < n; i+=3) {
            if (arr[i] % 3 == 0) {
                printf("%d ", arr[i]);
            }
        }
        printf("\n");
    #endif
}

int main() {
    int arr[ARRSIZE];
    for(int i = 0; i < ARRSIZE;i++){
        scanf("%d", &arr[i]);
    }

    sortAndFindSum(arr, ARRSIZE);

    return 0;
}
