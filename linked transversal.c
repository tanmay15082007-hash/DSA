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
    third->data = 14;
    third->next = NULL;
    linkedlisttraversal(head);
    return 0;
}
