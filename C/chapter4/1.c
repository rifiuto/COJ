#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    char surname[20], name[20];
    printf("Please input your surname and name: ");
    scanf("%s %s", surname, name);
    printf("%s,%s\n", surname, name);
    return 0;
}
