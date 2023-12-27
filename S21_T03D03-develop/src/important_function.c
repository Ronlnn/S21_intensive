#include <math.h>
#include <stdio.h>

double okrug(double x);

int main() {
  double x, y;

  if (scanf("%lf", &x) != 1) {
    printf("n/a");
  } else {
    y = okrug(x);
    if (isnan(y)) {
      printf("n/a");
    } else {
      printf("%lf", y);
    }
  }
  return 0;
}
double okrug(double x) {
  double y;
  if (x == 0) {
    return NAN;
  } else {
    y = 7e-3 * pow(x, 4) +
        ((22.8 * pow(x, 1.0 / 3.0) - 1e3) * x + 3) / (x * x / 2) -
        x * pow(10 + x, 2 / x) - 1.01;

    return y;
  }
}