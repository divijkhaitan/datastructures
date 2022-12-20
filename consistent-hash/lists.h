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


void add(ll* list, char* id, int* hashvalues);

void concat(ll* list1, ll* list2);

void removeFromLL(ll* list, double val);

ll* getllFromFront(ll* list, double val);

llnode* searchll(ll*list, double val);