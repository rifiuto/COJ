#include <stdio.h>
#include <stdlib.h>
#define GALLON2L 3.785
int main(void) {
    const float mile2km = 1.609;
    double qiyou, km;
    printf("Please input qiyou and km: ");
    scanf("%lf,%lf", &qiyou, &km);
    printf("%.1f(Km/gallon)\n", km /qiyou);
    printf("%.1f(L/Km)\n", qiyou * GALLON2L * 100 / (km * mile2km));
    return 0;
}
