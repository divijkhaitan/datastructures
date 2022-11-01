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
    Node* next;
    int count;
    bool listleft = true;
    if ((a->head)->next)
    {
        Node *temp = a->head;
        Node *temp1 = a->head;
        Node *temp2 = a->head->next;
        current = a->head;
        while(temp2 && listleft)
        {
            count=0;
            for(int i=0;i<n-1;i++)
            {   
                count++;
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
                    listleft=false;
                    break;
                }         
            }
            if(current == a->head)
            {
                a->head = temp;
            }
            if(next)
            {
                next = temp2;
                (current)->next=temp;
                current = temp;
                for(int i=0;i<count;i++)
                {
                    current=current->next;
                }
            }
            else
            {
                next = temp2;
            }
            if(temp2)
            {
                temp1=temp2;
                temp=temp1;
                temp2=temp2->next;
            }
            else
            {
                listleft=false;
                break;
            }
        }
        printf("Here\n");
        current->next=next;
        // for(int i =0;i<count-1;i++)
        // {
        //      current=current->next;
        // }
        
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

void insort(int* a, int n)
{
    int ind, temp;
    for(int i=1;i<n;i++)
    {
        ind = i;
        temp = a[i];
        for(int j = ind; j >0; j--)
        {
            if(a[j-1]>temp)
            {
                a[j] = a[j-1];
                ind--;
            }
        }
        a[ind] = temp;
    }
}

int main()
{
    // linkedList *a = generateList(15);
    // printLL(a);
    // revListChunks(a, 5);
    // printLL(a);
    // //printLLrev(a);
    // Node *temp = a->head;
    // Node *prev;
    // while (temp)
    // {
    //     prev = temp;
    //     temp = temp->next;
    //     free(prev);
    // }(
    // free(a);
    int *a;
    int size = 5;
    a = generateArray(size);
    printarray(a, size);
    insort(a, size);
    printarray(a, size);
    free(a);
    return 0;
}
