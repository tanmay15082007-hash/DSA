#include <stdio.h>

int main(){
    int arr[50];
    int n;
    int i, j;
    int minIndex;
    int temp;
    int comparisons = 0;
    int swaps       = 0;

    // ── ACCEPT INPUT ──────────────────────────────
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // ── DISPLAY ORIGINAL ARRAY ────────────────────
    printf("\nOriginal array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // ── SELECTION SORT ────────────────────────────
    for(i = 0; i < n-1; i++){

        minIndex = i;    // assume first element is minimum

        // find minimum in remaining array
        for(j = i+1; j < n; j++){
            comparisons++;
            if(arr[j] < arr[minIndex]){
                minIndex = j;    // update minimum index
            }
        }

        // swap minimum with first unsorted element
        if(minIndex != i){
            temp         = arr[i];
            arr[i]       = arr[minIndex];
            arr[minIndex]= temp;
            swaps++;
        }

        // display after each pass
        printf("Pass %d: ", i+1);
        for(int k = 0; k < n; k++){
            if(k == i){
                printf("[%d] ", arr[k]);  // sorted element
            }
            else{
                printf("%d ", arr[k]);
            }
        }
        printf("  → min=%d placed at index %d\n", arr[i], i);
    }

    // ── DISPLAY SORTED ARRAY ──────────────────────
    printf("\nSorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ── DISPLAY STATISTICS ────────────────────────
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps:       %d\n",  swaps);

    return 0;
}