#include <stdio.h>
#include "transformation.h"

int main() {
    const char* input;
    scanf("%c", &input);

    struct transformation result = transformStringToNumber(input);

    printf("Input: \"%s\" => Output: result = %ld, error = \"%s\"\n", input, result.result, result.error);

    return 0;
}
