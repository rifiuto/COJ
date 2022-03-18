#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int i = 1, j = 1;
    while (i <= 9) {
        j = 1;
        while (j<=i) {
            printf("%-2dx%2d=%2d ", i, j, i * j);
            j++;
        }
        printf("\b\n");
        i++;
    }
    return 0;
}
