#include <stdio.h>
#include <stdlib.h>

double det(double **matrix, int n, int m);
void input(double **matrix, int n, int m);

int main() {
    double **matrix = NULL;
    int n, m;
    if (scanf("%d %d", &n, &m) == 2 && (getchar() == '\n')) {
        if ((n != 0 && m != 0)) {
            matrix = (double **)malloc(n * sizeof(double *));
            for (int i = 0; i < n; i++) {
                matrix[i] = (double *)malloc(m * sizeof(double));
            }
            input(matrix, n, m);
            double deter = det(matrix, n, m);
            printf("%.6f", deter);
        } else
            printf("n/a");
    } else {
        printf("n/a");
    }
    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);
    matrix = NULL;

    return 0;
}

void input(double **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            if (scanf("%lf", &matrix[i][j]) != 1) {
                printf("n/a");
                exit(1);
            }
        }
    }
}

double det(double **matrix, int n, int m) {
    if (n == 1) {
        return matrix[0][0];
    }
    double deter = 0;
    double **submatrix = (double **)malloc((n - 1) * sizeof(double *));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            submatrix[j] = (double *)malloc((n - 1) * sizeof(double));
        }
        for (int j = 1; j < n; j++) {
            int col = 0;
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    submatrix[j - 1][col] = matrix[j][k];
                    col++;
                }
            }
        }
        double sign = (i % 2 == 0) ? 1.0 : -1.0;
        deter += sign * matrix[0][i] * det(submatrix, n - 1, m);

        for (int j = 0; j < n - 1; j++) {
            free(submatrix[j]);
        }
    }
    free(submatrix);
    return deter;
}
