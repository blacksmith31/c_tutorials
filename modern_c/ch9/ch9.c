#include <stdio.h>
#include <stdbool.h>

void print_count(int n){
    printf("T minus %d and counting\n", n);
}

bool is_prime(int n){
    int d;

    if (n <= 1){
        return false;
    }
    for (d = 2; d * d <= n; d++){
        if (n % d == 0){
            return false;
        }
    }
    return true;
}

void bad_arr_size(int a[], int n){
    // this doesn't produce the expected result 
    //- the argument passed to a is a pointer to an int at the first position in the array
    printf("size of a: %ld\n", sizeof(a));
}

int fact(int n){
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}

int main(void){
    int i;
    int a[] = {1, 2, 3};

    for (i = 10; i > 0; --i){
        print_count(i);
    }

    if (is_prime(4)){
        printf("Prime\n");
    } else {
        printf("Not Prime\n");
    }
    printf("size of a: %ld\n", sizeof(a));
    bad_arr_size(a, 3);

    printf("factorial 5: %d\n", fact(5));
    return 0;
}
