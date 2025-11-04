#include <stdio.h>
#include <stdlib.h>

void Merge(int arr[], int start, int middle, int end){
    int i = start;
    int j = middle+1;
    int k = start;
    int* DArray = (int*)malloc(10 * sizeof(int));

    while (i <= middle && j <= end)
    {
        if (arr[i] < arr[j])
        {
            DArray[k] = arr[i];
            i++;
            k++;
        }else{
            DArray[k] = arr[j];
            j++;
            k++;
        }
    }

    while (i <= middle)
    {
        DArray[k] = arr[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        DArray[k] = arr[j];
        j++;
        k++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = DArray[i];
    }
    
}

void MergeSort(int arr[], int start, int end){
    if (start < end)
    {
        int middle = start + (end - start) /2;

        MergeSort(arr, start, middle);
        MergeSort(arr, middle+1, end);

        Merge(arr, start, middle, end);
    }
}

int main(){
    int arr[] = {2, 5, 7, 8, 6, 4};
    int n = sizeof(arr) / sizeof(int);
    printf("Before sort \n");
    for (int i = 0; i < n; i++)
    {
        printf("Index: %d Values: %d \n", i, arr[i]);
    }

    MergeSort(arr, 0, n-1);
    
    printf("after sort \n");
    for (int i = 0; i < n; i++)
    {
        printf("Index: %d Values: %d \n", i, arr[i]);
    }

    return 0;
}