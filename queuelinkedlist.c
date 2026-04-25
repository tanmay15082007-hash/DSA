#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

// ── ENQUEUE ───────────────────────────────────────
void enqueue(struct Queue *q, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;

    if(q->front == NULL && q->rear == NULL){
        q->front = ptr;        // first node
        q->rear  = ptr;
        return;
    }
    q->rear->next = ptr;       // last node → new node
    q->rear       = ptr;       // rear moves to new node
}

// ── DEQUEUE ───────────────────────────────────────
int dequeue(struct Queue *q){
    if(q->front == NULL && q->rear == NULL){
        printf("Queue is empty!\n");
        return -1;
    }
    struct Node *ptr = q->front;       // save front
    int val          = ptr->data;      // save data

    if(q->front == q->rear){           // only one node
        q->front = NULL;
        q->rear  = NULL;
    }
    else{
        q->front = q->front->next;     // front moves forward
    }
    free(ptr);
    return val;
}

int main(){
    struct Queue q;
    q.front = NULL;
    q.rear  = NULL;

    enqueue(&q, 10);
    enqueue(&q, 20);
    enqueue(&q, 30);
    enqueue(&q, 40);

    printf("Dequeued: %d\n", dequeue(&q));   // 10
    printf("Dequeued: %d\n", dequeue(&q));   // 20
    printf("Dequeued: %d\n", dequeue(&q));   // 30
    printf("Dequeued: %d\n", dequeue(&q));   // 40
    dequeue(&q);                             // Queue is empty!

    return 0;
}