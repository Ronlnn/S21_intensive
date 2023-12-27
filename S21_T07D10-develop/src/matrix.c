#include <stdio.h>
#include <stdlib.h>
#define NMAX 100

int input(int **matrix, int *line, int *column);
int input_stat(int (*matrix_stat)[NMAX], int *line, int *column);
void static_matrix(int matrix_stat[NMAX][NMAX], int line, int column);
void easy_matrix(int line, int column);
void midle_matrix(int line, int column);
void hard_matrix(int line, int column);

int main() {
  int line = NMAX;
  int column = NMAX;
  int variant;
  int matrix_stat[NMAX][NMAX];

  // Ввод варианта массива
  if (scanf("%d ", &variant) != 1) {
    printf("n/a");
  } else if (variant == 1) {
    if (input_stat(matrix_stat, &line, &column) != 1) {
      printf("n/a");
    }
    static_matrix(matrix_stat, line, column);
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
int input_stat(int (*matrix_stat)[NMAX], int *line, int *column) {
  int re = 1;

  if (scanf("%d %d", line, column) != 1) {
    re = 0;
  }
  for (int i = 0; i < *line; i++) {
    for (int j = 0; j < *column; j++) {
      if (scanf("%d", &matrix_stat[i][j]) != 1) {
        re = 0;
      }
    }
  }
  re = 1;
  return re;
}

// статическая
void static_matrix(int matrix[NMAX][NMAX], int line, int column) {
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      if (j == column - 1) {
        printf("%d", matrix[i][j]);
      } else {
        printf("%d ", matrix[i][j]);
      }
    }
    if (i != column - 1) {
      printf("\n");
    }
  }
}

//Первая матрица
void easy_matrix(int line, int column) {
  int **pointer_array = malloc(line * sizeof(int *));
  for (int i = 0; i < line; i++) {
    pointer_array[i] = malloc(column * sizeof(int));
  }
  input(pointer_array, &line, &column);
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      if (j == column - 1) {
        printf("%d", pointer_array[i][j]);
      } else {
        printf("%d ", pointer_array[i][j]);
      }
    }
    if (i != column - 1) {
      printf("\n");
    }
  }
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
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      if (j == column - 1) {
        printf("%d", pointer_array[i][j]);
      } else {
        printf("%d ", pointer_array[i][j]);
      }
    }
    if (i != column - 1) {
      printf("\n");
    }
  }
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
  for (int i = 0; i < line; i++) {
    for (int j = 0; j < column; j++) {
      if (j == column - 1) {
        printf("%d", single_array_matrix[i][j]);
      } else {
        printf("%d ", single_array_matrix[i][j]);
      }
    }
    if (i != column - 1) {
      printf("\n");
    }
  }
  free(single_array_matrix);
}
