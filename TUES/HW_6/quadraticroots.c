#include<stdio.h>
#include "quadraticroots.h"
#include <math.h>

QuadraticRootsResult findroots(double a, double b, double c) {
    QuadraticRootsResult result;

    double D = b * b - 4 * a * c;

    if (D < 0) {
        result.norealroots = 1;
    } else {
        result.norealroots = 0;
        result.x1 = (-b + sqrtl(D)) / (2 * a);
        result.x2 = (-b - sqrtl(D)) / (2 * a);
    }

    return result;
}
