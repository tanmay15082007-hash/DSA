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
struct node* insertatfirst(struct node* head, int data){
    struct node*ptr = (struct node*)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node* insertatindex(struct node * head,int data, int index){
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    struct node*p = head;
    int i = 0;
    while(i!=index-1){
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    ptr->data = data;
    return head;
}
struct node* insertatend(struct node* head,int data){
    struct node * ptr = (struct node*)malloc(sizeof(struct node));
    struct node * p = head;
    while(p->next != NULL){
        p = p->next;
    }
    p->next = ptr;
    ptr->data = data;
    ptr->next = NULL;
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
    // head = insertatfirst(head,90);
    // linkedlisttraversal(head);
    // head = insertatindex(head,100,2);
    // linkedlisttraversal(head);
    head = insertatend(head,90);
    linkedlisttraversal(head);
    return 0;
}