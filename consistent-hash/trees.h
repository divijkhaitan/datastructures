#include "lists.h"
typedef struct node
{
    char* id;
    double val;
    ll* keys;
    struct node* left;
    struct node* right;
    struct node* parent;
    int height;
}node;

typedef struct tree
{
    node* root;
    int* ahash;
    int* khash;
    node* min;
    node* max;
}tree;
void insert(tree*a, char* str);
void printinorder(node* a);
node* search(tree*a, double n);
node* inorder_successor(tree* bst, node*a);
node* inorder_predeccessor(node* a);
node* maxchild(node* a);
node* minchild(node* a);
void del(tree* a,node* b);
int updateheight(node* a);
int getheight(node* a);
node* leftrotate(tree *a, node* b);
node* rightrotate(tree *a, node* b);
void balance(tree* a, node* b);
void delkey(tree*a, char* str);
void inskey(tree*a, char* str);
void reassignKeysAdd(tree*a, node* new);
void reassignKeysDel(tree*a, node* deleting);
