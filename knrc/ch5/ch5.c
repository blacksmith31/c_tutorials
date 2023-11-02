#include <ctype.h>
#include <stdio.h>

#define BUFSIZE 100
#define SIZE 10

int getch(void);
void ungetch(int);
// goto pg 101(87) to add qsort version
void swap(int *px, int *py);
int getint(int *pn);

char buf[BUFSIZE];
int bufp = 0;


int main(int argc, char *argv[]){
    int a, b, array[SIZE] = {0};
    a = 123;
    b = 456;
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
    
    // this should make calls to stdio.getchar to read input from stdin
    // test with input such as 1 2 3 -4 +5 
    for (int n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    
    for (int n = 0; n < SIZE; n++)
        printf("array[%d] = %d\n", n, array[n]);
}

int getch(void){
    /* get a (possibly pushed back) character */ 
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    /* push a character back on input */ 
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void swap(int *px, int *py){
    int temp;

    temp = *px;
    *px = *py;
    *py = temp;
}

int getint(int *pn){
    /* get next integer from input into *pn */ 
    int c, sign;

    while (isspace(c = getch()))
        ;
    if (!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c); /* it's not a number */ 
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-'){
        c = getch();
    }
    // Added as part of exercise 5-1 pg.97
    // this works except for newlines, there is likely something else going on with how getchar handles this
    if (!isdigit(c)){
        printf("c is not a digit\n");
        ungetch(c);
        return 0;
    }
    for (*pn = 0; isdigit(c); c = getch()){
        printf("c is a digit: %c.\n", c);
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}
