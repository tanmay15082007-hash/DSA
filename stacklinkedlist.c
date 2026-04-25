#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// ── PUSH ──────────────────────────────────────────
struct Node* push(struct Node *top, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = top;   // new node → old top
    top = ptr;         // top moves to new node
    return top;
}

// ── POP ───────────────────────────────────────────
struct Node* pop(struct Node *top){
    if(top == NULL){
        printf("Stack is empty!\n");
        return NULL;
    }
    struct Node *ptr = top;            // save top
    printf("Popped: %d\n", ptr->data);
    top = top->next;                   // top moves forward
    free(ptr);                         // free old top
    return top;
}

int main(){
    struct Node *top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top = push(top, 40);

    top = pop(top);                    // 40
    top = pop(top);                    // 30
    top = pop(top);                    // 20
    top = pop(top);                    // 10
    top = pop(top);                    // Stack is empty!

    return 0;
}