# include <stdio.h>
int main(){
    int i,j;
    int min_idx;
    int comparisions = 0;
    int arr[10];
    int arr1[10];
    int swap = 0;
    int hae;
    for (int c = 0; c < 10; c++) {
        scanf("%d ", &arr[c]);
    }
    
    for(i=0;i<10;i++){
        min_idx = 0;
        for(j = i+1;j<10;j++){
            if(arr[i]>arr[j]){
            hae = arr[i];
            arr[i] = arr[j];
            arr[j] = hae;
            arr1[i] = arr[i];
            }
        }
    }
    return 0;
}