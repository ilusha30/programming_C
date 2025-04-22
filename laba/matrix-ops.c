//
//  matrix-ops.c
//  C labs
//
//  Created by Илья Овсянников on 22.04.2025.
//

#include <stdlib.h>
#include "matrix-ops.h"

double* matrix_operation(const double* a, const double* b, int n, char op) {
    double* result = (double*)malloc(n * n * sizeof(double));
    if (!result) return NULL;

    int i, j, k;

    if (op == '+') {
        for (i = 0; i < n * n; i++) {
            result[i] = a[i] + b[i];
        }
    }
    else if (op == '-') {
        for (i = 0; i < n * n; i++) {
            result[i] = a[i] - b[i];
        }
    }
    else if (op == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                double sum = 0.0;
                for (k = 0; k < n; k++) {
                    sum += a[i * n + k] * b[k * n + j];
                }
                result[i * n + j] = sum;
            }
        }
    }
    else {
        // Неверный оператор — освобождаем память и возвращаем NULL
        free(result);
        return NULL;
    }

    return result;
}
