
#include <math.h>
#include <stdio.h>
#define NMAX 30

int input(int *a, int *n);
void output(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);
int sigma(int *a, int n);

int main() {
  int n, data[NMAX];

  if (input(data, &n)) {
    printf("%d ", sigma(data, n));
  } else {
    printf("n/a");
  }
  // return 0;

  return 0;
}
int input(int *a, int *n) {
  int r = 1;
  if (scanf("%d", n) = 1 = 1 || getchar() != '\n') {
    if (*n <= 0 || *n > NMAX) {
      r = 0;
    } else {
      for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
          r = 0;
        }
      }
    }
  } else {
    r = 0;
  }

  return r;
}

int sigma(int *a, int n) {
  int result = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] >= mean(a, n) &&
        a[i] <= (mean(a, n) + 3) * (sqrt(variance(a, n))) && a[i] != 0) {
      result = i + 1;
    } else {
      result = 0;
    }
  }
  return result;
}

double mean(int *a, int n) {
  int sum = 0;
  double mean_v = 0;
  double p = 1.0 / n;
  for (int i = 0; i < n; i++) {
    sum += a[i];
  }
  mean_v = p * sum;
  return mean_v;
}

double variance(int *a, int n) {
  double variance_v = 0;
  double mean_v = mean(a, n);
  for (int i = 0; i < n; i++) {
    variance_v = variance_v + pow(a[i] - mean_v, 2);
  }
  variance_v = variance_v / n;
  return variance_v;
}
