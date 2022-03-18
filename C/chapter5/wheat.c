#include <stdio.h>
#include <stdlib.h>
#define SQUARES 64
int main() {
    const double CROP = 2E16;
    double current, total;
    int square = 1;
    printf("%-10s%-10s%-10s%-10s\n", "square", "grains" ,"total", "fraction of total");
    total = current = 1;
    printf("%5d%13.2e%10.2e%10.2e\n", square, current, total, total / CROP);
    while (square < SQUARES) {
        square++;
        current *= 2, total += current;
        printf("%5d%13.2e%10.2e%10.2e\n", square, current, total, total / CROP);
    }
    return 0;
}
