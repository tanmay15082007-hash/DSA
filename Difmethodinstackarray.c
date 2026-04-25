#include <stdio.h>
#include <stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *ptr){
    if(ptr->top == -1){
        return 1;
    }
    return 0;
}

int isFull(struct stack *ptr){
    if(ptr->top == ptr->size-1){
        return 1;
    }
    return 0;
}

void push(struct stack *ptr, int value){
    if(isFull(ptr)){
        printf("Stack is full!\n");
        return;
    }
    ptr->top++;
    ptr->arr[ptr->top] = value;
}

int pop(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return -1;
    }
    int val = ptr->arr[ptr->top];  // save top value
    ptr->top--;                     // remove top
    return val;                     // return saved value
}


void display(struct stack *ptr){
    if(isEmpty(ptr)){
        printf("Stack is empty!\n");
        return;
    }
    printf("Stack (top to bottom): ");
    for(int i = ptr->top; i >= 0; i--){
        printf("%d ", ptr->arr[i]);
    }
    printf("\n");
}

int main(){
    // Create and initialize stack
    struct stack *s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 5;
    s->top  = -1;
    s->arr  = (int*)malloc(s->size * sizeof(int));

    // Test isEmpty on empty stack
    printf("Is empty: %d\n", isEmpty(s));   // 1

    // Push elements
    push(s, 10);
    push(s, 20);
    push(s, 30);
    push(s, 40);
    push(s, 50);
    display(s);                              // 50 40 30 20 10

    // Try push on full stack
    push(s, 60);                             // Stack is full!
    // Pop elements
    printf("Popped: %d\n", pop(s));         // 50
    printf("Popped: %d\n", pop(s));         // 40
    display(s);                              // 30 20 10

    // Pop all remaining
    pop(s);                                  // 30
    pop(s);                                  // 20
    pop(s);                                  // 10

    // Try pop on empty stack
    pop(s);                                  // Stack is empty!

    // Free memory
    free(s->arr);
    free(s);
    return 0;
}