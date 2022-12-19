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

typedef struct node
{
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
}tree;
void insert(tree*a, double b);
tree* maketree(double*a, int n);
void printarray(double* a, int size);
double* generateArray(int size);
void printinorder(node* a);
node* search(tree*a, double n);
node* inorder_successor(node*a);
node* inorder_predeccessor(node* a);
node* maxchild(node* a);
node* minchild(node* a);
void del(tree* a,node* b);
int updateheight(node* a);
int getheight(node* a);
node* leftrotate(tree *a, node* b);
node* rightrotate(tree *a, node* b);
void balance(tree* a, node* b);
