#include <stdlib.h>
#include <stdio.h>

#define MAX_OUTPUT 100

void counting_sort(int array[], int size) {
    int output[MAX_OUTPUT];

    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int count[MAX_OUTPUT];

    for (int i = 0; i <= max; i++) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}

void print_array(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[] = {101, 20, 42, 42, 42, 2, 4, 4, 5, 9, 2, 2, 53, 42};
    int n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    counting_sort(array, n);
    print_array(array, n);

    return 0;
}