#include <math.h>
#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
  int n, data[NMAX];
  input(data, &n);
  output(data, n);
  output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));

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

void output_result(int max, int min, double mean, double variance) {
  printf("%d %d %.6lf %.6lf", max, min, mean, variance);
  printf("\n");
}

int max(int *a, int n) {
  int max_v = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max_v) {
      max_v = a[i];
    }
  }

  return max_v;
}

int min(int *a, int n) {
  int min_v = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < min_v) {
      min_v = a[i];
    }
  }
  return min_v;
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