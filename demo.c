#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;
Node* createNode(int data) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data;
    newNode->prev=NULL;
    newNode->next=NULL;
    return newNode;
}
void append(Node** head, int data) {
    Node* newNode=createNode(data);
    Node* last=*head;
    if (*head==NULL){
        *head=newNode;
        return;
    }
    while (last->next != NULL){
        last=last->next;
    }
    last->next=newNode;
    newNode->prev=last;
}
void display(Node* node){
    Node* last;
    printf("Forward transversal:\n");
    while (node != NULL){
        printf("%d ", node->data);
        last=node;
        node=node->next;
    }
    printf("\nBackwar transversal:\n");
    while (node != NULL){
        printf("%d",last->data);
        last=last->prev;
    }
    printf("\n");
}
int main(){
    Node* head=NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    display(head);
    return 0;
}