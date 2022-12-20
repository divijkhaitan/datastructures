#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "trees.h"
#include "lists.h"
int main()
{
    srand(time(NULL));
    int size = 10;
    //double arr[10]= {1040813.949000, 447398.685000, 1721528.225000, 2117169.604000, 1698151.717000, 1847392.342000, 1632279.278000, 1427539.101000, 1013786.566000, 928263.239000};
    double* arr = generateArray(size);
    printarray(arr,size);
    tree* a= maketree(arr,size);
    //printinorder(a->root);
    printf("\n");
    del(a, a->root);
    printinorder(a->root);
    return 0;
}
//test with keys
void insert(tree* a, double b)
{
    int h = 0;
    node* temp = a->root;
    node* temp2 = (node*)malloc(sizeof(node));
    node*temp3=NULL;
    temp2->height = 0;
    temp2->val = b;
    temp2->keys = malloc(sizeof(ll));
    temp2->keys->head = NULL;
    temp2->keys->tail = NULL;
    temp2->right = NULL;
    temp2->parent = NULL;
    temp2->left = NULL;
    if(temp == NULL)
    {
        a->root = temp2;
        a->max = b;
        a->min = b;
        return;
    }
    if(b < a->min)
    {
        a->min = b;
    }
    if(b > a->max)
    {
        a->max = b;
    }
    while (temp)
    {
        if(b < temp->val && temp->left)
        {
            temp = temp->left;
            continue;
        }
        else if (b < temp->val && temp->left==NULL)
        {
            temp-> left = temp2;
            temp2->parent = temp;
            updateheight(temp2);
            balance(a, temp2);
            reassignKeysAdd(a,temp2);
            break;
        }
        else if(b > temp->val && temp->right)
        {
            temp = temp->right;
            continue;
        }
        else if (b > temp->val && temp->right==NULL)
        {
            temp-> right = temp2;
            temp2->parent = temp;
            updateheight(temp2);
            balance(a,temp2);
            reassignKeysAdd(a,temp2);
            break;
        }
    }
}

tree* maketree(double* a, int n)
{
    tree* bst = (tree*)malloc(sizeof(tree));
    bst->root = NULL;
    bst->ahash = malloc(sizeof(int)*2);
    bst->ahash[0] = rand()%1000;
    bst->ahash[1] = rand()%1000;
    bst->khash = malloc(sizeof(int)*2);
    bst->khash[0] = rand()%1000;
    bst->khash[1] = rand()%1000;
    for(int i = 0; i < n; i++)
    {
        // if(bst->root)
        // {
        //     printf("Root = %lf\n",bst->root->val);
        // }
        // printf("Inserting = %lf\n",a[i]);
        insert(bst,a[i]);
        // printinorder(bst->root);
        // printf("\n");
    }
    return bst;
}

void printarray(double *a, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%lf, ", a[i]);
    }
    printf("%lf\n", a[i]);
}

double* generateArray(int size)
{
    double *a = malloc(sizeof(double)*size);
    for (int i = 0; i < size; i++)
    {
        a[i]= ((double)rand() / 1000.0);
    }
    return a;
}

void printinorder(node* a)
{
    if(a->left)
    {
        printinorder(a->left);
    }
    printf("%lf\t", a->val);
    printf("%d\n", a->height);
    if(a->right)
    {
        printinorder(a->right);
    }
    return;
}

node* inorder_successor(node*a)
{
    if(a->right)
    {
        a = minchild(a->right);
        return a;
    }
    else
    {
        while (a->parent)
        {
            if(a->parent->left == a)
            {
                return a->parent;
            }
            a = a->parent;
        }
    }
    while (a)
    {
        a = a->left;
    }
    return a;
}

node* inorder_predeccessor(node* a)
{
    if(a->left)
    {
        a = maxchild(a->left);
        return a;
    }
    else
    {
        while (a->parent)
        {
            if(a->parent->right == a)
            {
                return a->parent;
            }
            a = a->parent;
        }
    }
    while (a)
    {
        a = a->right;
    }
    return a;
}

node* maxchild(node* a)
{
    if(a==NULL)
    {
        return NULL;
    }
    else
    {
        while (a->right)
        {
            a = a->right;
        }
    }
    return a;
}

node* minchild(node* a)
{
    if(a==NULL)
    {
        return NULL;
    }
    else
    {
        while (a->left)
        {
            a = a->left;
        }
    }
    return a;
}
//test with keys
void del(tree* a,node* b)
{
    int h;
    if(b==NULL)
    {
        return;
    }
    if(b->left==NULL && b->right==NULL)
    {
        if(b->parent->right == b)
        {
            b->parent->right = NULL;
        }
        else if(b->parent->left == b)
        {
            b->parent->left = NULL;
        }
        updateheight(b->parent);
        node* b1 = b;
        b = b->parent;
        balance(a,b1);
        reassignKeysDel(a,b1);
        free(b1);
    }
    else if ( (b->left==NULL) ^ (b->right==NULL))
    {
        if(b->left)
        {
            reassignKeysDel(a,b);
            b->val = b->left->val;
            b->keys = b->left->keys;
            free(b->left);
            b->left = NULL;
            node* b1 = b;
            updateheight(b);
            balance(a,b1);
        }
        else if(b->right)
        {
            reassignKeysDel(a,b);
            b->val = b->right->val;
            b->keys = b->right->keys;
            free(b->right);
            b->right = NULL;
            node* b1 = b;
            updateheight(b);
            balance(a,b1);
        }
    }
    else
    {
        node* succ = inorder_successor(b);
        reassignKeysDel(a,b);
        b->val = succ->val;
        b->keys = succ->keys;
        if(succ->parent->right == succ)
        {
            succ->parent->right = NULL;
        }
        else if(succ->parent->left == succ)
        {
            succ->parent->left = NULL;
        }
        node* succ2 = succ->parent;
        updateheight(succ2);
        balance(a,succ);
        del(a,succ);
    }
}

int updateheight(node* a)
{
    if(a==NULL)
    {
        return 0;
    }
    a->height = getheight(a);
    updateheight(a->parent);
}

int getheight(node* a)
{
    if(a==NULL)
    {
        return -1;
    }
    else
    {
        int l = (a->left)?getheight(a->left):-1;
        int r = (a->right)?getheight(a->right):-1;
        int height = l > r ? l+1 : r+1;
        return height;
    }
}

node* search(tree*a, double n)
{
    node* temp = a->root;
    while(temp)
    {
        if(temp->val > n)
        {
            temp = temp->left;
        }
        else if(temp->val < n)
        {
            temp = temp->right;
        }
        else if(temp->val == n)
        {
            return temp;
        }
    }
    return NULL;
}

node* leftrotate(tree *a, node* b)
{
    node* lc = b->left;
    node* rc = b->right;
    node* temp = NULL;
    b->right = rc->left;
    if(rc->left)
    {
        rc->left->parent = b;
    }
    rc->left = b;
    rc->parent = b->parent;
    if(b->parent &&b->parent->right==b)
    {
        b->parent->right = rc;
    }
    else if (b->parent && b->parent->left==b)
    {
        b->parent->left = rc;
    }
    b->parent = rc;
    // b->height = getheight(b);
    // int branchheight = getheight((rc->right));
    // rc->height = (b->height>branchheight)?b->height+1:branchheight+1;
    updateheight(b);
    if(b==a->root)
    {
        a->root = rc;
    }
    return rc;
}

node* rightrotate(tree *a, node* b)
{
    node* lc = b->left;
    node* rc = b->right;
    node* temp = NULL;
    b->left = lc->right;
    if(lc->right)
    {
        lc->right->parent = b;
    }
    lc->right = b;
    lc->parent = b->parent;
    if(b->parent && b->parent->right==b)
    {
        b->parent->right = lc;
    }
    else if (b->parent && b->parent->left==b)
    {
        b->parent->left = lc;
    }
    b->parent = lc;
    updateheight(b);
    // b->height = getheight(b);
    // int branchheight = getheight((lc->left));
    // lc->height = (b->height>branchheight)?b->height+1:branchheight+1;
    if(b==a->root)
    {
        a->root = lc;
    }
    return lc;
}

void balance(tree* a, node* b)
{
    if(b==NULL)
    {
        return;
    }
    int childleft, childright;
    int leftsize = (b->left)? b->left->height+1:0;
    int rightsize = (b->right)?b->right->height+1:0;
    if(leftsize-rightsize>1)
    {
        childleft = (b->left->left)?b->left->left->height+1:0;
        childright = (b->left->right)?b->left->right->height+1:0;
        if(childleft>=childright)
        {
            rightrotate(a,b);
            balance(a,b->parent);
        }
        else
        {
            b = leftrotate(a,b->left);
            b = rightrotate(a,b->parent);
            balance(a,b->parent);
        }
    }
    else if(leftsize-rightsize<-1)
    {
        childleft = (b->right->left)?b->right->left->height:0;
        childright = (b->right->right)?b->right->right->height:0;
        if(childleft<childright)
        {
            leftrotate(a,b);
            balance(a,b->parent);
        }
        else
        {
            b = rightrotate(a,b->right);
            b = leftrotate(a,b->parent);
            balance(a,b->parent);
        }
    }
    else
    {
        balance(a,b->parent);
    }

}
//test
void inskey(tree*a, char* str)
{
    double val;
    //val = hash(str)
    node* temp = a->root;
    while (temp)
    {
        if(temp->left==NULL && temp->right==NULL && temp->val < val)
        {
            add(inorder_successor(temp)->keys, str, a->khash);
            return;
        }
        
        if((temp->val >=val) && (temp->left == NULL || temp->left->val < val))
        {
            add(temp->keys, str, a->khash);
            return;
        }
        
        if(temp->val<val)
        {
            temp = temp->right;
            continue;
        }

        if(temp->val>=val)
        {
            temp = temp->left;
            continue;
        }
    }
}
//test

void delkey(tree*a, char* str)
{
    double val;
    //val = hash(str)
    node* temp = a->root;
    while (temp)
    {
        if(temp->left==NULL && temp->right==NULL && temp->val < val)
        {
            removeFromLL(inorder_successor(temp)->keys, val);
            return;
        }
        
        if((temp->val >=val) && (temp->left == NULL || temp->left->val < val))
        {
            removeFromLL(temp->keys,val);
            return;
        }
        
        if(temp->val<val)
        {
            temp = temp->right;
            continue;
        }

        if(temp->val>=val)
        {
            temp = temp->left;
            continue;
        }
    }
}


void reassignKeysAdd(tree*a, node* new)
{
    node* succ = inorder_successor(new);
    if(succ->keys->head==NULL)
    {
        return;
    }
    
    if(new->val > succ->val)
    {
        // new->keys->head = succ->keys->head;
        // succ->keys->head = NULL;
        //new->keys->tail = succ->keys->tail;
        //succ->keys->tail = NULL;
        llnode* temp = succ->keys->head;    //temp points to the head of the successor. We need to move the tail of the successor node to
        while(temp->val < succ->val)        //key before the successor on the ring, and map the rest of the nodes to the new node
        {
            succ->keys->tail = temp;
            temp = temp->next;
        }
        new->keys->head = temp;
        llnode* temp2;
        while(temp->val < new->val)         //need to adjust for edge case where there are keys greater than the anchor, so we move the tail pointer to
        {                                   //the last key less than the new anchor and terminate the list
            temp2 = temp;                   //point of termination of list when loop ends
            temp = temp->next;              //key after point of termination, which must be mapped back to the successor
        }
        new->keys->tail = temp2;            
        new->keys->tail->next = NULL;       //terminate list
        succ->keys->tail->next = temp;      //append to back of successors node list
        while(temp->next)                   //update tail pointer
        {
            temp = temp->next;
        }
        succ->keys->tail = temp;
        return;
    }
    
    if(new->val > succ->keys->tail->val)    //assign whole list to new anchor, since it will take every key
    {
        new->keys->head = succ->keys->head;
        succ->keys->head = NULL;
        new->keys->tail = succ->keys->tail;
        succ->keys->tail = NULL;
        return;
    }
    
    if(new->val < succ->keys->head->val)    // no change needed, no keys need to be assigned to the new anchor
    {
        return;
    }
    //common case: the new anchor has the head of the old anchor. Traverse the list until you find the tail and assign the next node as the head
    //of the new anchor 
    new->keys->head = succ->keys->head;
    llnode* temp = succ->keys->head;
    while (temp->val < new->val)
    {
        new->keys->tail = temp;
        temp = temp->next;
    }
    succ->keys->head = temp;
    new->keys->tail->next = NULL;
    return;
}
//test
void reassignKeysDel(tree*a, node* deleting)
{
    node* succ = inorder_successor(deleting);
    if(succ->val<deleting->val)
    {
        for(llnode* temp = deleting->keys->head; temp; temp->next)
        {
            add(succ->keys, temp->id, a->khash);
            removeFromLL(deleting->keys, temp->val);
        }
        return;
    }
    deleting->keys->tail->next = succ->keys->head;
    succ->keys->head = deleting->keys->head;
    deleting->keys->head = NULL;
    deleting->keys->tail = NULL;
}
