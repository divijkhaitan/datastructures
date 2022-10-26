#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct linkedlist
{
    Node *head;
    Node *tail;
} linkedList;

void revLinkedListinPlace(Node *a);
void addToFrontOfList(linkedList *a, int b);
void printLL(linkedList *a);
void printLLrev(linkedList *a);
void addToBackOfList(linkedList *a, int b);
void revlist(linkedList *a);
linkedList *generateList(int size);

bool hasloop(linkedList *a)
{
    Node *rabbit = (*a).head;
    Node *tortoise = (*a).head;
    while (rabbit)
    {
        if (rabbit->next->next = tortoise->next)
        {
            if (rabbit->value = tortoise->value)
            {
                return true;
            }
        }
        tortoise = tortoise->next;
        rabbit = rabbit->next;
        if (rabbit)
        {
            rabbit = rabbit->next;
        }
    }
    return false;
}

void revLinkedListinPlace(Node *a)
{
    if ((a->next))
    {
        if (a->next->next)
        {
            revLinkedListinPlace(a->next);
        }
        a->next->next = a;
        a->next = NULL;
    }
    else
    {
        printf("List of Size 1 is reversed by defintion");
    }
}

void addToFrontOfList(linkedList *a, int b)
{
    Node *temp = malloc(sizeof(Node));
    temp->value = b;
    if ((a->head))
    {
        temp->next = a->head;
        a->head = temp;
    }
    else
    {
        temp->next = NULL;
        a->head = temp;
        a->tail = temp;
    }
}

void addToBackOfList(linkedList *a, int b)
{
    Node *temp = malloc(sizeof(Node));
    temp->value = b;
    temp->next = NULL;
    if ((a->tail))
    {
        (a->tail)->next = temp;
        a->tail = temp;
        return;
    }
    else
    {
        a->tail = temp;
        a->head = temp;
        return;
    }
}

void printLL(linkedList *a)
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

void printLLrev(linkedList *a)
{
    if (!(a->tail))
    {
        printf("Empty List\n");
        return;
    }
    Node *temp = a->tail;
    while (temp->next)
    {
        printf("%d, ", temp->value);
        temp = temp->next;
    }
    printf("%d", temp->value);
    printf("\n");
    return;
}

void revlist(linkedList *a)
{
    if ((a->head)->next)
    {
        Node *temp = a->head;
        Node *temp1 = a->head;
        Node *temp2 = a->head->next;
        while (temp2)
        {
            temp1 = temp2;
            temp2 = temp2->next;
            temp1->next = temp;
            if (temp == a->head)
            {
                temp->next = NULL;
            }
            temp = temp1;
        }
        a->head = temp1; // if you want to change positioning of head. This will also invalidate the need for the above statement
    }
    else
    {
        printf("List of size 1 is reversed by definition\n");
    }
}

void revListChunks(linkedList *a, int n)
{
    Node* current;
    if ((a->head)->next)
    {
        Node *temp = a->head;
        Node *temp1 = a->head;
        Node *temp2 = a->head->next;
        current = a->head;
        for(int i=0;i<n;i++)
        {
            temp1 = temp2;
            temp2 = temp2->next;
            temp1->next = temp;
            if (temp == a->head)
            {
                a->head->next = NULL;
            }
            temp = temp1;
            if(temp2)
            {
                continue;
            }            
            else
            {
                break;
            }         
        }
        (current)->next=temp2;
        a->head = temp;
    }
    else
    {
        printf("List of size 1 is reversed by definition\n");
    }
}

linkedList *generateList(int size)
{
    linkedList *a = malloc(sizeof(linkedList));
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        addToBackOfList(a, rand() % 1000);
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

void selectionsort(int *a, int size)
{
    int min, temp, t;
    for (int i = 0; i < size; i++)
    {
        temp = i;
        for (int j = i; j < size; j++)
        {
            temp = (a[temp] < a[j]) ? temp : j;
        }
        if (temp == i)
            continue;
        else
        {
            t = a[temp];
            a[temp] = a[i];
            a[i] = t;
        }
    }
}

int main()
{
    linkedList *a = generateList(5);
    printLL(a);
    revListChunks(a, 3);
    printLL(a);
    //printLLrev(a);
    Node *temp = a->head;
    Node *prev;
    while (temp)
    {
        prev = temp;
        temp = temp->next;
        free(prev);
    }
    free(a);
    // int a[] = {17, 15, 164, 861, 362, 563, 14, 33, 280};
    // printarray(a, sizeof(a)/4);
    // selectionsort(a, sizeof(a)/4);
    // printarray(a, sizeof(a)/4);
    // return 0;
}
