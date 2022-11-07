#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void siftdown(int*a,int i, int n);

void siftup(int *a,int i, int n);

void insert(int*a, int *n, int i);

int extract_max(int*a, int *n);

int* generateArray(int size);

void printarray(int *a, int size);

void make_heap(int*a, int n);

int main()
{
    int *a;
    int size = 10;
    a = generateArray(size);
    //int a[] = {596,43,83,829,352,192,971,467,464,72};
    printarray(a,size );
    make_heap(a,size );
    printarray(a,size );
    insert(a,&size,1001);
    printarray(a,size );
    insert(a,&size,2000);
    // siftup(a,size-1,10);
    printarray(a,size );
    printf("%d\n",extract_max(a,&size));
    printf("%d\n",extract_max(a,&size));
    printarray(a,size );
    free(a);
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
    int maxchild = 0;
    if(i>=n || 2*i+1>=n)
    {
        return;
    }

    if(2*i+2>=n)
    {
        maxchild = 2*i+1;
    }
    else
    {
        maxchild = a[2*i+1]>a[2*i+2] ? 2*i+1 : 2*i+2;
    } 
    if( a[i] < a[maxchild] )
    {
        temp = a[i];

        a[i] = a[maxchild];
        a[maxchild] = temp;
        siftdown(a , maxchild, n);
    }
    return;
}

void siftup(int *a, int i, int n)
{
    int temp = 0;
    int parind = (i-1)/2;
    if(i==0||i>=n || (i-1)/2>=n)
    {
        return;
    }
    if( a[i] > a[parind] )
    {
        temp = a[i];
        a[i] = a[parind];
        a[parind] = temp;
        siftup(a , parind, n);
    }
    return;
}

void insert(int*a, int *n, int i)
{
    //not functioning, fairly certain this is a windows problem
    a = (int*)realloc(a,*n+1*sizeof(int));
    a[*n] = i;
    *n+=1;
    siftup(a,*n-1,*n);
}

int extract_max(int*a, int *n)
{
    int x = a[0];
    int y = *n-1*sizeof(int);
    //printf("%d\n",y);
    a[0] = a[*n-1];
    a[*n-1] = 0; 
    //a = realloc(a,(*n-1)*sizeof(int));
    *n-=1;
    siftdown(a,0,*n);
    return x;
}
