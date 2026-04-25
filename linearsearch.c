#include <stdio.h>

int main(){
    int arr[] = {10, 25, 30, 45, 50, 65, 70, 85, 90};
    int n     = 9;
    int key   = 45;
    int found = 0;
    int i;

    printf("Array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Searching for: %d\n\n", key);

    // ── LINEAR SEARCH ─────────────────────────────
    for(i = 0; i < n; i++){
        printf("Step %d: checking arr[%d] = %d\n", i+1, i, arr[i]);
        if(arr[i] == key){
            printf("\nFound %d at index %d!\n", key, i);
            found = 1;
            break;
        }
    }

    if(found == 0){
        printf("\n%d not found in array!\n", key);
    }

    return 0;
}