#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"


int main(void) {

        int *read_num=NULL;
        int k=0, current_memory=10;

        read_num=(int *)malloc(current_memory * sizeof(int));

        if(read_num==NULL) {
            printf("Memory allocation failed");
            return -1;
        }


        FILE *read = fopen("unsorted_nums.txt", "r");
        if (read == NULL) {
            printf("Error opening file");
            free(read_num);
            read_num=NULL;
            return 1;
        }

        FILE *write = fopen("sorted_nums.txt", "w");
        if (write == NULL) {
            printf("Error opening file");
            free(read_num);
            read_num=NULL;
            return 1;
        }

        while (fscanf(read ,"%d",&read_num[k]) == 1) {
            k++;
            if (k>=current_memory) {
                current_memory *= 2;
                int *temp=(int *)realloc(read_num, current_memory * sizeof(int));
                if(temp==NULL) {
                    printf("Memory allocation failed");
                    free(read_num);
                    read_num=NULL;
                    fclose(read);
                    fclose(write);
                    return -1;
                }
                read_num = temp;
            }
        }
    int arr[k];

    for(int i=0;i<k;i++) {
        arr[i]=read_num[i];
    }

    doMerge(read_num,arr,k);

    for(int i=0;i<k;i++) {
        fprintf(write,"%d ",arr[i]);
    }
    printf("length = %d",k);

    fclose(read);
    fclose(write);
    free(read_num);
    read_num = NULL;

    return 0;
}