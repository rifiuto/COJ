#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int n = 0;
    size_t intsize;
    intsize = sizeof(int);
    printf("%zd\n", intsize);
    return 0;
}
