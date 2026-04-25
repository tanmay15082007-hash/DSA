# include <stdio.h>
int main(){
    int i,j;
    int min_idx;
    int comparisions = 0;
    int arr[10];
    int swap = 0;
    int hae;
    for (int c = 0; c < 10; c++) {
        if (scanf("%d", &arr[c]) != 1) {
            return 1;
        }
    }
    for (int c = 0; c < 10; c++) {
        printf("%d ", arr[c]);
    }
    for (i = 0; i < 10; i++) {
        min_idx = i;
        for (j = i + 1; j < 10; j++) {
            comparisions++;
            if (arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            hae = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = hae;
            swap++;
        }
    }

    printf("\na) Sorted array: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nb) Metrics:");
    printf("\n   Total Comparisons: %d", comparisions);
    printf("\n   Total Swaps: %d\n", swap);

    return 0;
}
