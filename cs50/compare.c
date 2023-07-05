#include <stdio.h>

int main(void)
{
    int x, y;
    printf("Enter a val for x: ");
    scanf("%i", &x);
    printf("\nEnter a val for y: ");
    scanf("%i", &y);
    
    
    if (x > y)
    {
        printf("\nx greater than y\n");
    }
    else if (y > x)
    {
        printf("\ny greater than x\n");
    }
    else
    {
        printf("\nx and y equal\n");
    }
}