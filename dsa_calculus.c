#include <stdio.h>

#define SIZE 10

// Function f(x) = x^2 + 3x + 2
float function(float x) {
    return x*x + 3*x + 2;
}

int main() {
    float x[SIZE], fx[SIZE];
    float h = 1.0;

    // Store x values and f(x) values using arrays (Data Structure)
    for(int i = 0; i < SIZE; i++) {
        x[i] = i;
        fx[i] = function(x[i]);
    }

    // Numerical differentiation using finite difference method (Calculus)
    printf("x\tf(x)\tDerivative\n");
    for(int i = 0; i < SIZE - 1; i++) {
        float derivative = (fx[i + 1] - fx[i]) / h;
        printf("%.2f\t%.2f\t%.2f\n", x[i], fx[i], derivative);
    }

    return 0;
}
