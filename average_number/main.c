#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum {
    ANSWER_AND_ERROR = 2,
    ANSWER = 0,
    ERROR = 1,
};

double averagefunc(int n, double *arr);

double sigma(int n, double average, double *data);

double* data_input(int n);

void data_free(double *data);

void data_operations();

void data_print(int n, double *data);

void result_print(double average, double error_rate);

void result_find(int n, double *data, double *result);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    data_operations();
    return 0;
}

double averagefunc(int n, double *arr) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += arr[i];
    }
    return sum / (double) n;
}

double sigma(int n, double average, double * data) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += (average - data[i]) * (average - data[i]);
    }
    double ans = sqrtf(sum / (double) (n * (n - 1)));
    return ans;
}

double* data_input(int n) {
    double * data = (double*)calloc(n, sizeof(double));
    for (int i = 0; i < n; ++i) {
        scanf("%lg", data + i);
    }
    return data;
}

void data_free(double *data) {
    free(data);
}

void data_print(int n, double *data) {
    printf("data set:\n");
    for (int i = 0; i < n; ++i) {
        printf("%lg\n", data[i]);
    }
    putchar('\n');
}

void data_operations() {
    int n = 0, m = 0;
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
        scanf("%d", &n);
        double * data = data_input(n);
        data_print(n, data);
        double  result[ANSWER_AND_ERROR] = {0.0, 0.0}; 
        result_find(n, data, result);
        result_print(result[ANSWER], result[ERROR]);
        data_free(data);
    }
}

void result_print(double average, double error_rate) {
    printf("average = %.10lg ± %.10lg\n", average, error_rate);
    putchar('\n');
}

void result_find(int n, double *data, double *result) {
    double average = averagefunc(n, data);
    double error = sigma(n, average, data);
    result[ANSWER] = average;
    result[ERROR] = error;
}