#include <stdio.h>

int main() {
    int x;
    int y;
    if (scanf("%d %d", &x, &y) != 2) {
        printf("n/a");
    }
    if (y != 0) {
        printf("%d %d %d %d", x + y, x - y, x * y, x / y);
    } else {
        printf("%d %d %d %s", x + y, x - y, x * y, "n/a");
    }
    return 0;
}
