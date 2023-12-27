#include <stdio.h>
#define NMAX 10

int input(int *arr, int n);
void buble_sort(int *arr, int n);
void output(int *arr, int n);

int main() {
  int data[NMAX];
  int n = NMAX;
  if (input(data, n)) {
    buble_sort(data, n);
    output(data, n);
  } else {
    printf("n/a \n");
  }

  return 0;
}

int input(int *arr, int n) {
  int re = 1;

  for (int *p = arr; p - arr < n; p++) {
    if (scanf("%d", p) != 1) {
      re = 0;
    } else {
      re = 1;
    }
  }
  return re;
}

void buble_sort(int *arr, int n) {
  int temp = 0;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}

void output(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", arr[i]);
  }
}