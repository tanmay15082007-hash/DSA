#include <stdio.h>

int main(){
    int arr[50];
    int n;
    int i, j;
    int key;
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

    // ── INSERTION SORT ────────────────────────────
    for(i = 1; i < n; i++){

        key = arr[i];    // element to be inserted
        j   = i - 1;

        printf("Pass %d: key = %d\n", i, key);

        // shift elements greater than key to right
        while(j >= 0 && arr[j] > key){
            comparisons++;
            arr[j+1] = arr[j];   // shift right
            swaps++;
            j--;
        }

        // one more comparison when while condition fails
        if(j >= 0){
            comparisons++;
        }

        arr[j+1] = key;          // insert key at correct position

        // display after each pass
        printf("Array:  ");
        for(int k = 0; k < n; k++){
            if(k <= i){
                printf("[%d] ", arr[k]);   // sorted part
            }
            else{
                printf("%d ", arr[k]);     // unsorted part
            }
        }
        printf("\n\n");
    }

    // ── DISPLAY SORTED ARRAY ──────────────────────
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // ── DISPLAY STATISTICS ────────────────────────
    printf("\nTotal comparisons: %d\n", comparisons);
    printf("Total swaps:       %d\n",  swaps);

    return 0;
}