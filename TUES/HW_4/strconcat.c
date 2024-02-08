#include <stdio.h>
#include <stdlib.h>
#include "mystrings.h"

void copyString(char dest[], char src[]) {
    int i;
    for(i = 0; src[i] != '\0' && i < 50; i++) {
        dest[i] = src[i];
    }
    dest[i] = '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments! Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    char str1[100];
    copyString(str1, argv[1]);
    strconcat(str1, argv[2]);

    printf("%s\n", str1);

    return 0;
}
