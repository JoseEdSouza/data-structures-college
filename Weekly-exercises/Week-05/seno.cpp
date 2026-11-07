#include <stdio.h>
#include <math.h>
#define QNTD_TERMS 15



int main() {
    double angle = 0;
    long double terms[QNTD_TERMS];
    long double result = 0;

    printf("\nDigite o valor do angulo para sen(x): ");
    scanf("%le", &angle);

    angle *= (M_PI / 180.0);
    for (int i = 0, expo = 1;i < QNTD_TERMS;++i, expo += 2) {
        long double numerator = (pow(-1, i) * pow(angle, expo)), denominator = 1;
        for (int j = expo;j != 0;--j) {
            denominator *= j;
        }
        terms[i] = numerator / denominator;
        result += terms[i];
    }

    printf("\nsen(x) = %.2Lf\n", result);
}