#include <stdio.h>

int find_max(int a, int b);
int a;
int b;

int main() {
  if (scanf("%d %d", &a, &b) != 2) {
    printf("n/a");
  } else {
    printf("%d", find_max(a, b));
  }
  return 0;
}
int find_max(int a, int b) {
  if (a > b) {
    return a;
  } else if (a < b) {
    return b;
  } else {
    printf("Числа равны");
  }
  return 1;
}
