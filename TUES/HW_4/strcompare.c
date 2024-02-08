#include <stdio.h>
#include "mystrings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Invalid arguments! Usage: %s <string1> <string2>\n", argv[0]);
        return 1;
    }

    int result = strcompare(argv[1], argv[2]);
    printf("%d\n", result);

    return 0;
}
