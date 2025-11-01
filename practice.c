#include <stdio.h>
#include <stdlib.h>
// We Explore Singly Linked List
typedef struct Node
{
    int data;
    struct Node* next; // pointer
} Node;

Node* head = NULL;

Node* CreateNode(int data);
void InsertAtBegining(Node** head, int data);
void InsertAtEnd(Node** head, int data);
void InsertAtIndex(Node** head, int data, int index);
void DeleteAtBegining(Node** head);
void DeleteAtEnd(Node** head);
void DeleteAtIndex(Node** head, int index);
int Search(Node** head, int key);
void Display(Node* head);

int main() {
    InsertAtBegining(&head, 10);
    InsertAtBegining(&head, 20);
    InsertAtBegining(&head, 30);
    InsertAtBegining(&head, 40);

    // InsertAtEnd(&head, 100);

    // InsertAtIndex(&head, 400, 1);

    // DeleteAtBegining(&head);

    // DeleteAtEnd(&head);

    // DeleteAtIndex(&head, 1);


    Display(head);

    // int result = Search(&head, 40);
    // if (result != -1)
    // {
    //     printf("Found at Index %d \n", result);
    // }else{
    //     printf("Not Founded\n");
    // }
    
    return 0;
}

void Display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Allocation Failed! ");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void InsertAtBegining(Node** head, int data){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    return;
}

void InsertAtEnd(Node** head, int data){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    newNode->data = data;
    temp->next = newNode;
    return;
}

void InsertAtIndex(Node** head, int data, int index){
    Node* newNode = CreateNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }
    if (index == 0)
    {
        InsertAtBegining(head, data);
        return;
    }
    Node* temp = *head;

    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return;
}

void DeleteAtBegining(Node** head){
    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    return;
}

void DeleteAtEnd(Node** head){
    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    Node* temp = (*head)->next;
    Node* prev = *head;
    while (temp->next != NULL)
    {
        temp = temp->next;
        prev = prev->next;
    }
    prev->next = NULL;
    free(temp);
    return;
}

void DeleteAtIndex(Node** head, int index){
    if ((*head)->next == NULL)
    {
        free(head);
        *head = NULL;
    }
    if (index == 0)
    {
        DeleteAtBegining(head);
        return;
    }
    
    Node* temp = *head;
    Node* q = (*head)->next;
    for (int i = 0; i < index-1; i++)
    {
        temp = temp->next;
        q = q->next;
    }
    temp->next = q->next;
    q->next = NULL;
    free(q);
    return;
}

int Search(Node** head, int key){
    Node* temp = *head;
    int i = 0;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return i;
        }
        temp = temp->next;
        i++;
    }
    return -1;
}
