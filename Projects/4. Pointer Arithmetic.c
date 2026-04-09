#include <stdio.h>

#define ARRAY_SIZE 10

int read_array(int *arr);
void sort_array(int *arr, int size);
void print_array(const int *arr, int size);

int main() {
    int data[ARRAY_SIZE];

    if (read_array(data) == 0) {
        printf("n/a");
        return 0;
    }

    sort_array(data, ARRAY_SIZE);

    print_array(data, ARRAY_SIZE);

    return 0;
}

int read_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0;
        }
    }
    return 1;
}

void sort_array(int *arr, int size) {
    int i;

    for (i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}

void print_array(const int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(" ");
        }
    }
}
