#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    double input;
    printf("Please input the number:\n");
    scanf("%lf", &input);
    printf("Decimal point form is %f\n", input);
    printf("Exponent form is %e\n", input);
    printf("P form is %a\n", input);
    return 0;
}
