#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    double input;
    printf("Please input the float: ");
    scanf("%lf", &input);
    printf("The input is %.1f or %.1e\n", input, input);
    printf("The input is %+.1f or %.3E\n", input, input);
    return 0;
}
