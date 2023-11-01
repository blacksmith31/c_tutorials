#include <stdio.h>

int e1(){
    int i, j, k;

    i = 2;
    j = 3;
    k = i * j == 6;
    printf("%d\n", k);

    i = 5;
    j = 10;
    k = 1;
    printf("%d\n", k > i < j);
    
    i = 3; j = 2; k = 1;
    printf("%d\n", i % j + 1 < k);
}

int e2(){
    int i, j, k;

    i = 10; j = 5;
    printf("%d\n", !i < j);
}

int e4(int i, int j){
    printf("%d\n", (i > j) - (i < j));
 
}

int e6(int n){
    if (n == 1-10){
        printf("n is between 1 and 10\n");
    }
}

int main(void){

    e1();
    e2();
    e4(2, 2);
    e6(5);
}