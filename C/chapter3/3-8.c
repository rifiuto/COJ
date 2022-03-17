#include <stdio.h>
#include <stdlib.h>
#define YEAR_SECOND 3.156e7
#define WATER_MELOCULE 3.0e-23
#define INCH2CM 2.54
int main(int argc, char *argv[]) {
    int age;
    printf("Please input your age: ");
    scanf("%d", &age);
    printf("The second of the year which is equal to your age is %.4e second\n", age * YEAR_SECOND);
    double kuatuo;
    printf("Please input the kuatuo of the water: ");
    scanf("%lf", &kuatuo);
    printf("The number of water melocule is %.4e\n", kuatuo * WATER_MELOCULE);
    float heigth;
    printf("Please input your height(inch): ");
    scanf("%f", &heigth);
    printf("Your height is %.3f(cm)\n", heigth * INCH2CM);
    int cup;
    printf("Please input the number of cup: ");
    scanf("%d", &cup);
    printf("%d cup is equal to %.1f pint, %d ounce, %d spoon, %d tea spoon\n", cup, (float)cup /2, cup * 8, cup * 16, cup * 48);
    return 0;
}
