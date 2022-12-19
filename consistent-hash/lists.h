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


void add(ll* list, char* id);

void concat(ll* list1, ll* list2);

void remove(ll* list, double val);

ll* getllFromFront(ll* list, double val);

llnode* search(ll*list, double val);