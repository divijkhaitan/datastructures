#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include "lists.h"
// int main()
// {
//     char*arr[10]= {"The","One", "Piece", "tHE", "OnE", "PiEcE", "is", "rEal"};
//     int hashvalues[] = {367, 468};
//     ll* list = malloc(sizeof(ll));
//     list->head = NULL;
//     list->tail = NULL;
//     for(int i = 0; i < 9; i++)
//     {
//         add(list, arr[i], hashvalues);
//         printLL(list);
//     }
//     return 0;
// }

void add(ll* list, char* id, int* hashvalues)
{
    llnode* temp = malloc(sizeof(llnode));
    temp->id = malloc((strlen(id)+1)*sizeof(char));
    for(int i = 0; i < strlen(id); i++)
    {
        temp->id[i] = id[i];
    }
    temp->next =NULL;
    temp->val = hash(id, hashvalues);
    if(list->head == NULL)
    {
        list->head = temp;
        list->tail = temp;
        return;
    }
    
    if(temp->val<list->head->val)
    {
        temp->next = list->head;
        list->head = temp;
        return;
    }
    
    if(temp->val>list->tail->val)
    {
        list->tail->next = temp;
        list->tail = temp;
        return;
    }
    llnode* current = list->head;
    while (current->next)
    {
        if(current->next->val>temp->val)
        {
            temp->next = current->next;
            current->next = temp;
            break;
        }
        current = current->next;
    }
    
}

void concatll(ll* list1, ll* list2)
{
    if(list1->head == NULL || list2->head == NULL)
    {
        return;
    }
    list1->tail->next = list2->head;
}

void removeFromLL(ll*list, double val)
{
    llnode* temp = list->head;
    if(temp->val == val)
    {
        list->head = temp->next;
        free(temp->id);
        free(temp);
        return;
    }
    while (temp->next)
    {
        if(temp->next->val == val)
        {
            break;
        }
        temp = temp->next;
    }
    llnode* temp2 = temp->next;
    temp->next = temp2->next;
    if(temp2 == list->tail)
    {
        list->tail = temp;
    }
    free(temp2);
}

ll* getllFromFront(ll* list, double val)
{
    ll* new = malloc(sizeof(ll));
    if(list->head == NULL)
    {
        return NULL;
    }
    if(list->tail->val <val)
    {
        new->head = list->head;
        new->tail = list->tail;
        list->head = NULL;
        list->tail = NULL;
        return new;
    }
    llnode* temp = list->head;
    if(list->head->val> val)
    {
        new->head = NULL;
        new->tail = NULL;
        return new;
    }
    new->head = list->head;
    while (temp->next->val<val);
    {
        temp = temp->next;
    }
    new->tail = temp;
    return new;
}

llnode* searchll(ll*list, double val)
{
    if(list->head == NULL)
    {
        return NULL;
    }
    llnode* temp = list->head;
    while (temp)
    {
        if(temp->val == val)
        break;
    }
    return temp;
}

double hash(char* str, int * hashvalues)
{
    unsigned long long int val= 0;
    for(int i = 0; str[i]!=0; i++)
    {
        val+= str[i]*hashvalues[0];
        val*= str[i]*hashvalues[1];
    }
    double degrees = ((double)val/(double)ULLONG_MAX) *360;
    return degrees;
}

void printLL(ll *list)
{
    if(list==NULL)
    {
        return;
    }
    if (!(list->head))
    {
        printf("Empty List\n");
        return;
    }
    llnode *temp = list->head;
    while (temp->next)
    {
        printf("%lf %s, ", temp->val, temp->id);
        temp = temp->next;
    }
    printf("%lf %s", temp->val, temp->id);
    printf("\n");
    return;
}

llnode* pop(ll* list)
{
    if(list->tail == NULL)
    {
        return NULL;
    }
    llnode* temp = list->tail;
    removeFromLL(list, temp->val);
    return temp;
}
