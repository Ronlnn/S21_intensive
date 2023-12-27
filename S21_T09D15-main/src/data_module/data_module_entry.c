#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "data_process.h"

int main() {
    int n = 0;

    if ((scanf("%d", &n) == 1)) {
        double *data = (double *)malloc(n * sizeof(double));
        input(data, n);

        if (normalization(data, n)) {
            output(data, n);
        } else {
            printf("ERROR");
        }

        free(data);
    } else {
        printf("n/a");
    }

    return 0;
}