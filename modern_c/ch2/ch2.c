#include <stdio.h>

// function declarations
void e1(void);
void p1(void);


int main(void) {
    // e1();
    p1();
}


// FUNCTIONS
void e1(void){
    printf("hello world\n");
}

void p1(void) {
    // prints a "Check mark"
    int rows = 6, cols = 8;
    char c = '*';
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols - 1 - i; j++) {
            if (i >= 3 && j == i-3){
                printf("%c", c);
            } else {
                printf(" ");
            }
        }
        printf("%c\n", c);
    }
}

