#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int size;
    int rear;
    int front;
    int* array;
} Queue;

int isFull(Queue* ptr){
    if (ptr->rear == ptr->size-1)
    {
        return 1;
    }else{
        return 0;
    }
}

int isEmpty(Queue* ptr){
    if (ptr->rear == ptr->front)
    {
        return 1;
    }else{
        return 0;
    }
}

void Enqueue(Queue* ptr, int data){
    if (isFull(ptr))
    {
        printf("Queue is Full .");
        return;
    }
    ptr->rear++;
    ptr->array[ptr->rear] = data;
    return;
}

int Dequeue(Queue* ptr){
    if (isEmpty(ptr))
    {
        printf("Queue is EMpty");
    }
    ptr->front++;
    int x = ptr->array[ptr->front];
    return x;
}

int main()
{
    Queue q;
    q.size = 400;
    q.rear = q.front = 0;
    q.array = (int*) malloc(q.size * sizeof(int));

    // Grapth Implementation
    int node;
    int i = 0;
    int Visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int graph[7][7] = {
        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    printf("%d \n", i);
    Visited[i] = 1;
    Enqueue(&q, i);
    while (!isEmpty(&q))
    {
        node = Dequeue(&q);
        for (int j = 0; j < 7; j++)
        {
            if (graph[node][j] == 1 && Visited[j] == 0)
            {
                printf("%d \n", j);
                Visited[j] = 1;
                Enqueue(&q, j);
            }
        }
    }
    
    return 0;
}