typedef struct LinkedList {
    struct Node* head;
    int size;
} LinkedList;

typedef  struct Node {
    int data;
    struct Node* next;
} Node;

LinkedList* CreateList();
void Push(LinkedList* list, int data);
Node* Pop(LinkedList* list);
void  Clear(LinkedList* list);
