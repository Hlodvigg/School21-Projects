#include <stdio.h>
#include <stdlib.h>

int read_array(int **arr, int *size);
void sort_array(int *arr, int size);
void print_array(const int *arr, int size);

int main() {
    int *data = NULL;
    int n;

    if (read_array(&data, &n) == 0) {
        printf("n/a");
        free(data);
        return 0;
    }

    sort_array(data, n);
    print_array(data, n);

    free(data);
    return 0;
}

int read_array(int **arr, int *size) {
    if (scanf("%d", size) != 1 || *size <= 0) {
        return 0;
    }

    *arr = (int *)malloc(*size * sizeof(int));
    if (*arr == NULL) {
        return 0;
    }

    for (int i = 0; i < *size; i++) {
        if (scanf("%d", &(*arr)[i]) != 1) {
            free(*arr);
            return 0;
        }
    }
    return 1;
}

void sort_array(int *arr, int size) {
    for (int i = 0; i < size - 1; i++) {
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
