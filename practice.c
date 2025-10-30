#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} Node;

Node* InsertAtBegining(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
}

Node* InsertAtEnd(Node* head, int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = NULL;
    return head;
}

Node* InsertAtIndex(Node* head, int data, int index){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    Node* temp = head;
    Node* p = head->next;

    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next;
        p  = p->next;
    }
    temp->next = newNode;
    newNode->next = p;
    return head;
    
}

Node* DeleteAtBegining(Node* head){
    if (head->next == NULL)
    {
        printf("Linked List is Empty Nothing to delete.");
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

Node* DeleteAtEnd(Node* head){
    Node* temp = head->next;
    Node* prev = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
        prev = prev->next;
    }
    free(temp);
    prev->next = NULL;
    return head;
}

Node* DeleteAtIndex(Node* head, int index){
    Node* p = head;
    Node* q = head->next;

    for (int i = 0; i < index-1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

void display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main(){
    Node* head = NULL;

    head = InsertAtBegining(head, 10);
    head = InsertAtBegining(head, 20);
    head = InsertAtBegining(head, 30);
    head = InsertAtBegining(head, 40);

    // head = InsertAtEnd(head, 50);
    // head = InsertAtEnd(head, 60);
    // head = InsertAtIndex(head, 100, 3);

    // head = DeleteAtBegining(head);
    // head = DeleteAtEnd(head);
    head = DeleteAtIndex(head, 2);

    display(head);

    return 0;
}