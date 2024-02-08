#include <stdio.h>

#define ARRAY_SIZE 10

int main() {
#if defined (ARRAY_SIZE) && (ARRAY_SIZE >= 1) && (ARRAY_SIZE <= 10)
    int array[ARRAY_SIZE];
    int power = 1;

    for (int i = 0; i < ARRAY_SIZE; i++) {
        array[i] = power;
        power *= 2;
    }

    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d\n", array[i]);
    }
#else
    printf("The app doesn't support an array of this size\n");
#endif

    return 0;
}
