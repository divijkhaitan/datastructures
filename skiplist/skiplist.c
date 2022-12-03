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

node* searchlevel(skiplist*list, int val, int level);

node* findpred(skiplist list,int val,int level);

node* findsucc(skiplist list,int val,int level);

void delete(skiplist* list, int val);

void printlist(skiplist* list);


int main()
{
    srand(time(NULL));
    skiplist* list = malloc(sizeof(skiplist));
    node*temp4 = malloc(sizeof(node));
    temp4->val = 4;
    temp4->size = 1;
    temp4->nextarr = malloc(sizeof(node*));
    temp4->nextarr[0] = NULL;
    
    node*temp3 = malloc(sizeof(node));
    temp3->val = 3;
    temp3->size = 2;
    temp3->nextarr = malloc(2*sizeof(node*));
    temp3->nextarr[0] = temp4;
    temp3->nextarr[1] = NULL;

    node*temp2 = malloc(sizeof(node));
    temp2->val = 2;
    temp2->size = 3;
    temp2->nextarr = malloc(3*sizeof(node*));
    temp2->nextarr[0] = temp3;
    temp2->nextarr[1] = temp3;
    temp2->nextarr[2] = NULL;
    list->tail = temp4;
    
    node*temp1 = malloc(sizeof(node));
    temp1->val = 1;
    temp1->size = 4;
    temp1->nextarr = malloc(4*sizeof(node*));
    temp1->nextarr[0] = temp2;
    temp1->nextarr[1] = temp2;
    temp1->nextarr[2] = temp2;
    temp1->nextarr[3] = NULL;
    list->tail = temp4;
    list->maxsize = 4;
    list->head = temp1;
    printlist(list);
    return 0;
}

// void insert(skiplist* list, int val)
// {
//     node* temp = malloc(sizeof(node));
//     temp->val = val;
//     int n = rand()/9;
//     int i =0;
//     while ((i < (list->maxsize)-1) && (n < 5))
//     {
//         i++;
//         n = rand()/9;
//     }
//     i++;
//     temp->nextarr = malloc(i*sizeof(node*));
//     temp->size = i;
//     if(list->head==NULL)
//     {
//         list->head = temp;
//         list->tail = temp;
//     }
//     else
//     {
//         node* pred = NULL;
//         node* succ = NULL;
//         bool smallest = false;
//         for(i = 0; i < temp->size;i++)
//         {
//             pred = searchlevel(list, val, 0);
//             if(pred)
//             {
//                 succ = pred->nextarr[i];
//                 pred->nextarr[i] = temp;
//                 temp->nextarr[i] = succ;
//             }
//             else
//             {
//                 smallest = true;
//                 break;
//             }
//         }
//         if(smallest)
//         {
//             temp->nextarr[0] = list->head;
//             list->head = temp;
//             for(int j =0;j<temp->size;j++)
//             {
//                 temp->nextarr[j] = searchlevel(list, val, j);
//             }
//         }
//     }
//     if(val>list->tail->val)
//     {
//         list->tail = temp;
//     }
// }

void printlist(skiplist*list)
{
    for(int i = list->maxsize-1; i>=0;i--)
    {
        for(node* temp = list->head; temp!=NULL; temp = temp->nextarr[i])
        {
            printf("%d\t", temp->val);
        }
        printf("\n");
    }
}

node* search(skiplist list, int val)
{
    node* temp = list->head;
    for(int i = list->maxsize-1;i>=0;i++)
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
        
    }
}