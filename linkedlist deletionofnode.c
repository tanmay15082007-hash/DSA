
#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr){
    while(ptr != NULL){
        printf("Elements: %d\n", ptr->data);
        ptr = ptr->next;
    }
}
// Case 1: Deleting first element from linked list
struct node* deletionatfirst(struct node* head){
    struct node* p = head;
    head = head->next;
    free(p);
    return head;
}  

// Case 2: deleting the last node from linked list
struct node* deletelast(struct node* head){
    struct node*p = head;
    struct node*prev = NULL;
    while(p->next != NULL){
        prev = p;
        p = p->next;
    }
    prev->next = NULL;
    free(p);
    return head;
}

// Case 3: Deleting the node at an index i 
struct node* deleteatindex(struct node* head, int index){
    struct node* p = head;
    struct node* prev = NULL;
    int i = 0;

    while(i != index){
        prev = p;          // prev stays one behind
        p = p->next;       // p moves to target node
        i++;
    }
    // now p = node to delete, prev = node before it
    prev->next = p->next;  // ✅ bypass the node
    free(p);               // ✅ free the correct node
    return head;
}
int main(){
    struct node*head;
    struct node*first;
    struct node*second;
    struct node*third;

    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = first;
    
    first->data = 21;
    first->next = second;

    second->data = 9;
    second->next = third;

    third->data = 12;
    third->next = NULL; 
    printf("Linked list before deletion:\n");
    linkedlisttraversal(head);

    // head = deletionatfirst(head);
    // head = deletelast(head);
    head = deleteatindex(head,2);
    printf("Linked list after  deletion:\n");
    linkedlisttraversal(head);
    return 0;
}
