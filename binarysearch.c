#include <stdio.h>

int main(){
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90};
    int n     = 9;
    int key   = 50;
    int low   = 0;
    int high  = n - 1;
    int mid;
    int found = 0;

    printf("Array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Searching for: %d\n\n", key);

    // ── BINARY SEARCH ─────────────────────────────
    while(low <= high){
        mid = (low + high) / 2;

        printf("low=%d mid=%d high=%d  checking arr[%d]=%d\n",
                low, mid, high, mid, arr[mid]);

        if(arr[mid] == key){
            printf("\nFound %d at index %d!\n", key, mid);
            found = 1;
            break;
        }
        else if(key < arr[mid]){
            printf("%d < %d → search left half\n\n",  key, arr[mid]);
            high = mid - 1;    // go left
        }
        else{
            printf("%d > %d → search right half\n\n", key, arr[mid]);
            low  = mid + 1;    // go right
        }
    }

    if(found == 0){
        printf("\n%d not found in array!\n", key);
    }

    return 0;
}