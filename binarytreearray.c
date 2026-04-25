#include <stdio.h>
#include <stdlib.h>

int main(){
    int size = 7;
    int arr[8];
    int i;

    // ── INITIALIZE ────────────────────────────────
    for(i = 0; i <= size; i++){
        arr[i] = 0;        // 0 means empty
    }

    // ── INSERT NODES ──────────────────────────────
    arr[1] = 10;   // root
    arr[2] = 20;   // left  of root
    arr[3] = 30;   // right of root
    arr[4] = 40;   // left  of node 20
    arr[5] = 50;   // right of node 20
    arr[6] = 60;   // left  of node 30
    arr[7] = 70;   // right of node 30

    // ── DISPLAY ARRAY ─────────────────────────────
    printf("Array representation:\n");
    for(i = 1; i <= size; i++){
        printf("index[%d] = %d\n", i, arr[i]);
    }

    // ── TREE STRUCTURE ────────────────────────────
    printf("\nTree structure:\n");
    printf("          %d\n",         arr[1]);
    printf("         /  \\\n");
    printf("       %d     %d\n",     arr[2], arr[3]);
    printf("      / \\   / \\\n");
    printf("    %d   %d %d   %d\n",  arr[4], arr[5], arr[6], arr[7]);

    // ── RELATIONSHIPS ─────────────────────────────
    printf("\nRelationships:\n");

    // root
    printf("Root                   = %d\n", arr[1]);

    // left and right child of root
    printf("Left  child of root    = %d\n", arr[2*1]);
    printf("Right child of root    = %d\n", arr[2*1+1]);

    // left and right child of node at index 2
    printf("Left  child of %d      = %d\n", arr[2], arr[2*2]);
    printf("Right child of %d      = %d\n", arr[2], arr[2*2+1]);

    // left and right child of node at index 3
    printf("Left  child of %d      = %d\n", arr[3], arr[2*3]);
    printf("Right child of %d      = %d\n", arr[3], arr[2*3+1]);

    // parent of index 4
    printf("Parent of %d           = %d\n", arr[4], arr[4/2]);

    // parent of index 5
    printf("Parent of %d           = %d\n", arr[5], arr[5/2]);

    // parent of index 6
    printf("Parent of %d           = %d\n", arr[6], arr[6/2]);

    // parent of index 7
    printf("Parent of %d           = %d\n", arr[7], arr[7/2]);

    // ── INORDER (Left → Root → Right) ────────────
    printf("\nInorder (Left->Root->Right):\n");
    printf("%d ", arr[4]);   // left  of node 2
    printf("%d ", arr[2]);   // node  2
    printf("%d ", arr[5]);   // right of node 2
    printf("%d ", arr[1]);   // root
    printf("%d ", arr[6]);   // left  of node 3
    printf("%d ", arr[3]);   // node  3
    printf("%d ", arr[7]);   // right of node 3
    printf("\n");

    // ── PREORDER (Root → Left → Right) ───────────
    printf("\nPreorder (Root->Left->Right):\n");
    printf("%d ", arr[1]);   // root
    printf("%d ", arr[2]);   // node  2
    printf("%d ", arr[4]);   // left  of node 2
    printf("%d ", arr[5]);   // right of node 2
    printf("%d ", arr[3]);   // node  3
    printf("%d ", arr[6]);   // left  of node 3
    printf("%d ", arr[7]);   // right of node 3
    printf("\n");

    // ── POSTORDER (Left → Right → Root) ──────────
    printf("\nPostorder (Left->Right->Root):\n");
    printf("%d ", arr[4]);   // left  of node 2
    printf("%d ", arr[5]);   // right of node 2
    printf("%d ", arr[2]);   // node  2
    printf("%d ", arr[6]);   // left  of node 3
    printf("%d ", arr[7]);   // right of node 3
    printf("%d ", arr[3]);   // node  3
    printf("%d ", arr[1]);   // root
    printf("\n");

    return 0;
}