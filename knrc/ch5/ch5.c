#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define SIZE 10
#define MAXLINES 5000
#define MAXLEN 1000 /* max length of any input line */ 
#define ALLOCSIZE 10000 /* size of available space */ 

int getch(void);
void ungetch(int);
void swap(int v[], int i, int j);
int getint(int *pn);
void qsort(int v[], int left, int right);
void strcpyp(char *s, char *t);
void strcpya(char *s, char *t);

// Globals for getch/ungetchr
char buf[BUFSIZE];
int bufp = 0;

static char allocbuf[ALLOCSIZE]; /* storage for alloc */ 
static char *allocp = allocbuf; /* next free position */ 
char *lineptr[MAXLINES]; /* pointers to text lines */ 


int main(int argc, char *argv[]){
    int a, b, array[SIZE] = {0};
    a = 123;
    b = 456;
    //swap(&a, &b);
    //printf("a: %d, b: %d\n", a, b);
    
    // qsort testing
    int sl[SIZE] = {9, 3, 5, 2, 8};
    printf("qsort before: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sl[i]);
    }
    printf("\n");

    qsort(sl, 0, 3);

    printf("qsort after: \n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", sl[i]);
    }
    printf("\n");

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

void swap(int v[], int i, int j){
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(int v[], int left, int right){
    /* given the array a partition element is chosen
     * the remaining elements are separated into 2 subsets
     * greater than and less than the partition
     * this is done recursively
     * left and right are index positions in the array to sort between
     * */
    int i, last;
    
    // do nothing if array contains fewer than 2 elements
    if (left >= right){
        return;
    }
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++){
        if (v[i] < v[left]){
            swap(v, ++last, i);
        }
    }
    swap(v, left, last);
    qsort(v, left, last-1);
    qsort(v, last+1, right);
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

/* strcpy: copy t to s; array subscript version */ 
void strcpya(char *s, char *t){
    int i;

    i = 0;
    while ((s[i] = t[i]) != '\0')
        i++;
}


/* strcpy: copy t to s; pointer subscript version */ 
void strcpyp(char *s, char *t){
    while ((*s = *t) != '\0'){
        s++;
        t++;
    }
}

int getline(char s[], int lim){
    /* read a line into s, return length */ 
    int c, i;

    for (i=0; i<lim-1 && (c=getchar()) != EOF && c!= '\n'; ++i){
        s[i] = c;
    }
    if (c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

char *alloc (int n){
    if (allocbuf + ALLOCSIZE - allocp >= n){
        // it fits
        allocp += n;
        return allocp - n;
    }
    else {
        return 0;
    }
}

int readlines(char *lineptr[], int maxlines){
    /* read input lines */ 
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getline(line, MAXLEN)) > 0){
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len-1] = '\0'; /* delete newline */ 
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }
    return nlines;
}
