#include "test.h"
#include <stdio.h>

#define NUM_DATA_PTS 10

const int data[NUM_DATA_PTS] = {
    0,1,2,3,4,5,6,7,8,9
};

const int expected[NUM_DATA_PTS] = {
    9,8,7,6,5,4,3,2,1,0
};

LinkedList* CreateTest() {
   return CreateList();
}

int ClearTest(LinkedList* list) {
    Clear(list);
    return list->size == 0;
}

int PushTest(LinkedList* list) {
    for(int i = 0; i < NUM_DATA_PTS; i++) {
        Push(list,data[i]);
    }

    return list->size == NUM_DATA_PTS;
}

int PopTest(LinkedList* list) {
    for(int i = 0; i < NUM_DATA_PTS; i++) {
        Node* node = Pop(list);
        if(node->data != expected[i]) {
            printf("Expected: %i, Actual: %i", expected[i], node->data);
            return 0;
        }
    }

    return 1;
}
