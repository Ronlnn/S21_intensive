#include "../data_libs/data_io.h"

#include <stdio.h>

void input(double *data, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lf", &data[i]);
    }
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%.02lf", data[i]);
        if (i != n - 1) {
            printf(" ");
        }
    }
    printf("\n");
}
