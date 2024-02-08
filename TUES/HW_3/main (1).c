#include <stdio.h>
#include "maths.h"

int main() {
    int num;
    scanf("%d", &num);
    unsigned long long result = factorial(num);

    printf("Factorial of %d is %llu\n", num, result);

    return 0;
}
