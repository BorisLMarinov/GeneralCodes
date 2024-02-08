#include <stdio.h>
#include "util.h"

void print_error(const char *message) {
    fprintf(stderr, "Error: %s\n", message);
}
