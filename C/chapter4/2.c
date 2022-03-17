#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char name[16];
    printf("Please input your name: ");
    scanf("%s", name);
    int length = strlen(name) + 3;
    printf("Your name is \"%s\"\n", name);
    printf("Your name is \"%20s\"\n", name);
    printf("Your name is \"%-20s\"\n", name);
    printf("Your name is \"%*s\"\n", length, name);
    return 0;
}
