#include <stdlib.h>

#include "linked-list.h"

LinkedList* CreateList() {
    LinkedList* list = (struct LinkedList*) malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

void Push(LinkedList* list, int data) {
    Node* node = (struct Node*) malloc(sizeof(Node));
    if(node) {
        node->data = data;
        if(list->head == NULL) {
            list->head = node;
        }
        else {
            node->next = list->head;
            list->head = node;
        }
        list->size++;
    }
}

Node* Pop(LinkedList* list) {
    if(list->head) {
        Node* node = list->head;
        list->head = list->head->next;
        list->size--;
        return node;
    }
    return NULL;
}

void Clear(LinkedList *list){
    if(list != NULL) {
        Node* cur = list->head;
        Node* next;
        while(cur != NULL) {
            next = cur->next;
            free(cur);
            cur = next;
            list->size--;
        } 
    }
}
