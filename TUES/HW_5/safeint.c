#include "safeint.h"
#include "util.h"
#include <stdio.h>

struct SafeResult safeadd(int a, int b) {
    struct SafeResult result;
    result.errorflag = __builtin_add_overflow(a, b, &result.value);
    return result;
}

struct SafeResult safesubtract(int a, int b) {
    struct SafeResult result;
    result.errorflag = __builtin_sub_overflow(a, b, &result.value);
    return result;
}

struct SafeResult safemultiply(int a, int b) {
    struct SafeResult result;
    result.errorflag = __builtin_mul_overflow(a, b, &result.value);
    return result;
}

struct SafeResult safedivide(int a, int b) {
    struct SafeResult result;
    if (b == 0) {
        result.errorflag = 1;
        return result;
    }
    result.value = a / b;
    result.errorflag = 0;
    return result;
}

struct SafeResult safestrtoint(const char *str) {
    struct SafeResult result;
    int scanned = sscanf(str, "%d", &result.value);
    if (scanned == 0) {
        result.errorflag = 1;
    } else if (scanned == EOF) {
        result.errorflag = 1;
    } else {
        struct SafeResult addResult = safeadd(result.value, 0);
        struct SafeResult multiplyResult = safemultiply(result.value, 1);
        result.errorflag = addResult.errorflag || multiplyResult.errorflag;
    }
    return result;
}
