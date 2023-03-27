#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void print_array(int* array, unsigned int size) {
    for(int i = 0; i < size; i++) {
        printf("%i ", array[i]);
    }
    printf("\n");
}

void bubble_sort(int* array, unsigned int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size - 1 - i; j++) {
            if(array[j] > array[j + 1]) {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int main(int argc, char *argv[]) {
    const int size = 10;
    int array[] = {
        7,1,4,2,6,9,0,3,5,8
    };

    print_array(array, size);
    bubble_sort(array, size);
    print_array(array, size);
    return 0;
}


