#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define bool int
#define true 1
#define false 0
int global_num;
/*  */
bool isPalindrome(int x);
bool isPalindrome2(int x);
int main(int argc, char *argv[]) {
    isPalindrome(12321);
    isPalindrome2(1232154);
    return 0;
}
bool isPalindrome(int x)
{
    int local_num;
    local_num += 1;
    _Bool boo1=-1;
    printf("%d", boo1);
    printf("global number is %d, local number is %d\n", global_num, local_num);
    if (x < 0) {
        printf("false\n");
        return false;
    } else if (x == 0) {
        printf("true\n");
        return true;
    }
    int array[31] = {0}, i=0;
    while (x) {
        array[i] = x % 10;
        i++;
        x /= 10;
    }
    /* printf("The length is %d\n", i); */
    for (int j=0; j < i / 2; j++) {
        if (array[j] != array[i - j - 1]) {
            printf("false\n");
            return 0;
        }
    }
    printf("true\n");
    return 1;
}

bool isPalindrome2(int x)
{
    char str[100];
    sprintf(str, "%d", x);
    int len_r=0, len_l=0;
    len_r = strlen(str) - 1;
    for(;len_l < len_r;len_l++, len_r--){
        if (str[len_l] != str[len_r]) {
            return false;
        }
    }
    return true;
}
