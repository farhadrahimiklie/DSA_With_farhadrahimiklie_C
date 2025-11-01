#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
        int data;
        struct Node* prev;
        struct Node* next;
} Node;

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Dynamic Memory Allocation is Failed ! \n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* InsertAtBegining(Node* head, int data){
    Node* newNode = CreateNode(data);
    if (head == NULL)
    {
        head = newNode;
    }else{
        newNode->next = head;
        head->prev = NULL;
        head = newNode;
        return head;
    }
}

Node* InsertAtEnd(Node* head, int data){
    Node* newNode = CreateNode(data);
    if (head == NULL)
    {
        return head = newNode;
    }else{
        Node* temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        newNode->next = NULL;
        return head;
    }
}

Node* InsertAtIndex(Node* head, int data, int index){
    Node* newNode = CreateNode(data);
    if (index == 0)
    {
        return InsertAtBegining(head, data);
    }
    Node* temp = head;
    for (int i = 0; i < index -1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("INdex out of Range");
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
    
}

Node* DeleteAtBegining(Node* head){
    if (head == NULL)
    {
       printf("Nothing to delete");
    }
    Node* temp = head;
    head = temp->next;
    if (head != NULL)
    {
        head->prev = NULL;
    }
    temp->next = NULL;
    free(temp);
}

void DeleteAtEnd(Node* head){
    if (head == NULL)
    {
        printf("List is Empty \n");
        return;
    }
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        printf("NOthing to delete.");
    }
    
    Node* temp = head;
    Node* q = head->next;
    while (q->next != NULL)
    {
        temp = temp->next;
        q = q->next;
    }
    temp->next = NULL;
    q->prev = NULL;
    free(q);
}

void DeleteAtIndex(Node* head, int index){
    if (head == NULL)
    {
        printf("Empty list");
        return;
    }
    if (index == 0)
    {
        DeleteAtBegining(head);
        return;
    }
    
    Node* temp = head;

    for (int i = 0; i < index && temp != NULL; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Index out of range");
        return;
    }

    if (temp->next != NULL){
        temp->next->prev = temp->prev;
    }

    if (temp->prev != NULL){
        temp->prev->next = temp->next;
    }
    temp = NULL;
    free(temp);
}

void display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d <--> ", temp->data);
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

    // head = InsertAtEnd(head, 70);
    // head = InsertAtEnd(head, 80);

    // head = InsertAtIndex(head, 100, 1);

    // DeleteAtBegining();

    // DeleteAtEnd(head);
    // DeleteAtEnd(head);
    // DeleteAtEnd(head);
    // DeleteAtEnd(head);
    // DeleteAtEnd(head);

    display(head);

    DeleteAtIndex(head, 1);

    display(head);

    return 0;
}