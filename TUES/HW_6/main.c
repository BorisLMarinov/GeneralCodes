#include "quadraticroots.h")
#include <stdio.h>

int main() {
    QuadraticRootsResult result1 = findroots(1, -3, 2);
    printf("x1=%.2f, x2=%.2f, hasrealroots=%d\n", result1.x1, result1.x2, result1.norealroots);

    QuadraticRootsResult result2 = findroots(1.0, -2.5, 1.5);
    printf("x1=%.2f, x2=%.2f, hasrealroots=%d\n", result2.x1, result2.x2, result2.norealroots);

    QuadraticRootsResult result3 = findroots(1.5, -4.0, 2.5);
    printf("x1=%.2f, x2=%.2f, hasrealroots=%d\n", result3.x1, result3.x2, result3.norealroots);

    return 0;
}
