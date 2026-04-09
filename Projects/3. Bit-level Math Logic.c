#include <math.h>
#include <stdio.h>

int largest_prime_factor(int a) {
  if (a == 0)
    return -1;

  int n;
  if (a < 0) {
    n = -a;
  } else {
    n = a;
  }
  int candidate = 2;

  while (candidate * candidate <= n) {
    int temp = n;
    while (temp >= candidate) {
      temp -= candidate;
    }

    if (temp == 0) {
      int quotient = 0;
      while (n >= candidate) {
        n -= candidate;
        quotient++;
      }
      n = quotient;
    } else {
      candidate++;
    }
  }
  if (n > 1) {
    return n;
  }
  return candidate - 1;
}

int main() {
  int a;

  if (scanf("%d", &a) != 1) {
    printf("n/a");
    return 0;
  }

  int result = largest_prime_factor(a);

  if (result == -1) {
    printf("n/a");
  } else {
    printf("%d", result);
  }

  return 0;
}
