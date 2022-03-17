#include <stdio.h>
#include <stdlib.h>

int main() {
    float file, speed;
    printf("Please input the speed and file size: ");
    scanf("%f,%f", &speed, &file);
    printf("At %.2f megabits per second, a file of %.2f megabytes\n"
           "downloads in %.2f second\n", speed, file, file * 8 / speed);
    return 0;
}
