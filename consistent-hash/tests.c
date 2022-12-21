#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include "trees.h"
#include "lists.h"
char* randstring(int length) 
{
    char* str = malloc(length + 1);
    int i;
    for (i = 0; i < length; i++) {
        str[i] = 'a' + rand() % 26;
    }
    str[length] = '\0';
    return str;
}



void case1()
{
    tree* bst = malloc(sizeof(tree));
    bst->root = NULL;
    bst->max = NULL;
    bst->min = NULL;
    bst->ahash = malloc(sizeof(int)*2);
    bst->khash = malloc(sizeof(int)*2);
    bst->ahash[0] = rand()%1000+1;
    bst->khash[0] = rand()%1000+1;
    bst->ahash[1] = rand()%1000+1;
    bst->khash[1] = rand()%1000+1;
    insert(bst, "TESTSERVER");
    char* str;
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    llnode* temp = bst->root->keys->head;
    llnode* current;
    while(temp)
    {
        current = temp->next;
        free(temp->id);
        free(temp);
        temp = current;
    }
    free(bst->root->id);
    free(bst->root->keys);
    free(bst->ahash);
    free(bst->khash);
    free(bst->root);
    free(bst);
}

void case2()
{
    //Does adding one anchor maintain ring property?
    tree* bst = malloc(sizeof(tree));
    bst->root = NULL;
    bst->max = NULL;
    bst->min = NULL;
    bst->ahash = malloc(sizeof(int)*2);
    bst->khash = malloc(sizeof(int)*2);
    bst->ahash[0] = rand()%1000+1;
    bst->khash[0] = rand()%1000+1;
    bst->ahash[1] = rand()%1000+1;
    bst->khash[1] = rand()%1000+1;
    insert(bst, "TESTSERVER");
    char* str;
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("\n");
    printf("After adding New server");
    printf("\n");
    insert(bst,"Additiontestserver");
    printinorder(bst->root);
    // llnode* temp = bst->root->keys->head;
    // llnode* current;
    // while(temp)
    // {
    //     current = temp->next;
    //     free(temp->id);
    //     free(temp);
    //     temp = current;
    // }
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case3()
{
    //does adding multiple anchors maintain ring property?
}

void case4()
{
    //is load balanced in every case? No
}

void case5()
{
    //is load balanced when anchors are duplicated?
}

void case6()
{
    //Does deleting a anchor maintain ring property?
}

void case7()
{
    //Does adding a key maintain ring property?
}

void case8()
{
    //does deleting a key maintain ring property?
}

void case9()
{
    //can all keys be deleted without problems being caused?
}

void case10()
{
    //can all anchors be deleted without problems being caused?
}

int main()
{
    srand(time(NULL));
    case2();
    return 0;
}
