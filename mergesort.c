#include <stdio.h>

void printArray(int A[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int A[], int low, int mid, int high){
    int i, j, k;
    int B[high+1];          // ✅ correct size

    i = low;
    j = mid + 1;
    k = low;

    // compare and merge into B
    while(i <= mid && j <= high){
        if(A[i] < A[j]){
            B[k] = A[i];
            i++; k++;
        }
        else{
            B[k] = A[j];
            j++; k++;
        }
    }                        // ✅ while loop ends here

    // copy remaining left half
    while(i <= mid){         // ✅ index compared to index
        B[k] = A[i];
        k++; i++;
    }

    // copy remaining right half
    while(j <= high){        // ✅ index compared to index
        B[k] = A[j];
        k++; j++;
    }

    // copy B back to A      // ✅ copy back added
    for(int i = low; i <= high; i++){
        A[i] = B[i];
    }
}

void mergesort(int A[], int low, int high){
    if(low < high){
        int mid;
        mid = (low + high) / 2;
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, low, mid, high);
    }
}

int main(){
    int A[] = {1, 2, 45, 23, 67, 11, 98, 56};
    int n = 8;                // ✅ correct size

    printf("Before sorting: ");
    printArray(A, n);

    mergesort(A, 0, n-1);    // ✅ n-1 not hardcoded

    printf("After sorting:  ");
    printArray(A, n);

    return 0;
}