#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char *argv[]) {
    char surname[16], name[16];
    printf("Please input the surname: ");
    scanf("%s", surname);
    printf("Please input the name: ");
    scanf("%s", name);
    int len_surname = strlen(surname), len_name = strlen(name);
    printf("%s %s\n"
    "%*d %*d\n", surname, name, len_surname, len_surname, len_name, len_name);
    return 0;
}
