#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;
};

// ── DISPLAY ───────────────────────────────────────
void display(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *ptr = head;
    printf("Circular List: ");
    do{
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }while(ptr != head);
    printf("→ (back to %d)\n", head->data);
}

// ── INSERT AT BEGINNING ───────────────────────────
struct Node* insertAtFirst(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = ptr;           // points to itself

    if(head == NULL){
        return ptr;
    }
    struct Node *last = head;
    while(last->next != head){
        last = last->next;
    }
    ptr->next  = head;         // new node → old head
    last->next = ptr;          // last node → new node
    head = ptr;                // head = new node
    return head;
}

// ── INSERT AT END ─────────────────────────────────
struct Node* insertAtEnd(struct Node *head, int data){
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = ptr;           // points to itself

    if(head == NULL){
        return ptr;
    }
    struct Node *last = head;
    while(last->next != head){
        last = last->next;
    }
    last->next = ptr;          // last node → new node
    ptr->next  = head;         // new node → head
    return head;
}

// ── INSERT AT INDEX ───────────────────────────────
struct Node* insertAtIndex(struct Node *head, int data, int index){
    if(index == 0){
        return insertAtFirst(head, data);
    }
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = ptr;

    struct Node *p = head;
    int i = 0;
    while(i != index-1){
        p = p->next;
        if(p == head){
            printf("Index out of bounds!\n");
            free(ptr);
            return head;
        }
        i++;
    }
    ptr->next = p->next;       // new node → next node
    p->next   = ptr;           // p → new node
    return head;
}

// ── DELETE AT BEGINNING ───────────────────────────
struct Node* deleteAtFirst(struct Node *head){
    if(head == NULL){
        printf("List is empty!\n");
        return NULL;
    }
    if(head->next == head){    // only one node
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *last = head;
    while(last->next != head){
        last = last->next;
    }
    struct Node *ptr = head;
    last->next = head->next;   // last → second node
    head = head->next;         // head moves forward
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
    if(head->next == head){    // only one node
        printf("Deleted: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *ptr  = head;
    struct Node *prev = NULL;
    while(ptr->next != head){
        prev = ptr;
        ptr  = ptr->next;
    }
    prev->next = head;         // second last → head
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
    struct Node *ptr  = head;
    struct Node *prev = NULL;
    int i = 0;
    while(i != index){
        prev = ptr;
        ptr  = ptr->next;
        if(ptr == head){
            printf("Index out of bounds!\n");
            return head;
        }
        i++;
    }
    prev->next = ptr->next;    // skip ptr
    printf("Deleted: %d\n", ptr->data);
    free(ptr);
    return head;
}

// ── SEARCH ────────────────────────────────────────
void search(struct Node *head, int key){
    if(head == NULL){
        printf("List is empty!\n");
        return;
    }
    struct Node *ptr = head;
    int index = 0;
    do{
        if(ptr->data == key){
            printf("Found %d at index %d\n", key, index);
            return;
        }
        ptr = ptr->next;
        index++;
    }while(ptr != head);
    printf("%d not found!\n", key);
}

int main(){
    struct Node *head = NULL;

    // insert at end
    head = insertAtEnd(head, 10);
    head = insertAtEnd(head, 20);
    head = insertAtEnd(head, 30);
    head = insertAtEnd(head, 40);
    display(head);               // 10 20 30 40

    // insert at beginning
    head = insertAtFirst(head, 5);
    display(head);               // 5 10 20 30 40

    // insert at index
    head = insertAtIndex(head, 15, 2);
    display(head);               // 5 10 15 20 30 40

    // search
    search(head, 15);            // Found at index 2
    search(head, 99);            // not found

    // delete at beginning
    head = deleteAtFirst(head);
    display(head);               // 10 15 20 30 40

    // delete at end
    head = deleteAtEnd(head);
    display(head);               // 10 15 20 30

    // delete at index
    head = deleteAtIndex(head, 1);
    display(head);               // 10 20 30

    return 0;
}