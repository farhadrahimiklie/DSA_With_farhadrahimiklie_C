#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* head = NULL;

Node* CreateNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = NULL;
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
    newNode->next = *head;
    (*head)->prev = newNode;
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
    temp->next = newNode;
    newNode->prev = temp;
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
    for (int i = 0; i < index-1 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Index is Out of Range");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void DeleteAtBegining(Node** head){
    if (*head == NULL)
    {
        printf("Linked List is empty, Nothing to delete.");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    *head = (*head)->next;
    if ((*head)->prev != NULL)
    {
        (*head)->prev = NULL;
    }
    temp->next = NULL;
    free(temp);
    return;
}

void DeleteAtEnd(Node** head){
    if (*head == NULL)
    {
        printf("Linked List is empty, Nothing to delete.");
        return;
    }
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    Node* temp = *head;
    Node* q = (*head)->next;
    while (q->next != NULL)
    {
        q = q->next;
        temp = temp->next;
    }
    temp->next = NULL;
    q->prev = NULL;
    free(q);
    return;
}

void DeleteAtIndex(Node** head, int index){
    if ((*head)->next == NULL)
    {
        free(*head);
        *head = NULL;
        return;
    }
    if (index == 0)
    {
        DeleteAtBegining(head);
        return;
    }
    Node* temp = *head;
    for (int i = 0; i < index && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Out of Range");
        return;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    free(temp);
}

int Search(Node* head, int key){
    Node* temp = head;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

void display(Node* head){
    Node* temp = head;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

int main() {
    InsertAtBegining(&head, 10);
    InsertAtBegining(&head, 20);
    InsertAtBegining(&head, 30);
    InsertAtBegining(&head, 40);

    // InsertAtEnd(&head, 600);
    // InsertAtIndex(&head, 600, 1);

    // DeleteAtBegining(&head);
    // DeleteAtEnd(&head);
    DeleteAtIndex(&head, 1);

    display(head);

    // int result = Search(head, 10);
    // if (result != -1)
    // {
    //     printf("Founded at Index : %d \n", result);
    // }else{
    //     printf("Not Found \n");
    // }
    
    return 0;
}
