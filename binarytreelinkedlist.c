#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

// ── CREATE NODE ───────────────────────────────────
struct Node* createNode(int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data  = data;
    ptr->left  = NULL;
    ptr->right = NULL;
    return ptr;
}

// ── PREORDER (Root → Left → Right) ───────────────
void preorder(struct Node *root){
    if(root == NULL){
        return;
    }
    printf("%d ", root->data);       // visit root
    preorder(root->left);            // visit left
    preorder(root->right);           // visit right
}

// ── INORDER (Left → Root → Right) ────────────────
void inorder(struct Node *root){
    if(root == NULL){
        return;
    }
    inorder(root->left);             // visit left
    printf("%d ", root->data);       // visit root
    inorder(root->right);            // visit right
}

// ── POSTORDER (Left → Right → Root) ──────────────
void postorder(struct Node *root){
    if(root == NULL){
        return;
    }
    postorder(root->left);           // visit left
    postorder(root->right);          // visit right
    printf("%d ", root->data);       // visit root
}

int main(){

    // ── CREATE NODES ──────────────────────────────
    struct Node *root   = createNode(10);
    struct Node *node2  = createNode(20);
    struct Node *node3  = createNode(30);
    struct Node *node4  = createNode(40);
    struct Node *node5  = createNode(50);
    struct Node *node6  = createNode(60);
    struct Node *node7  = createNode(70);

    // ── CONNECT NODES ─────────────────────────────
    root->left   = node2;    // 10 → left  → 20
    root->right  = node3;    // 10 → right → 30
    node2->left  = node4;    // 20 → left  → 40
    node2->right = node5;    // 20 → right → 50
    node3->left  = node6;    // 30 → left  → 60
    node3->right = node7;    // 30 → right → 70

    // ── TREE STRUCTURE ────────────────────────────
    printf("Tree structure:\n");
    printf("          %d\n",        root->data);
    printf("         /  \\\n");
    printf("       %d     %d\n",    node2->data, node3->data);
    printf("      / \\   / \\\n");
    printf("    %d   %d %d   %d\n", node4->data, node5->data,
                                    node6->data, node7->data);

    // ── TRAVERSALS ────────────────────────────────
    printf("\nPreorder  (Root->Left->Right): ");
    preorder(root);
    printf("\n");

    printf("Inorder   (Left->Root->Right): ");
    inorder(root);
    printf("\n");

    printf("Postorder (Left->Right->Root): ");
    postorder(root);
    printf("\n");

    return 0;
}