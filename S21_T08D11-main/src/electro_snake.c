#include <stdio.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);
void sort_horizontal(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int n, int m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix = NULL;
    int **result = NULL;
    int n, m;
    if (scanf("%d %d", &n, &m) == 2 && (getchar() == '\n')) {
        if (n != 0 && m != 0) {
            matrix = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++) {
                matrix[i] = (int *)malloc(m * sizeof(int));
            }
            result = (int **)malloc(n * sizeof(int *));
            for (int i = 0; i < n; i++) {
                result[i] = (int *)malloc(m * sizeof(int));
            }
            input(matrix, n, m);
            sort_vertical(matrix, n, m, result);
            output(result, n, m);
            printf("\n\n");
            sort_horizontal(matrix, n, m, result);
            output(result, n, m);
        } else
            printf("n/a");
    } else {
        printf("n/a");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(result[i]);
    }
    free(matrix);
    free(result);
    matrix = NULL;
    result = NULL;

    return 0;
}

void input(int **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%d", &matrix[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

void output(int **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%d", matrix[i][j]);
            if (j + 1 != column) {
                printf(" ");
            }
        }
        if (i + 1 != row) {
            printf("\n");
        }
    }
}

void sort(int *stat_mas, int size) {
    int sort;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (stat_mas[j] > stat_mas[j + 1]) {
                sort = stat_mas[j];
                stat_mas[j] = stat_mas[j + 1];
                stat_mas[j + 1] = sort;
            }
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {
    int stat_mas[n * m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            stat_mas[k] = matrix[i][j];
            k++;
        }
    }
    sort(stat_mas, n * m);
    int w = 0;
    k = 0;
    if (n >= m) {
        while (k != n) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][k] = stat_mas[w];
                w++;
            }
            k++;
            if (k == n) {
                break;
            }
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][k] = stat_mas[w];
                w++;
            }
            k++;
        }
    } else {
        while (k != m) {
            for (int i = 0; i < n; i++) {
                result_matrix[i][k] = stat_mas[w];
                w++;
            }
            k++;
            if (k == m) {
                break;
            }
            for (int i = n - 1; i >= 0; i--) {
                result_matrix[i][k] = stat_mas[w];
                w++;
            }
            k++;
        }
    }
}

void sort_horizontal(int **matrix, int n, int m, int **result_matrix) {
    int stat_mas[n * m];
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            stat_mas[k] = matrix[i][j];
            k++;
        }
    }
    sort(stat_mas, n * m);
    int w = 0;
    k = 0;
    while (k < n * m) {
        for (int i = 0; i < m; i++) {
            result_matrix[k / m][i] = stat_mas[w];
            w++;
            k++;
        }
        if (k == n * m) {
            break;
        }
        for (int i = m - 1; i >= 0; i--) {
            result_matrix[k / m][i] = stat_mas[w];
            w++;
            k++;
        }
    }
}
