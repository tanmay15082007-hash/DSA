#include <stdio.h>

#define SIZE 100

int tree[SIZE];

// Function to initialize tree
void initTree() {
    for (int i = 0; i < SIZE; i++) {
        tree[i] = -1;  // -1 means empty
    }
}

// Insert root
void insertRoot(int value) {
    if (tree[0] != -1)
        printf("Tree already has a root\n");
    else
        tree[0] = value;
}

// Insert left child
void insertLeft(int parentIndex, int value) {
    int leftIndex = 2 * parentIndex + 1;

    if (tree[parentIndex] == -1) {
        printf("Parent does not exist\n");
    } else if (tree[leftIndex] != -1) {
        printf("Left child already exists\n");
    } else {
        tree[leftIndex] = value;
    }
}

// Insert right child
void insertRight(int parentIndex, int value) {
    int rightIndex = 2 * parentIndex + 2;

    if (tree[parentIndex] == -1) {
        printf("Parent does not exist\n");
    } else if (tree[rightIndex] != -1) {
        printf("Right child already exists\n");
    } else {
        tree[rightIndex] = value;
    }
}

// Display tree (array form)
void display() {
    printf("Tree elements:\n");
    for (int i = 0; i < SIZE; i++) {
        if (tree[i] != -1)
            printf("Index %d: %d\n", i, tree[i]);
    }
}

int main() {
    initTree();

    insertRoot(10);
    insertLeft(0, 5);
    insertRight(0, 15);
    insertLeft(1, 3);
    insertRight(1, 7);

    display();

    return 0;
}
