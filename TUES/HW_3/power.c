#include <stdio.h>
#define POWER(A,B) ((A + B) * (A + B))
int main(){
    int A,B;
    scanf("%d", &A);
    scanf("%d", &B);
    printf("%d",POWER(A,B));
    return 0;
}