#include <stdio.h>

#define N 10

void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);

int main(void){
    int a[N], i = 0;

    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N && i != EOF; i++){
        scanf("%d", &a[i]);
    }

    quicksort(a, 0, N-1);

    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}

void quicksort(int a[], int low, int high){
    /*Quicksort algorithm:
    * choose an array element e (the partitioning element)
    * then rearrange the array so elements 0, ..., i-1 are less than or equal to e 
    * element i contains e,
    * and elements i+1, ..., n are greater than or equal to e
    * Sort elements 0, ..., i-1 using quicksort recursively,
    * Sort elements i+1, ..., n using quicksort recursively.
    */ 
    int middle;

    if (low >= high)
        return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

int split(int a[], int low, int high){
    int part_element = a[low];

    for (;;){
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];
    }

    a[high] = part_element;
    return high;
}


