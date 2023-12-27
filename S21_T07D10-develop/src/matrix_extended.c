#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int **matrix, int *line, int *column);
int input_stat(int (*matrix_stat)[NMAX], int *line, int *column);
void static_matrix(int line, int column);
void easy_matrix(int line, int column);
void midle_matrix(int line, int column);
void hard_matrix(int line, int column);
void max(int line, int column, int **a);
void maxs(int line, int column, int a[][column]);
void min(int line, int column, int **a);
void mins(int line, int column, int a[][column]);
void print(int line, int column, int **a);
void print_static(int line, int column, int a[][column]);

int main() {
  int line = NMAX;
  int column = NMAX;
  int variant;

  // Ввод варианта массива
  if (scanf("%d ", &variant) != 1) {
    printf("n/a");
  } else if (variant == 1) {
    static_matrix(line, column);
  } else if (variant == 2) {
    easy_matrix(line, column);
  } else if (variant == 3) {
    midle_matrix(line, column);
  } else if (variant == 4) {
    hard_matrix(line, column);
  }
}

//Ввод динамики
int input(int **matrix, int *line, int *column) {
  int re = 1;
  // Ввод размер матрицы
  if (scanf("%d %d", line, column) != 1) {
    re = 0;
  }
  // Ввод элементов массива
  for (int i = 0; i < *line; i++) {
    for (int j = 0; j < *column; j++) {
      if (scanf("%d", &matrix[i][j]) != 1) {
        re = 0;
      }
    }
  }
  re = 1;
  return re;
}

//Ввод статики
int input_static(int line, int column, int a[][column]) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      scanf("%d", &a[i][j]);
    }
  }
  return 0;
}

// статическая
void static_matrix(int line, int column) {
  if (scanf("%d %d", &line, &column) == 2 && line <= 100 && column <= 100) {
    int matrix[line][column];
    input_static(line, column, matrix);
    print_static(line, column, matrix);
    printf("\n");
    maxs(line, column, matrix);
    printf("\n");
    mins(line, column, matrix);
  }
}

//Первая матрица
void easy_matrix(int line, int column) {
  int **pointer_array = malloc(line * sizeof(int *));
  for (int i = 0; i < line; i++) {
    pointer_array[i] = malloc(column * sizeof(int));
  }
  input(pointer_array, &line, &column);
  print(line, column, pointer_array);
  printf("\n");
  max(line, column, pointer_array);
  printf("\n");
  min(line, column, pointer_array);

  free(pointer_array);
}

//Вторая матрица
void midle_matrix(int line, int column) {
  int **pointer_array = malloc(line * sizeof(int *));
  int *values_array = malloc(line * column * sizeof(int));
  for (int i = 0; i < line; i++) {
    pointer_array[i] = values_array + column * i;
  }
  input(pointer_array, &line, &column);
  print(line, column, pointer_array);
  printf("\n");
  max(line, column, pointer_array);
  printf("\n");
  min(line, column, pointer_array);

  free(values_array);
  free(pointer_array);
}

//Третья матрица
void hard_matrix(int line, int column) {
  int **single_array_matrix =
      malloc(line * column * sizeof(int) + line * sizeof(int *));
  int *ptr = (int *)(single_array_matrix + line);
  for (int i = 0; i < line; i++) {
    single_array_matrix[i] = ptr + column * i;
  }
  input(single_array_matrix, &line, &column);
  print(line, column, single_array_matrix);
  printf("\n");
  max(line, column, single_array_matrix);
  printf("\n");
  min(line, column, single_array_matrix);

  free(single_array_matrix);
}

void max(int line, int column, int **a) {
  for (int i = 0; i < line; i++) {
    int temp = a[i][0];
    for (int j = 1; j < column; j++) {
      if (temp < a[i][j]) {
        temp = a[i][j];
      }
    }
    if (i < line - 1)
      printf("%d ", temp);
    else
      printf("%d", temp);
  }
}

void maxs(int line, int column, int a[][column]) {
  for (int i = 0; i < line; i++) {
    int temp = a[i][0];
    for (int j = 1; j < column; j++) {
      if (temp < a[i][j]) {
        temp = a[i][j];
      }
    }
    if (i < line - 1)
      printf("%d ", temp);
    else
      printf("%d", temp);
  }
}

void min(int line, int column, int **a) {
  for (int i = 0; i < line; i++) {
    int temp = a[0][i];
    for (int j = 1; j < column; j++) {
      if (temp > a[j][i]) {
        temp = a[j][i];
      }
    }
    if (i < line - 1)
      printf("%d ", temp);
    else
      printf("%d", temp);
  }
}

void mins(int line, int column, int a[][column]) {
  for (int i = 0; i < line; i++) {
    int temp = a[0][i];
    for (int j = 1; j < column; j++) {
      if (temp > a[j][i]) {
        temp = a[j][i];
      }
    }
    if (i < line - 1)
      printf("%d ", temp);
    else
      printf("%d", temp);
  }
}

void print(int line, int column, int **a) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      printf("%d", a[i][j]);
      if (j != column - 1) {
        printf(" ");
      }
    }
    if (i != line - 1) {
      printf("\n");
    }
  }
}

void print_static(int line, int column, int a[][column]) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      printf("%d", a[i][j]);
      if (j != column - 1) {
        printf(" ");
      }
    }
    if (i != line - 1) {
      printf("\n");
    }
  }
}