#include <stdio.h>

int main(){
    int a, b;
    printf("first number ");
    scanf("%d", &a);
    printf("second number ");
    scanf("%d", &b);


    int kratno = (a > b) ? a : b;

    while (1) {
        if (kratno % a == 0 && kratno % b == 0) {
            printf("NOK na %d i %d e %d\n", a, b, kratno);
            break;
        }
        kratno++;
    }

    return 0;
}