#include <stdio.h>

int e1(){
    int i, j;

    i = 5;
    j = 3;
    printf("%d %d\n", i / j, i % j);

    i = 2;
    j = 3;
    printf("%d\n", (i + 10) % j);
    
}

int main(void){
    int i, j;
    float x, y;

    // Simple assignment operator has a side effect and produces a result
    // left operand is modified and the result is equal to the assignment value
    printf("%d\n", i = 72.99f);

    e1();
}