#include <stdio.h>

int sum(int a, int b) { return (a + b); }
int min(int a, int b) { return (a - b); }
int mul(int a, int b) { return (a * b); }
int div(int a, int b) { return (a / b); }

int main() {
  int var;
  int a;
  int b;
  var = scanf("%d", &a);
  if (var != 1) {
    printf("n/a");
    return 0;
  }
  var = scanf("%d", &b);
  if (var != 1) {
    printf("n/a");
    return 0;
  }
  if (b == 0) {
    printf("%d %d %d %s", sum(a, b), min(a, b), mul(a, b), "n/a");
  } else {
    printf("%d %d %d %d", sum(a, b), min(a, b), mul(a, b), div(a, b));
  }

  return 0;
}
