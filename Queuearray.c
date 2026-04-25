#include <stdio.h>
#include <stdlib.h>
struct queue{
    int size;
    int rear;
    int front;
    int *arr;
};

int isEmpty(struct queue *ptr){
    if(ptr->front == -1 && ptr->rear == -1){
        return 1;
    }
    return 0;
}

int isFull(struct queue *ptr){
    if(ptr->rear==ptr->size-1){
        return 1;
    }
    return 0;
}

void enqueue(struct queue *ptr, int value){
    if(isFull(ptr)){
        printf("Queue full\n");
        return;
    }
    if(isEmpty(ptr)){
        ptr->front = 0;   // ✅ set front on first insert
        ptr->rear  = 0;
    }
    else{
        ptr->rear++;
    }
    ptr->arr[ptr->rear] = value;
}

int dequeue(struct queue *ptr){             // ✅ returns int, no value param
    if(isEmpty(ptr)){                       // ✅ pass ptr
        printf("Queue empty\n");
        return -1;                          // ✅ valid return for int function
    }
    int val = ptr->arr[ptr->front];         // ✅ save front value
    if(ptr->front == ptr->rear){
        ptr->front = -1;
        ptr->rear  = -1;
    }
    else{
        ptr->front++;                       // ✅ front++ not front--
    }
    return val;
}
int main(){
     // Create and initialize queue
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->size  = 5;
    q->front = -1;
    q->rear  = -1;
    q->arr   = (int*)malloc(q->size * sizeof(int));

    // Test isEmpty on empty queue
    printf("Is empty: %d\n", isEmpty(q));   // 1

    // Enqueue elements
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    enqueue(q, 40);
    enqueue(q, 50);
    display(q);                              // 10 20 30 40 50

    // Try enqueue on full queue
    enqueue(q, 60);                          // Queue is full!

    // Dequeue elements
    printf("Dequeued: %d\n", dequeue(q));   // 10
    printf("Dequeued: %d\n", dequeue(q));   // 20
    display(q);                              // 30 40 50

    // Dequeue all remaining
    dequeue(q);                              // 30
    dequeue(q);                              // 40
    dequeue(q);                              // 50

    // Try dequeue on empty queue
    dequeue(q);                              // Queue is empty!

    // Free memory
    free(q->arr);
    free(q);
    return 0;
}