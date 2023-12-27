#include <stdio.h>
#define NMAX 10

int input(int *arr, int *len, int *count);
void shift(int *arr, int len, int count);
void output(int *arr, int len);

int main() {
  int len, count, data[NMAX];

  if (input(data, &len, &count)) {
    shift(data, len, count);
    output(data, len);
  } else {
    printf("n/a");
  }
}

int input(int *arr, int *len, int *count) {
  int re = 1;

  if (scanf("%d", len) != 1) {
    re = 0;
  }
  for (int *p = arr; p - arr < *len; p++) {
    if (scanf("%d", p) != 1) {
      re = 0;
    } else {
      re = 1;
    }
  }
  if (scanf("%d", count) != 1) {
    re = 0;
  }

  return re;
}

void output(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void shift(int *arr, int len, int count) {
  int temp[NMAX];
  for (int i = 0; i < len; i++) {
    temp[i] = arr[i];
  }
  if (count >= 0) {
    for (int i = 0; i < len; i++) {
      arr[i] = temp[(i + count) % len];
    }

  } else if (count <= 0) {
    for (int i = 0; i < len; i++) {
      arr[i] = temp[(i + count + len) % len];
    }
  }
}
