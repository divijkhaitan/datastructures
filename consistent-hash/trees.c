#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<limits.h>
#include "trees.h"
#include "lists.h"
// int main()
// {
//     srand(time(NULL));
//     char*arr[] = {"hjk857sfdg98", "qwertyuiopasdfghjklzxcvbnm", "abcdefghijklmnopqrstuvwxyz1234567890"};
//     char* kees[] = {"Jessica", "Michael", "Jennifer", "Christopher", "Amanda", "Matthew", "Sarah", "David", "Emily", "James"};
//     tree* bst = malloc(sizeof(tree));
//     bst->ahash = malloc(sizeof(int)*2);
//     bst->khash = malloc(sizeof(int)*2);
//     bst->ahash[0] = rand()%1000+1;
//     bst->khash[0] = rand()%1000+1;
//     bst->ahash[1] = rand()%1000+1;
//     bst->khash[1] = rand()%1000+1;
//     printf("%d %d Ahash\n", bst->ahash[0], bst->ahash[1]);
//     printf("%d %d Ahash\n", bst->khash[0], bst->khash[1]);
//     insert(bst,arr[0]);
//     insert(bst,arr[1]);
//     insert(bst,arr[2]);
//     for(int i = 0; i < 10; i++)
//     {
//         printf("Inserting %s %lf\n", kees[i], hash(kees[i],bst->khash));
//         inskey(bst, kees[i]);
//         printinorder(bst->root);
//         printf("\n");
//     }
//     insert(bst, "TESTSERVER");
//     printinorder(bst->root);
//     del(bst, search(bst, hash(arr[0],bst->ahash)));
//     printf("\n");
//     printinorder(bst->root);
//     return 0;
// }

void insert(tree* a, char* id)
{
    double b = hash(id, a->ahash);
    int h = 0;
    node* temp = a->root;
    node* temp2 = (node*)malloc(sizeof(node));
    node*temp3=NULL;
    //printf("%lf\n", b);
    temp2->height = 0;
    temp2->val = b;
    temp2->keys = malloc(sizeof(ll));
    temp2->keys->head = NULL;
    temp2->keys->tail = NULL;
    temp2->right = NULL;
    temp2->parent = NULL;
    temp2->left = NULL;
    temp2->id = malloc((strlen(id)+1)*sizeof(char));
    for(int i = 0; i < strlen(id); i++)
    {
        temp2->id[i] = id[i];
    }
    if(temp == NULL)
    {
        a->root = temp2;
        a->max = temp2;
        a->min = temp2;
        return;
    }
    if(b < a->min->val)
    {
        a->min = temp2;
    }
    if(b > a->max->val)
    {
        a->max = temp2;
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

void printinorder(node* a)
{
    if(a == NULL)
    {
        return;
    }
    if(a->left)
    {
        printinorder(a->left);
    }
    printf("%s\t",a->id);
    printf("%lf\t", a->val);
    //printf("%d\t", a->height);
    printf("\n");
    printLL(a->keys);
    if(a->right)
    {
        printinorder(a->right);
    }
    return;
}

node* inorder_successor(tree* bst, node*a)
{
    if(a == bst->max)
    {
        return bst->min;
    }
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

void del(tree* a,node* b)
{
    int h;
    if(b==NULL)
    {
        return;
    }
    if(b == a->root && b->left == NULL && b->right == NULL)
    {
        a->root = NULL;
        a->min = NULL;
        a->max = NULL;
        llnode* temp = b->keys->head;
        llnode* curr;
        while(temp)
        {
            curr = temp->next;
            free(temp->id);
            free(temp);
            temp = curr;
            }
        free(b->keys);
        //free(b->id);
        free(b);
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
        //free(b1->id);
        free(b1);
        return;
    }
    else if ( (b->left==NULL) ^ (b->right==NULL))
    {
        if(b->left)
        {
            reassignKeysDel(a,b);
            b->val = b->left->val;
            b->id = b->left->id;
            b->keys->head = b->left->keys->head;
            b->keys->tail = b->left->keys->tail;
            free(b->left->keys);
            //free(b->left->id);
            free(b->left);
            b->left = NULL;
            node* b1 = b;
            updateheight(b);
            balance(a,b1);
            return;
        }
        else if(b->right)
        {
            reassignKeysDel(a,b);
            b->val = b->right->val;
            b->id = b->right->id;
            b->keys->head = b->right->keys->head;
            b->keys->tail = b->right->keys->tail;
            free(b->right->keys);
            //free(b->right->id);
            free(b->right);
            b->right = NULL;
            node* b1 = b;
            updateheight(b);
            balance(a,b1);
            return;
        }
    }
    else
    {
        node* succ = inorder_successor(a,b);
        reassignKeysDel(a,b);
        b->val = succ->val;
        b->keys->head = succ->keys->head;
        b->keys->tail = succ->keys->tail;
        succ->keys->head=NULL;
        succ->keys->tail=NULL;
        //free(succ->id);
        free(succ->keys);
        succ->keys = NULL;
        // if(succ->parent->right == succ)
        // {
        //     succ->parent->right = NULL;
        // }
        // else if(succ->parent->left == succ)
        // {
        //     succ->parent->left = NULL;
        // }
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
        return -1;
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
        if(childleft<=childright)
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

void inskey(tree*a, char* str)
{
    if(a->root == NULL)
    {
        return;
    }
    double val;
    val = hash(str, a->khash);
    node* temp = a->root;
    node* temp2;
    while(temp)
    {
        if(temp->val > val)
        {
            temp2 = temp;
            temp = temp->left;
            continue;
        }
        if(temp->val < val)
        {
            temp2 = temp;
            temp = temp->right;
            continue;
        }
    }//this loop finds the location of the key if it were to be added into the tree as a server
    if(temp2->val > val)
    {
        add(temp2->keys, str, a->khash);
        return;
    }
    node* succ = inorder_successor(a, temp2);
    if(succ == NULL)
    {
        succ = a->min;
    }
    add(succ->keys, str, a->khash);
}

void delkey(tree*a, char* str)
{
    double val;
    //val = hash(str)
    node* temp = a->root;
    while (temp)
    {
        if(temp->left==NULL && temp->right==NULL && temp->val < val)
        {
            removeFromLL(inorder_successor(a,temp)->keys, val);
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
    node* succ = inorder_successor(a,new);
    if(succ==NULL)
    {
        succ = a->min;
    }
    if(succ->keys->head==NULL)
    {
        return;
    }
    
    if(new->val > succ->val)
    {
        llnode* temp = succ->keys->head;
        llnode* next;
        char *str;
        while(temp)
        {
            if(temp->val < succ->val)
            {
                temp = temp->next;
                continue;
            }
            if(temp->val > new->val)
            {
                temp = temp->next;
                continue;
            }
            if(temp->val < new->val)
            {
                next = temp->next;
                add(new->keys,temp->id,a->khash);
                removeFromLL(succ->keys, temp->val);
                temp = next;
            }
        }
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

void reassignKeysDel(tree*a, node* deleting)
{
    if(deleting==NULL)
    {
        return;
    }
    if(deleting->keys==NULL)
    {
        return;
    }
    if(deleting->keys->head==NULL)
    {
        return;
    }
    node* succ = inorder_successor(a,deleting);
    
    if(succ->val<deleting->val)
    {
        for(llnode* temp = deleting->keys->head; temp; temp = temp->next)
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
