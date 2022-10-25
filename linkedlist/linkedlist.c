#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
typedef struct Node{
  int value;
  struct Node *next;
} Node;

typedef struct linkedlist
{
    Node* head;
    Node* tail;
} linkedList;

void revLinkedListinPlace(Node* a);
void addToFrontOfList(linkedList* a, int b);
void printLL(linkedList* a);

bool hasloop(linkedList * a)
    {
        Node* rabbit= (*a).head;
        Node* tortoise= (*a).head;
        while(rabbit)
        {
            if(rabbit->next->next=tortoise->next)
            {
                if(rabbit->value=tortoise->value)
                {
                    return true;
                }
            }
            tortoise = tortoise->next;
            rabbit = rabbit->next;
            if(rabbit)
            {
                rabbit= rabbit->next;
            }
        }
        return false;
    }

void revLinkedListinPlace(Node* a)
{
    if((a->next))
    {
        if(a->next->next)
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

void addToFrontOfList(linkedList* a, int b)
{
    Node* temp = malloc(sizeof(Node));
    temp->value = b;
    if((a->head))
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

void addToBackOfList(linkedList* a, int b)
{
    Node* temp = malloc(sizeof(Node));
    temp->value = b;
    temp->next = NULL;
    if((a->tail))
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


void printLL(linkedList* a)
{
    if(!(a->head))
    {
        printf("Empty List\n");
        return;
    }
    Node * temp = a->head;
    while (temp->next)
    {
        printf("%d, ",temp->value);
        temp = temp->next;
    }
    printf("%d",temp->value);
    printf("\n");
    return;
}

void printLLrev(linkedList* a)
{
    if(!(a->tail))
    {
        printf("Empty List\n");
        return;
    }
    Node * temp = a->tail;
    while (temp->next)
    {
        printf("%d, ",temp->value);
        temp = temp->next;
    }
    printf("%d",temp->value);
    printf("\n");
    return;
}

linkedList* generateList(int size)
{
    linkedList* a = malloc(sizeof(linkedList));
    srand(time(NULL));
    for (int i = 0; i<size; i++)
    {
        addToBackOfList(a,rand()%1000);
    }
    return a;
}

int main()
{
    linkedList* a = generateList(10);
    printLL(a);
    revLinkedListinPlace(a->head);
    printLLrev(a);
    Node * temp = a->head; 
    Node * prev;
    while (temp)
    {
        prev = temp;
        temp = temp ->next;
        free(prev);
    }
    free(a);
    return 0;
}


