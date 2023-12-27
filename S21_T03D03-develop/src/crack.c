#include <stdio.h>

void crack(double x, double y);

int main() {
  double x, y;
  if (scanf("%lf %lf", &x, &y) != 2) {
    printf("n/a");
  } else {
    crack(x, y);
  }
  return 0;
}

void crack(double x, double y) {
  if ((x * x) + (y * y) <= 25) {
    printf("GOTCHA");
  } else {
    printf("MISS");
  }
}