#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node{
  int value;
  struct Node *next;
} Node;

typedef struct linkedlist
{
    Node* head;
    Node* tail;
    int size;
} linkedList;

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
    if((a->next)->next==NULL)
    {
        (a->next)->next=a
        return
    }
    else
    {
        revLinkedListinPlace(a->next)
    }
    a->next->next=a
    return
}

int main()
{
    return 0;
}


