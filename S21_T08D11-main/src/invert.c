#include <stdio.h>
#include <stdlib.h>

int invert(double **matrix, int row, double **inverse);
void input(double **matrix, int row, int column);
void output(double **matrix, int row, int column);

int main() {
    double **matrix = NULL;
    double **inverse = NULL;
    int n, m;
    if (scanf("%d %d", &n, &m) == 2 && (getchar() == '\n')) {
        if ((n != 0 && m != 0)) {
            matrix = (double **)malloc(n * sizeof(double *));
            for (int i = 0; i < n; i++) {
                matrix[i] = (double *)malloc(m * sizeof(double));
            }

            input(matrix, n, m);

            inverse = (double **)malloc(n * sizeof(double *));
            for (int i = 0; i < n; i++) {
                inverse[i] = (double *)malloc(n * sizeof(double));
            }

            invert(matrix, n, inverse);
            output(inverse, n, m);

        } else
            printf("n/a");
    } else {
        printf("n/a");
    }

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
        free(inverse[i]);
    }
    free(matrix);
    free(inverse);
    matrix = NULL;
    inverse = NULL;

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

void output(double **matrix, int row, int column) {
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            printf("%lf", matrix[i][j]);
            if (j + 1 != column) {
                printf(" ");
            }
        }
        if (i + 1 != row) {
            printf("\n");
        }
    }
}

int invert(double **matrix, int row, double **inverse) {
    double **augmented = (double **)malloc(row * sizeof(double *));
    for (int i = 0; i < row; i++) {
        augmented[i] = (double *)malloc(2 * row * sizeof(double));
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < row; j++) {
            augmented[i][j] = matrix[i][j];
        }
        for (int j = row; j < 2 * row; j++) {
            augmented[i][j] = (j == (i + row)) ? 1.0 : 0.0;
        }
    }

    for (int i = 0; i < row; i++) {
        if (augmented[i][i] == 0.0) {
            for (int j = i + 1; j < row; j++) {
                if (augmented[j][i] != 0.0) {
                    double *temp = augmented[i];
                    augmented[i] = augmented[j];
                    augmented[j] = temp;
                    break;
                }
            }
        }

        double pivot = augmented[i][i];
        for (int j = 0; j < 2 * row; j++) {
            augmented[i][j] /= pivot;
        }

        for (int j = 0; j < row; j++) {
            if (j != i) {
                double factor = augmented[j][i];
                for (int k = 0; k < 2 * row; k++) {
                    augmented[j][k] -= factor * augmented[i][k];
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = row; j < 2 * row; j++) {
            inverse[i][j - row] = augmented[i][j];
        }
    }

    for (int i = 0; i < row; i++) {
        free(augmented[i]);
    }
    free(augmented);

    return 1;
}
