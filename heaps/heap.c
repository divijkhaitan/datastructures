#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void siftdown(int*a,int i, int n);

void heapifydown(int*a , int n);

void siftup(int *a, int n);

int* generateArray(int size);

void heapifyup(int *a, int n);

void printarray(int *a, int size);

void make_heap(int*a, int n);

int main()
{
    //int *a;
    int size = 10;
    //a = generateArray(size);
    int a[] = {596,43,83,829,352,192,971,467,464,72};
    printarray(a,size );
    make_heap(a,size );
    printf("Here\n");
    printarray(a,size );
    //free(a);
    return 0;
}
int* generateArray(int size)
{
    int *a = (int *)malloc(sizeof(int)*size);
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        a[i]= (rand() % 1000);
    }
    return a;
}


void printarray(int *a, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[i]);
}

void make_heap(int *a, int n)
{
    int level = 1;
    while (level*2<n)
    {
        level = level*2;
    }
    for(int i = level-1; i>=0;i--)
    {
        siftdown(a, i, n);
    }
}


void siftdown(int *a,int i, int n)
{
    int temp = 0;
    if(i>=n || 2*i+1>=n)
    {
        return;
    }
    int maxchild = a[2*i+1]>a[2*i+2] ? 2*i+1 : 2*i+2; 
    if( a[i] < a[maxchild] )
    {
        temp = a[i];
        
        a[i] = a[maxchild];
        a[maxchild] = temp;
        siftdown(a , maxchild, n);
    }
    return;
}

// void heapifydown(int*a , int n)
// {

// }

// void siftup(int *a, int n)
// {

// }

// void heapifyup(int *a, int i, int n)
// {
    
// }