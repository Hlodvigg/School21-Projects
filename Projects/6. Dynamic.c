#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

void print_matrix(int **matrix, int rows, int cols) {
  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      if (j > 0)
        printf(" ");
      printf("%d", matrix[i][j]);
    }
    if (i < rows - 1)
      printf("\n");
  }
}

void free_matrix(int **matrix, int rows) {
  for (int i = 0; i < rows; ++i)
    free(matrix[i]);
  free(matrix);
}

int static_allocation() {
  int matrix[MAX_SIZE][MAX_SIZE];
  int rows, cols;
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0 ||
      rows > MAX_SIZE || cols > MAX_SIZE)
    return 0;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (scanf("%d", &matrix[i][j]) != 1)
        return 0;
  print_matrix((int **)matrix, rows, cols);
  return 1;
}

int dynamic_allocation_1() {
  int rows, cols;
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
    return 0;
  int **matrix = malloc(rows * sizeof(int *));
  if (!matrix)
    return 0;
  for (int i = 0; i < rows; ++i) {
    matrix[i] = malloc(cols * sizeof(int));
    if (!matrix[i]) {
      free_matrix(matrix, i);
      return 0;
    }
  }
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (scanf("%d", &matrix[i][j]) != 1) {
        free_matrix(matrix, rows);
        return 0;
      }
  print_matrix(matrix, rows, cols);
  free_matrix(matrix, rows);
  return 1;
}

int dynamic_allocation_2() {
  int rows, cols;
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
    return 0;
  int *data = malloc(rows * cols * sizeof(int));
  int **matrix = malloc(rows * sizeof(int *));
  if (!data || !matrix) {
    free(data);
    free(matrix);
    return 0;
  }
  for (int i = 0; i < rows; ++i)
    matrix[i] = data + i * cols;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (scanf("%d", &matrix[i][j]) != 1) {
        free(data);
        free(matrix);
        return 0;
      }
  print_matrix(matrix, rows, cols);
  free(data);
  free(matrix);
  return 1;
}

int dynamic_allocation_3() {
  int rows, cols;
  if (scanf("%d %d", &rows, &cols) != 2 || rows <= 0 || cols <= 0)
    return 0;
  int **matrix = malloc(rows * sizeof(int *));
  if (!matrix)
    return 0;
  matrix[0] = malloc(rows * cols * sizeof(int));
  if (!matrix[0]) {
    free(matrix);
    return 0;
  }
  for (int i = 1; i < rows; ++i)
    matrix[i] = matrix[0] + i * cols;
  for (int i = 0; i < rows; ++i)
    for (int j = 0; j < cols; ++j)
      if (scanf("%d", &matrix[i][j]) != 1) {
        free(matrix[0]);
        free(matrix);
        return 0;
      }
  print_matrix(matrix, rows, cols);
  free(matrix[0]);
  free(matrix);
  return 1;
}

int main() {
  int choice;
  if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
    printf("n/a");
    return 1;
  }

  int success = 0;
  switch (choice) {
  case 1:
    success = static_allocation();
    break;
  case 2:
    success = dynamic_allocation_1();
    break;
  case 3:
    success = dynamic_allocation_2();
    break;
  case 4:
    success = dynamic_allocation_3();
    break;
  }

  if (!success)
    printf("n/a");

  return success ? 0 : 1;
}
