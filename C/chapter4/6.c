#include <stdio.h>
#include <stdlib.h>
#include <float.h>

int main(int argc, char *argv[]) {
    double first = 1.0 / 3.0;
    float second = 1.0 / 3.0;
    printf("Float:%d,\t Double:%d\n", FLT_DIG, DBL_DIG);
    printf("Standrad\n\t"
           "Float:%.*f,Double:%.*f\n", FLT_DIG, second, DBL_DIG, first);
    int array[3] = {6, 12, 16};
    for (int i=0; i<3; i++) {
        printf("Double %.*f\n", array[i], first);
        printf("Float %.*f\n", array[i], second);
    }
    return 0;
}
