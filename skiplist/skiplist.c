#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

typedef struct node {
    int val;
    int size;
    struct node** nextarr;
} node;

typedef struct skiplist{
    node* head;
    node* tail;
    int maxsize;
} skiplist;


void insert(skiplist* list, int val);

node* search(skiplist* list, int val);

node* searchnew(skiplist* a, int val);

node* searchlevel(skiplist*list, int val, int level);

node* findpredlevel(skiplist* list,int val,int level);

node* findsucclevel(skiplist* list,int val,int level);

node* findfirstlevel(skiplist*list, int level);

void delete(skiplist* list, int val);

void printlist(skiplist* list);


int main()
{
    srand(time(NULL));
    skiplist* list = malloc(sizeof(skiplist));
    list->maxsize = 5;
    // node* temp5 = malloc(sizeof(node));
    // temp5->val = 10;
    // temp5->size = 4;
    // temp5->nextarr = malloc(4*sizeof(node*));
    // temp5->nextarr[0] = NULL;
    // temp5->nextarr[1] = NULL;
    // temp5->nextarr[2] = NULL;
    // temp5->nextarr[3] = NULL;

    
    // node*temp4 = malloc(sizeof(node));
    // temp4->val = 4;
    // temp4->size = 1;
    // temp4->nextarr = malloc(4*sizeof(node*));
    // temp4->nextarr[0] = temp5;
    
    // node*temp3 = malloc(sizeof(node));
    // temp3->val = 3;
    // temp3->size = 2;
    // temp3->nextarr = malloc(2*sizeof(node*));
    // temp3->nextarr[0] = temp4;
    // temp3->nextarr[1] = temp5;
    
    // node*temp2 = malloc(sizeof(node));
    // temp2->val = 2;
    // temp2->size = 3;
    // temp2->nextarr = malloc(3*sizeof(node*));
    // temp2->nextarr[0] = temp3;
    // temp2->nextarr[1] = temp3;
    // temp2->nextarr[2] = temp5;

    // node*temp1 = malloc(sizeof(node));
    // temp1->val = 1;
    // temp1->size = 4;
    // temp1->nextarr = malloc(4*sizeof(node*));
    // temp1->nextarr[0] = temp2;
    // temp1->nextarr[1] = temp2;
    // temp1->nextarr[2] = temp2;
    // temp1->nextarr[3] = temp5;

    // list->tail = temp4;
    // list->maxsize = 4;
    // list->head = temp1;
    // printlist(list);
    insert(list, 5);
    insert(list, 11);
    insert(list, 12);
    insert(list, 0);
    insert(list, 15);
    insert(list, 1);
    insert(list, 20);
    insert(list, -10);
    printlist(list);
    printf("\n");
    delete(list, -10);
    printlist(list);
    delete(list, 0);
    delete(list,12);
    printlist(list);
    return 0;
}

void insert(skiplist* list, int val)
{
    node* temp = malloc(sizeof(node));
    temp->val = val;
    int i =0;
    int n = rand()%9;
    while ((i < (list->maxsize)-1) && (n < 5))
    {
        i++;
        n = rand()/9;
    }
    i++;
    //i = 4;
    temp->nextarr = malloc(list->maxsize*sizeof(node*));
    temp->size = i;
    for(int j = 0; j < list->maxsize; j++)
    {
        temp->nextarr[j] = NULL;
    }
    //fixes number of pointers on node
    if(list->head==NULL)
    {
        list->head = temp;
        list->tail = temp;
    }
    //edge case for insertion of first node
    else
    {
        i--;
        node* pred;
        for(;i >= 0;i--)
        {
            pred = findpredlevel(list, val, i);
            if(pred==NULL)
            {
                temp->nextarr[i]==NULL;
                continue;
            }
            if(pred->val > val)
            {
                temp->nextarr[i] = pred;
            }
            else
            {
                temp->nextarr[i] = pred->nextarr[i];
                pred->nextarr[i] = temp;
            }
        }
        if(val < list->head->val)
        {
            list->head = temp;
        }
        
        if(val > list->tail->val)
        {
            list -> tail = temp;
        }
    }
}

void printlist(skiplist*list)
{
    for(int i = list->maxsize-1; i>=0;i--)
    {
        for(node* temp = findfirstlevel(list,i); temp!=NULL; temp = temp->nextarr[i])
        {
            printf("%d\t", temp->val);
        }
        printf("\n");
    }
}

node* search(skiplist* list, int val)
{
    node* temp = list->head;
    for(int i = list->maxsize-1;i>=0;i--)
    {
        while (temp->nextarr[i])
        {
            if(temp->val == val)
            {
                return temp;
            }
            if(temp->val<val && temp->nextarr[i]->val>val)
            {
                break;
            }
            temp = temp->nextarr[i];
        }
        if(temp->val == val)
        {
                return temp;
        }
    }
    return NULL;
}

node* searchnew(skiplist* list, int val)
{
    if(list->head==NULL)
    {
        return NULL;
    }
    node* temp = list->head;
    int i = temp->size-1;
    if(temp->val == val)
    {
        return temp;
    }
    while(temp)
    {
        if(i<0)
        {
            break;
        }
        if(temp->nextarr[i]==NULL)
        {
            i--;
        }
        if(temp->nextarr[i]->val == val)
        {
            return temp->nextarr[i];
        }
        else if(temp->nextarr[i]->val < val)
        {
            temp=temp->nextarr[i];
            i = temp->size-1;
        }
        else if (temp->nextarr[i]->val > val)
        {
            i--;
        }
    }
    return NULL;
}

node* searchlevel(skiplist* list, int val, int level)
{
    if(level >= list->maxsize)
    {
        return NULL;
    }
    int i = level;
    node* temp = list->head;
    while(temp)
    {
        if (temp->size<level)
        {
            temp=temp->nextarr[temp->size-1];
            continue;
        }
        else
        break;
    }
    while(temp)
    {
        if(temp->val == val)
        {
            return temp;
        }
        else if (temp->val>val)
        {
            return NULL;
        }
        temp = temp->nextarr[i];
    }
    return NULL;
}

node* findpredlevel(skiplist* list, int val, int level)
{
    int i = level;
    node* pred = findfirstlevel(list,level);
    if(pred->val >= val)
    {
        return pred;
    }
    while(pred)
    {
        if(pred->val < val)
        {
            if(pred->nextarr[level]==NULL)
            {
                return pred;
            }
            if(pred->nextarr[level]->val>=val)
            {
                return pred;
            }
            else
            {
                pred = pred->nextarr[level];
            }
        }
    }
    return NULL;
}

node* findfirstlevel(skiplist*list, int level)
{
    if(level >= list->maxsize)
    {
        return NULL;
    }
    node* first = list->head;
    while(first)
    {
        if (first->size<level)
        {
            first=first->nextarr[first->size-1];
            continue;
        }
        else
        break;
    }
    if(first==NULL)
    return NULL;
    if(first->size<level)
    {
        return NULL;
    }
    
    return first;
}

void delete(skiplist* list, int val)
{
    node* temp = searchnew(list, val);
    node* pred = NULL;
    if(temp==NULL)
    {
        printf("Element must exist to be deleted");
        return;
    }
    for(int i = temp->size-1;i>=0;i--)
    {
        pred=findpredlevel(list,val,i);
        pred->nextarr[i] = temp->nextarr[i];
    }
    if(temp==list->head)
    {
        list->head = temp->nextarr[0];
    }
    if(temp==list->tail)
    {
        list->tail = findpredlevel(list,val,0);
    }
    
    free(temp);
}
