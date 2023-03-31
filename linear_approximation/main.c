#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double average_number(int n, double *a);

void mnk(int n, double *x, double *y, double * result);

void data_processing();

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int data_sets = 0;
    scanf("%d", &data_sets);
    for (int i = 0; i < data_sets; ++i) {
        data_processing();
    }    
    return 0;
}

double average_number(int n, double *a) {
    double sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
    }
    return (sum / ((double) n));
}

void mnk(int n, double *x, double *y, double *result) {
    double average_y = average_number(n, y);
    double average_x = average_number(n, x);
    double arr1[n];
    double arr2[n];
    double arr3[n];

    for (int i = 0; i < n; ++i) {
        arr1[i] = x[i] * y[i];
        arr2[i] = x[i] * x[i];
        arr3[i] = y[i] * y[i];
    }

    double average_xy = average_number(n, arr1);
    double average_square_x = average_number(n, arr2);
    double average_square_y = average_number(n, arr3);

    result[0] = (average_xy - average_x * average_y) / (average_square_x - average_x * average_x);
    result[1] = sqrtf(((average_square_y - average_y * average_y) / (average_square_x - average_x * average_x) - result[0] * result[0]) / n);
    result[2] = average_y - result[0] * average_x;
    result[3] = result[1] * sqrtf(average_square_x - average_x * average_x);
    result[4] = -result[2] / result[0];
    result[5] = result[4] * sqrtf(result[1] * result[1] / result[0] / result[0] + result[3] * result[3] / result[2] / result[2]);
}

void data_processing() {
    int n = 0;
    scanf("%d", &n);
    double *x = (double*)calloc(n, sizeof(double));

    for (int i = 0; i < n; ++i) {
        scanf("%lg", &x[i]);
    }
    getchar();
    double *y = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        scanf("%lg", &y[i]);
    }

    for (int i = 0; i < 30; ++i) printf("---");
    printf("\n");
    printf("data set (x, y):\n");
    for (int i = 0; i < n; ++i) {
        printf("%.15lg  %.15lg\n", x[i], y[i]);
    }
    printf("\n");

    double result[6];
    mnk(n, x, y, result);

    printf("straight line approximation: y = k * x + b\n");
    printf("k = %.15lg +- %.15lg\n", result[0], result[1]);
    printf("b = %.15lg +- %.15lg\n", result[2], result[3]);
    printf("(y = 0) => x = %.15lg +- %.15lg\n", result[4], result[5]);
    
    for (int i = 0; i < 30; ++i) printf("---");
    printf("\n");
    free(x);
    free(y);
    getchar();
}