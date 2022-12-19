#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "lists.h"

void main()
{
    return 0;
}

void add(ll* list, char* id)
{
    llnode* temp = malloc(sizeof(llnode));
    temp->id = malloc(strlen(id)*sizeof(char));
    temp->id = id;
    temp->next =NULL;
    //temp->val = hash(id);
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
        }
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

void remove(ll*list, double val)
{
    llnode* temp = list->head;
    if(temp->val == val)
    {
        list->head = temp->next;
        free(temp);
        return;
    }
    while (temp->next)
    {
        if(temp->next->val == val)
        {
            llnode* temp2 = temp->next;
            temp->next = temp2->next;
            if(temp2 == list->tail)
            {
                list->tail = temp;
            }
            free(temp2);
        }
    }
    
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

llnode* search(ll*list, double val)
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
