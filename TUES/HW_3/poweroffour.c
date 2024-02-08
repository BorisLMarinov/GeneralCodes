#include <stdio.h>
#include <math.h>

void raiseToFourthPower(long arr[], int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = pow(arr[i], 4);
    }
}

int main() {
    long numbers[] = {2, 3, 4, 5, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    raiseToFourthPower(numbers, size);

    printf("Result after raising to the fourth power:\n");
    for (int i = 0; i < size; i++) {
        printf("%ld ", numbers[i]);
    }
    printf("\n");

    return 0;
}
