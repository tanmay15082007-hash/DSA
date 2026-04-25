#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 15;
    int arr[16];
    int i, key, index;

    // ── INITIALIZE ────────────────────────────────
    for(i = 0; i <= size; i++){
        arr[i] = 0;        // 0 means empty
    }

    // ── INSERT FUNCTION ───────────────────────────
    // BST rule:
    // smaller → go left  (2*i)
    // larger  → go right (2*i+1)

    // inserting root
    arr[1] = 50;

    // insert 30
    index = 1;
    while(arr[index] != 0){
        if(30 < arr[index])
            index = 2 * index;       // go left
        else
            index = 2 * index + 1;   // go right
    }
    arr[index] = 30;

    // insert 70
    index = 1;
    while(arr[index] != 0){
        if(70 < arr[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    arr[index] = 70;

    // insert 20
    index = 1;
    while(arr[index] != 0){
        if(20 < arr[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    arr[index] = 20;

    // insert 40
    index = 1;
    while(arr[index] != 0){
        if(40 < arr[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    arr[index] = 40;

    // insert 60
    index = 1;
    while(arr[index] != 0){
        if(60 < arr[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    arr[index] = 60;

    // insert 80
    index = 1;
    while(arr[index] != 0){
        if(80 < arr[index])
            index = 2 * index;
        else
            index = 2 * index + 1;
    }
    arr[index] = 80;

    // ── DISPLAY ARRAY ─────────────────────────────
    printf("Array representation:\n");
    for(i = 1; i <= size; i++){
        if(arr[i] != 0)
            printf("index[%d] = %d\n", i, arr[i]);
    }

    // ── TREE STRUCTURE ────────────────────────────
    printf("\nTree structure:\n");
    printf("           %d\n",         arr[1]);
    printf("          /  \\\n");
    printf("        %d     %d\n",     arr[2], arr[3]);
    printf("       / \\   / \\\n");
    printf("     %d   %d %d   %d\n",  arr[4], arr[5], arr[6], arr[7]);

    // ── INORDER TRAVERSAL ─────────────────────────
    // inorder of BST always gives sorted output
    printf("\nInorder (Left->Root->Right):\n");
    printf("%d ", arr[4]);   // left  of 30
    printf("%d ", arr[2]);   // 30
    printf("%d ", arr[5]);   // right of 30
    printf("%d ", arr[1]);   // root  50
    printf("%d ", arr[6]);   // left  of 70
    printf("%d ", arr[3]);   // 70
    printf("%d ", arr[7]);   // right of 70
    printf("\n");

    // ── PREORDER TRAVERSAL ────────────────────────
    printf("\nPreorder (Root->Left->Right):\n");
    printf("%d ", arr[1]);   // root  50
    printf("%d ", arr[2]);   // 30
    printf("%d ", arr[4]);   // left  of 30
    printf("%d ", arr[5]);   // right of 30
    printf("%d ", arr[3]);   // 70
    printf("%d ", arr[6]);   // left  of 70
    printf("%d ", arr[7]);   // right of 70
    printf("\n");

    // ── POSTORDER TRAVERSAL ───────────────────────
    printf("\nPostorder (Left->Right->Root):\n");
    printf("%d ", arr[4]);   // left  of 30
    printf("%d ", arr[5]);   // right of 30
    printf("%d ", arr[2]);   // 30
    printf("%d ", arr[6]);   // left  of 70
    printf("%d ", arr[7]);   // right of 70
    printf("%d ", arr[3]);   // 70
    printf("%d ", arr[1]);   // root  50
    printf("\n");

    // ── SEARCH ────────────────────────────────────
    key   = 40;
    index = 1;
    printf("\nSearching for %d:\n", key);
    while(arr[index] != 0 && index <= size){
        if(arr[index] == key){
            printf("Found %d at index %d\n", key, index);
            break;
        }
        else if(key < arr[index]){
            printf("%d < %d go left\n", key, arr[index]);
            index = 2 * index;       // go left
        }
        else{
            printf("%d > %d go right\n", key, arr[index]);
            index = 2 * index + 1;   // go right
        }
    }
    if(arr[index] == 0 || index > size){
        printf("%d not found!\n", key);
    }

    return 0;
}