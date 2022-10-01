#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct {
  int value;
  struct Node *next;
} Node;

typedef struct 
{
    Node* head;
    Node* tail;
    int size;
} linkedList;

bool hasloop(linkedList a)
    {
        Node* rabbit= a.head;
        Node* tortoise= a.head;
        while(rabbit)
        {
            if(rabbit->next=tortoise->next)
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

int main()
{
    return 0;
}


