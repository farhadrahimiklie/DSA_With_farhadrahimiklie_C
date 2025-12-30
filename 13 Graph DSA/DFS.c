#include <stdio.h>
#include <stdlib.h>

// Grapth Implementation
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

void DFS(int i){
    int j;
    printf("%d \n", i);
    Visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (graph[i][j] == 1 && !Visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{
    // Call the dfs function to implement the grapth of Depth first search
    DFS(1);
    return 0;
}