#include <math.h>
#include <stdio.h>

float l(float x) {
    return 7e-3 * pow(x, 4) + ((22.8 * cbrt(x) - 1000) * x + 3) / ((x * x) / 2) - x * pow(10 + x, 2.0 / x) -
           1.01;
}
int main() {
    float x;
    float result = 0;
    if (scanf("%f", &x) != 1) {
        printf("n/a");
        return 0;
    }
    if (x == 0) {
        printf("n/a");
        return 0;
    }
    result = l(x);
    printf("%.1f", result);
    return 0;
}
