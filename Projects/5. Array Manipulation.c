#include <stdio.h>

#define MAX_SIZE 10

int input(int *arr, int *n, int *shift);
int gcd(int a, int b);
void cycle_shift_left(int *arr, int n, int c);
void output(const int *arr, int n);

int main() {
    int data[MAX_SIZE];
    int n, shift;

    if (input(data, &n, &shift) == 0) {
        printf("n/a");
        return 0;
    }

    cycle_shift_left(data, n, shift);
    output(data, n);

    return 0;
}

int input(int *arr, int *n, int *shift) {
    if (scanf("%d", n) != 1) return 0;
    if (*n <= 0 || *n > MAX_SIZE) return 0;

    for (int i = 0; i < *n; i++) {
        if (scanf("%d", &arr[i]) != 1) return 0;
    }

    if (scanf("%d", shift) != 1) return 0;

    return 1;
}

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void cycle_shift_left(int *arr, int n, int c) {
    if (n == 0) return;

    c = c % n;
    if (c < 0) {
        c = n + c;
    }
    if (c == 0) {
        return;
    }

    int num_cycles = gcd(n, c);

    for (int i = 0; i < num_cycles; i++) {
        int temp = arr[i];
        int j = i;

        while (1) {
            int k = j + c;
            if (k >= n) k -= n;
            if (k == i) break;
            arr[j] = arr[k];
            j = k;
        }
        arr[j] = temp;
    }
}

void output(const int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
}
