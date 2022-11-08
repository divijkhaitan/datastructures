#include<stdio.h>
#include<stdlib.h>
#include <time.h>

typedef struct node
{
    int val;
    struct node* left;
    struct node* right;
    struct node* parent;
    int height;
}node;

typedef struct tree
{
    node* root;
}tree;
void insert(tree*a, int b);
tree* maketree(int*a, int n);
void printarray(int* a, int size);
int* generateArray(int size);
void printinorder(node* a);
node* inorder_successor(node*a);
node* inorder_predeccessor(node* a);
node* maxchild(node* a);
node* minchild(node* a);
void delete(node* b);
int nodeheight(node *a);
int updateheight(node* a);
int getheight(node* a);

int main()
{
    int size = 10;
    int* arr = generateArray(size);
    printarray(arr,size);
    tree* a= maketree(arr,size);
    printinorder(a->root);
    node* temp = a->root;
    return 0;
}

void insert(tree* a, int b)
{
    int h = 0;
    node* temp = a->root;
    node* temp2 = (node*)malloc(sizeof(node));
    temp2->height = 0;
    temp2->val = b;
    temp2->right = NULL;
    temp2->parent = NULL;
    temp2->left = NULL;
    if(temp == NULL)
    {
        a->root = temp2;
    }
    else
    {
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
                temp2->height = getheight(temp2);
                while (temp2->parent)
                {
                    if(temp2->parent->left==temp2)
                    {
                        h = (temp2->parent->right)?temp2->parent->right->height : 0;
                    }
                    if(temp2->parent->right==temp2)
                    {
                        h = (temp2->parent->left)?temp2->parent->left->height : 0;
                    }
                    if(h<=temp2->height)
                    {
                        temp2->parent->height = temp2->height+1;
                    }
                    temp2=temp2->parent;
                }
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
                temp2->height = getheight(temp2);
                while (temp2->parent)
                {
                    if(temp2->parent->left==temp2)
                    {
                        h = (temp2->parent->right)?temp2->parent->right->height : 0;
                    }
                    if(temp2->parent->right==temp2)
                    {
                        h = (temp2->parent->left)?temp2->parent->left->height : 0;
                    }
                    if(h<=temp2->height)
                    {
                        temp2->parent->height = temp2->height+1;
                    }
                    temp2=temp2->parent;
                }
                break;
            }
        }
    }
}

tree* maketree(int* a, int n)
{
    tree* bst = (tree*)malloc(sizeof(tree));
    bst->root = NULL;
    for(int i = 0; i < n; i++)
    {
        insert(bst,a[i]);
    }
    return bst;
}

int nodeheight(node *a)
{
    if(a==NULL)
    {
        return -1;
    }
    if(a->height!=0)
    {
        return a->height;
    }
    else if((a->left || a->right))
    {
        int b = nodeheight(a->left);
        int c = nodeheight(a->right);
        a->height = b>c? b+1:c+1;
        return a->height;
    }
    else
    {
        return a->height;
    }
}

void printarray(int *a, int size)
{
    int i;
    for (i = 0; i < size - 1; i++)
    {
        printf("%d, ", a[i]);
    }
    printf("%d\n", a[i]);
}

int* generateArray(int size)
{
    int *a = (int *)malloc(sizeof(int)*size);
    srand(time(NULL));
    for (int i = 0; i < size; i++)
    {
        a[i]= (rand() % 1000);
    }
    return a;
}

void printinorder(node* a)
{
    if(a->left)
    {
        printinorder(a->left);
    }
    printf("%d\t", a->val);
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
    return NULL;
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

void delete(node* b)
{
    if(b->left==NULL && b->right==NULL)
    {
        free(b);
        b==NULL;
    }
    else if ( (b->left==NULL) ^ (b->right==NULL))
    {
        if(b->left)
        {
            b->val = b->left->val;
            free(b->left);
            b->left = NULL;
        }
        if(b->right)
        {
            b->val = b->right->val;
            free(b->right);
            b->right = NULL;
        }
    }
    else
    {
        node* succ = inorder_successor(b);
        b->val = succ->val;
    }
}

int updateheight(node* a)
{
    if(a->left==NULL && a->right==NULL)
    {
        a->height = 0;
        return 0;
    }
    int b = 0;
    int c = 0;
    if(a->left)
    {
        b = updateheight(a->left);
    }
    if(a->right)
    {
        c = updateheight(a->right);
    }
    if(b == a->height-1 || c == a->height-1)
    {
        return a->height;
    }
    else
    {
        if(b>c)
        {
            a->height = b+1;
        }
        else
        {
            a->height = c+1;
        }
    }
}

int getheight(node* a)
{
    if(a==NULL)
    {
        return 0;
    }
    else
    {
        int l = getheight(a->left);
        int r = getheight(a->right);
        int height = l > r ? l : r;
        return height;
    }
}