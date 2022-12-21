#ifndef LISTS_H
#define LISTS_H
typedef struct llnode
{
    char* id;
    double val;
    struct llnode* next;
}llnode;

typedef struct ll{
    llnode* head;
    llnode* tail;
}ll;


void add(ll* list, char* id, int* hashvalues);

void concat(ll* list1, ll* list2);

llnode* pop(ll* list);

void removeFromLL(ll* list, double val);

ll* getllFromFront(ll* list, double val);

llnode* searchll(ll*list, double val);

double hash(char* str, int* list);

void printLL(ll *list);

#endif