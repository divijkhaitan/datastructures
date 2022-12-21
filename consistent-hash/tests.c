#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include "trees.h"
#include "lists.h"

void removekeysinorder(node* a)
{
    if(a == NULL)
    {
        return;
    }
    if(a->left)
    {
        removekeysinorder(a->left);
    }
    
    llnode* tempnode = a->keys->head;
    llnode* current;
    while (tempnode)
    {
        current = tempnode->next;
        removeFromLL(a->keys,tempnode->val);
        tempnode = current;
    }
    if(a->right)
    {
        removekeysinorder(a->right);
    }
    return;
}


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
    insert(bst, "TESTANCHOR");
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
    insert(bst, "TESTANCHOR");
    char* str;
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"AdditionTESTANCHOR");
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
    //Does adding multiple anchors maintain ring property?
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
    insert(bst, "TESTANCHOR");
    char* str;
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"AdditionTESTANCHOR");
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"Multitest");
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"TestingMultipleAdditions");
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"AdDITionTestMul");
    printinorder(bst->root);
    printf("\n");
    printf("After adding New anchor");
    printf("\n");
    insert(bst,"FinalADDITIONforTest");
    printinorder(bst->root);
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case4()
{
    //is load balanced when anchors are duplicated?
    //Does adding multiple anchors maintain ring property?
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
    char* str;
    char* ancharr[] = {"AnchorOne","SecondAnchor","AndThenThereWere3","AnchorNumber4","TheLastOftheAnchors"};
    char* ancharr1[] = {"1AnchorOne","1SecondAnchor","1AndThenThereWere3","1AnchorNumber4","1TheLastOftheAnchors"};
    char* ancharr2[] = {"2AnchorOne","2SecondAnchor","2AndThenThereWere3","2AnchorNumber4","2TheLastOftheAnchors"};
    for(int j = 0; j < 5; j++)
    {
        insert(bst,ancharr[j]);
    }
    for(int i = 0; i < 50; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("\n");
    printf("After Duplicating the anchors");
    printf("\n");
    for(int k = 0; k < 5; k++)
    {
        insert(bst,ancharr1[k]);
        insert(bst,ancharr2[k]);
    }
    printinorder(bst->root);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst->ahash);
    free(bst->khash);
    free(bst);
}

void case5()
{
    //Does deleting an anchor maintain ring property?
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
    char* str;
    insert(bst,"AdditionTESTANCHOR");
    insert(bst,"Multitest");
    insert(bst,"TestingMultipleAdditions");
    insert(bst,"AdDITionTestMul");
    insert(bst,"FinalADDITIONforTest");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("\n");
    printf("After Deleting anchor");
    printf("\n");
    del(bst,search(bst,hash("AdditionTESTANCHOR",bst->ahash)));
    printinorder(bst->root);
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case6()
{
    //does adding keys maintain ring property
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
    char* str;
    insert(bst,"AdditionTESTANCHOR");
    insert(bst,"Multitest");
    insert(bst,"TestingMultipleAdditions");
    insert(bst,"AdDITionTestMul");
    insert(bst,"FinalADDITIONforTest");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("Adding keys\n\n");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case7()
{
    //does deleting all of an anchors keys maintain ring property?
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
    char* str;
    insert(bst,"AdditionTESTANCHOR");
    insert(bst,"Multitest");
    insert(bst,"TestingMultipleAdditions");
    insert(bst,"AdDITionTestMul");
    insert(bst,"FinalADDITIONforTest");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("Removing all keys from one anchor\n\n");
    node* temp = search(bst,hash("TestingMultipleAdditions",bst->ahash));
    llnode* tempnode = temp->keys->head;
    llnode* current;
    while (tempnode)
    {
        current = tempnode->next;
        removeFromLL(temp->keys,tempnode->val);
        tempnode = current;
    }
    printinorder(bst->root);
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case8()
{
    //can all keys be deleted without problems being caused?
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
    char* str;
    insert(bst,"AdditionTESTANCHOR");
    insert(bst,"Multitest");
    insert(bst,"TestingMultipleAdditions");
    insert(bst,"AdDITionTestMul");
    insert(bst,"FinalADDITIONforTest");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("Removing all keys from all anchors\n\n");
    removekeysinorder(bst->root);
    printinorder(bst->root);
    free(bst->ahash);
    free(bst->khash);
    while(bst->root)
    {
        del(bst,bst->root);    
    }
    free(bst);
}

void case9()
{
    //can all anchors be deleted without problems being caused?
    //can all keys be deleted without problems being caused?
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
    char* str;
    insert(bst,"AdditionTESTANCHOR");
    insert(bst,"Multitest");
    insert(bst,"TestingMultipleAdditions");
    insert(bst,"AdDITionTestMul");
    insert(bst,"FinalADDITIONforTest");
    for(int i = 0; i < 15; i++)
    {
        str=randstring(10);
        inskey(bst,str);
        free(str);
    }
    printinorder(bst->root);
    printf("Removing all anchors\n\n");
    while(bst->root)
    {
        printf("\n After removing %s\n",bst->root->id);
        del(bst,bst->root);
        printinorder(bst->root);
    }
    free(bst->ahash);
    free(bst->khash);
    free(bst);
}

int main()
{
    srand(time(NULL));
    case9();
    return 0;
}
