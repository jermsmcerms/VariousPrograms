#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "test.h"

void EndTest(int passCount, int numTests) {
    if(passCount == numTests) {
        printf("%i \\ %i pass. Congrats!\n", passCount, numTests);
    }
    else {
        printf("%i \\ %i test pass...\n", passCount, numTests);
    }
}

int ValidateArgs(int argc, char** argv) {
    if(argc <= 1) {
        printf("argv[1] - (int numTests) is required\n");
        return -1;
    }
    // LinkedList* list = NULL;

    char *p;
    errno = 0;
    long conv = strtol(argv[1], &p, 10);

    if(errno != 0 || *p != '\0') {
        printf("failed to parse argv[1]: %s\n", argv[0]);
        return -1;
    }

    return conv;
}

int main(int argc, char** argv) {
    int numTests = ValidateArgs(argc, argv);
    
    if(numTests < 1) {
        printf("Minimum number of tests must be 1\n");
        return -1;
    }
    printf("Starting test on your linked list implementation\n");

    LinkedList* list = NULL;
    int passCount = 0;

    if((list = CreateTest())) {
        passCount++;
        printf("CreateTest passed\n");
    }
    else {
        EndTest(passCount, numTests);
    }

    if(numTests >= 2 && PushTest(list)) {
        passCount++;
    }

    if(numTests >= 4 && PopTest(list)) {
        passCount++;
    }
    
    if(numTests >=3 && ClearTest(list)) {
        passCount++;
        list = NULL;
    }

    EndTest(passCount, numTests); 

    return 0;
}
