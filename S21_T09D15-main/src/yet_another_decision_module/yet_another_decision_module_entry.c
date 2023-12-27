#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_stat.h"
#include "decision.h"

int main() {
    int n;
    if ((scanf("%d", &n) == 1) && (getchar() == '\n') && n > 0) {
        double *data = (double *)malloc(n * sizeof(double));
        input(data, n);

        if (make_decision(data, n)) {
            printf("YES");
        } else {
            printf("NO");
        }
        free(data);
        data = NULL;
    } else {
        printf("ERROR");
    }
    return 0;
}
