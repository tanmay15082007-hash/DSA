#include <stdio.h>

void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Lomuto Partition
int partition(int A[], int low, int high){
    int pivot = A[low];   // pivot is first element
    int i = low;          // i tracks last smaller element
    int j;

    for(j = low+1; j <= high; j++){
        if(A[j] <= pivot){    // if current element smaller than pivot
            i++;
            swap(&A[i], &A[j]);  // swap to left side
        }
    }
    swap(&A[low], &A[i]);    // put pivot in correct position
    return i;                 // return pivot index
}

void quickSort(int A[], int low, int high){
    if(low < high){
        int pi = partition(A, low, high);  // pi = pivot index
        quickSort(A, low, pi-1);           // sort left of pivot
        quickSort(A, pi+1, high);          // sort right of pivot
    }
}

int main(){
    int A[] = {9, 3, 7, 1, 5, 8, 2, 6, 4};
    int n = 9;

    printf("Before sorting: ");
    printArray(A, n);

    quickSort(A, 0, n-1);

    printf("After sorting:  ");
    printArray(A, n);

    return 0;
}