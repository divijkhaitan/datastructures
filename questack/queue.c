#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct queue
{
    Node *head;
    Node *tail;
    int size;
    int n;
} queue;

void printqueue(queue *a);
void push(queue *a, int b);
queue *generatequeue(int size);
int* generateArray(int size);
void printarray(int *a, int size);
int pop(queue* a);
int peek(queue* a);

int pop(queue* a)
{
    if(a->n == 0)
    {
        printf("queue underflow");
        return 0;
    }
    int n = a->head->value;
    Node* temp = a->head;
    a->head = a->head->next;
    free(temp);
    a->n -=1;
    return n;
}

void push(queue *a, int b)
{
    if(a->size == a->n)
    {
        printf("queue overflow");
        return;
    }
    Node *temp = malloc(sizeof(Node));
    temp->value = b;
    temp->next = NULL;
    if(a->head==NULL)
    {
        a->head = temp;
    }
    if(a->tail)
    {
        a->tail->next = temp;
    }
    a->tail = temp;
    a->n +=1;
}

int peek(queue *a)
{
    if(a->head)
    {
        return a->head->value;
    }
    else
    {
        printf("queue underflow");
    }
}

void printqueue(queue *a)
{
    if (!(a->head))
    {
        printf("Empty List\n");
        return;
    }
    Node *temp = a->head;
    while (temp->next)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("%d", temp->value);
    printf("\n");
    return;
}

queue *generatequeue(int size)
{
    queue *a = malloc(sizeof(queue));
    //The bottom two statments need to be added because malloc works differently in windows and linux
    //In a linux machine, mallocing a queue gives you null head and tail pointers while in windows it initialises
    //head and tail pointers with some value, thus a->tail-> next gives a segmentation fault
    a->head = NULL;
    a->tail = NULL;
    a->size = size;
    a->n = 0;
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        push(a, rand() % 1000);
    }
    return a;
}

int main()
{
    queue *a = generatequeue(15);
    printqueue(a);
    int k = 0;
    a->size +=1;
    push(a,1001);
    while(a->n > 0)
    {
        k = pop(a);
        printf("%d\t",k);
    }
    //int *a;
    // int size = 10;
    // a = generateArray(size);
    // int a[] = { 4,3,2,7,11,23,16,1,5,6 };
    // printarray(a, size);
    // insort(a, size);
    // printarray(a, size);
    free(a);
    return 0;
}
