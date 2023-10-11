#include <stdio.h>

int datefmt(void);

int main(void){
    int i, j;
    float x, y;

    // printf("\a\n");
    // scanf("%f%d%f", &x, &i, &y);
    // printf("%f %d %f\n", x, i, y);
    datefmt();
    return 0;
}

int datefmt(void){
    // takes a date input in the form mm/dd/yyyy 
    // and prints it in the form yyyymmdd
    int m, d, y;
    
    printf("Enter a date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &m, &d, &y);
    printf("You entered the date %d%.2d%.2d\n", y, m, d);

    return 0;
}