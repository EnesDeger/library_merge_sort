#include "merge_sort.h"
#include <stdlib.h>



void doMerge(int array[], int arr[], int size){


    for(int i=0;i<size;i++) {
        arr[i] = array[i];
    }
    mergeSort(arr,0,size-1);
}


void mergeSort(int arr[], int left, int right) {

    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left,mid);

        mergeSort(arr, mid+1,right);

        merge(arr, left, mid, right);

    }

}

void merge(int arr[], int left, int mid, int right) {

    int length_left = mid - left + 1;
    int length_right = right - mid;

    int *left_array = (int*)malloc(length_left*sizeof(int));
    int *right_array = (int*)malloc(length_right*sizeof(int));

    if(left_array == NULL || right_array == NULL) {
        perror("Memory allocation error");
        if (left_array != NULL) free(left_array);
        if (right_array != NULL) free(right_array);
        exit(1);
    }

    for(int i = 0; i < length_left; i++) {
       left_array[i] = arr[left + i];
    }

    for(int j = 0; j < length_right; j++) {
        right_array[j] = arr[mid + 1 + j];
    }


    int i = 0, j=0;
    int k = left;

    while (i<length_left && j<length_right ) {

        if (left_array[i] < right_array[j]) {
            arr[k] = left_array[i];
            i++;
        }
        else {
            arr[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < length_left) {
        arr[k] = left_array[i];
        i++;
        k++;
    }

    while (j < length_right) {
        arr[k] = right_array[j];
        j++;
        k++;
    }
    free (left_array);
    free (right_array);
}