#include <stdlib.h>
#include <stdio.h>

void merge(int arr[], int p, int q, int r)
{
    int nl = q - p + 1;
    int nr = r - q;
    int L[nl], R[nr], i, j;

    for (i = 0; i < nl; i++) {
        L[i] = arr[p + i];
    }

    for (j = 0; j < nr; j++) {
        R[j] = arr[q + j + 1];
    }

    printf("ANT Imprimindo array arr\n");
    for (int is = 0; is < 14; is++) {
        printf(is ? ",%d" : "%d", arr[is]);
    }
    printf(".\n");

    // printf("\nImprimindo array R\n");
    // for (int ik = 0; ik < nr; ik++) {
    //     printf(ik ? ",%d" : "%d", R[ik]);
    // }
    // printf(".\n");

    i = 0, j = 0;
    int k = p;

    while (i < nl && j < nr) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];            
            j++;
        } 
        k++;
    }

    printf("DPS Imprimindo array arr\n");
    for (int it = 0; it < 14; it++) {
        printf(it ? ",%d" : "%d", arr[it]);
    }
    printf(".\n");

    while (i < nl) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < nr) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int p, int r) {
    if (p >= r) {
        return;
    }

    int q = (p + r)/2;
    merge_sort(arr, p, q);
    merge_sort(arr, q + 1, r);

    merge(arr, p, q, r);
}

int main()
{
    int nums[15] = {9, 10, 23, 43, -1, -13, 1932, 105043, 40, -21, -23135, 12313, 498, -143, 5};


    int r = 14;
    int q = (0 + r)/2;

    // merge(nums, 0, q, r);
    merge_sort(nums, 0, 14);

    for (int ik = 0; ik < r; ik++) {
        printf(ik ? ",%d" : "%d", nums[ik]);
    }
    printf(".\n");

    return 0;
}