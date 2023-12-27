#include "../data_libs/data_stat.h"

double max(double *data, int n) {
    int max_v = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max_v) {
            max_v = data[i];
        }
    }

    return max_v;
}
double min(double *data, int n) {
    int min_v = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min_v) {
            min_v = data[i];
        }
    }
    return min_v;
}

double mean(double *data, int n) {
    int sum = 0;
    double mean_v = 0;
    double p = 1.0 / n;
    for (int i = 0; i < n; i++) {
        sum += data[i];
    }
    mean_v = p * sum;
    return mean_v;
}

double variance(double *data, int n) {
    double variance_v = 0;
    double mean_v = mean(data, n);
    for (int i = 0; i < n; i++) {
        variance_v = variance_v + pow(data[i] - mean_v, 2);
    }
    variance_v = variance_v / n;
    return variance_v;
}
