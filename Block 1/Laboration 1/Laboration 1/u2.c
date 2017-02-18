#include <stdio.h>
#include <math.h>

int num1,num2,sum;

int main(void)
{
    printf("\n----------------------------\nUppgift 2\n----------------------------\nAnge ett tal: ");
    scanf("%d",&num1);
    printf("Ange ytterligare ett tal: ");
    scanf("%d",&num2);
    sum = num1 + num2;
    printf("Summan av talen är: %d\n----------------------------\n\n", sum);
    return 0;
}