#include <stdio.h>

void ranges(int x[], int npts, int *max_ptr, int *min_ptr);

int main(){
    int a[5]={4, 3, 4, 2, 5};
    int *p = a;
    int *q = a;
    ranges(a, 5, p, q);
}

void ranges(int x[], int npts, int *max_ptr, int *min_ptr){
    max_ptr=x;
    min_ptr=x;
    int temp=1;
    while (temp<=npts-1) {
        if (*max_ptr<x[temp]) {
            max_ptr=&x[temp];
        }
        if (*min_ptr>x[temp]) {
            min_ptr=&x[temp];
        }
        temp++;
    }
    printf("maximum value: %d\n", *max_ptr);
    printf("minimum value: %d", *min_ptr);
}

