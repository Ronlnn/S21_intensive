#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n, data[NMAX];
  if (input(data, &n) == -1) {
    printf("n/a");
    return 0;
  }
  squaring(data, n);
  output(data, n);

  return 0;
}

int input(int *a, int *n) {
  if (scanf("%d", n) != 1) {
    return -1;
    if (*n <= 0 && *n > NMAX) {
      return -1;
    }
  } else {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p) != 1) {
        return -1;
      }
    }
  }

  return 1;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);

    if (i != n - 1) {
      printf(" ");
    }
  }
  printf("\n");
}

void squaring(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] *= a[i];
  }
}
