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

void freelist(struct node *ptr){
    while(ptr != NULL){
        struct node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
}
struct node* insertatfirst(struct node* head, int data){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

struct node* insertatindex(struct node* head,int data,int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node*p = head;
    int i = 0;
    while(i!=index-1 && p != NULL){
        p = p->next;
        i++;
    }
    if(p == NULL){
        printf("Index out of bounds\n");
        free(ptr);
        return head;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main(){
    struct node*head;
    struct node*first;
    struct node*second;

    head = (struct node*)malloc(sizeof(struct node));
    first = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));

    head->data = 7;
    head->next = first;
    
    first->data = 21;
    first->next = second;
    second->data = 9;
    second->next = NULL;
    linkedlisttraversal(head);
    // head = insertatfirst(head,90);   // point at previous head and now as function return ptr and we equate it with new head
    head = insertatindex(head,90,2);
    linkedlisttraversal(head);
    return 0;
}