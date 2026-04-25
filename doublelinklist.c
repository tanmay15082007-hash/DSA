#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
    struct Node *prev;
};

// ── CREATE NODE ───────────────────────────────────
struct Node* createNode(int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}

// ── DISPLAY FORWARD ───────────────────────────────
void displayForward(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *ptr = head;
    printf("Forward:  ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// ── DISPLAY BACKWARD ──────────────────────────────
void displayBackward(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    // go to last node first
    struct Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    printf("Backward: ");
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->prev;    // move backward using prev
    }
    printf("\n");
}

// ── INSERT AT BEGINNING ───────────────────────────
struct Node* insertAtFirst(struct Node *head, int data){
    struct Node *ptr = createNode(data);
    if(head == NULL){
        return ptr;          // first node
    }
    ptr->next  = head;       // new node points to old head
    head->prev = ptr;        // old head points back to new node
    head = ptr;              // head moves to new node
    return head;
}

// ── INSERT AT END ─────────────────────────────────
struct Node* insertAtEnd(struct Node *head, int data){
    struct Node *ptr = createNode(data);
    if(head == NULL){
        return ptr;          // first node
    }
    struct Node *p = head;
    while(p->next != NULL){
        p = p->next;         // go to last node
    }
    p->next   = ptr;         // last node points to new node
    ptr->prev = p;           // new node points back to last node
    return head;
}

// ── INSERT AT INDEX ───────────────────────────────
struct Node* insertAtIndex(struct Node *head, int data, int index){
    struct Node *ptr = createNode(data);
    if(index == 0){
        return insertAtFirst(head, data);
    }
    struct Node *p = head;
    int i = 0;
    while(i != index-1 && p != NULL){
        p = p->next;
        i++;
    }
    if(p == NULL){
        printf("Index out of bounds!\n");
        free(ptr);
        return head;
    }
    ptr->next = p->next;     // new node points to next
    ptr->prev = p;           // new node points back to p
    if(p->next != NULL){
        p->next->prev = ptr; // next node points back to new node
    }
    p->next = ptr;           // p points to new node
    return head;
}

// ── DELETE AT BEGINNING ───────────────────────────
struct Node* deleteAtFirst(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }
    struct Node *ptr = head;
    head = head->next;       // move head forward
    if(head != NULL){
        head->prev = NULL;   // new head prev = NULL
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// ── DELETE AT END ─────────────────────────────────
struct Node* deleteAtEnd(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }
    struct Node *ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;     // go to last node
    }
    if(ptr->prev != NULL){
        ptr->prev->next = NULL;  // second last next = NULL
    }
    else{
        head = NULL;         // only one node
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// ── DELETE AT INDEX ───────────────────────────────
struct Node* deleteAtIndex(struct Node *head, int index){
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }
    if(index == 0){
        return deleteAtFirst(head);
    }
    struct Node *ptr = head;
    int i = 0;
    while(i != index && ptr != NULL){
        ptr = ptr->next;
        i++;
    }
    if(ptr == NULL){
        printf("Index out of bounds!\n");
        return head;
    }
    if(ptr->next != NULL){
        ptr->next->prev = ptr->prev;  // next node skips ptr
    }
    if(ptr->prev != NULL){
        ptr->prev->next = ptr->next;  // prev node skips ptr
    }
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// ── SEARCH ────────────────────────────────────────
void search(struct Node *head, int key){
    struct Node *ptr = head;
    int index = 0;
    while(ptr != NULL){
        if(ptr->data == key){
            printf("Found %d at index %d\n", key, index);
            return;
        }
        ptr = ptr->next;
        index++;
    }
    printf("%d not found!\n", key);
}

int main(){
    struct Node *head = NULL;

    // insert at end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    displayForward(head);           // 10 20 30 40
    displayBackward(head);          // 40 30 20 10

    // insert at beginning
    head = insertAtFirst(head, 5);
    displayForward(head);           // 5 10 20 30 40

    // insert at index
    head = insertAtIndex(head, 15, 2);
    displayForward(head);           // 5 10 15 20 30 40

    // search
    search(head, 15);               // Found 15 at index 2
    search(head, 99);               // 99 not found!

    // delete at beginning
    head = deleteAtFirst(head);
    displayForward(head);           // 10 15 20 30 40

    // delete at end
    head = deleteAtEnd(head);
    displayForward(head);           // 10 15 20 30

    // delete at index
    head = deleteAtIndex(head, 1);
    displayForward(head);           // 10 20 30

    return 0;
}