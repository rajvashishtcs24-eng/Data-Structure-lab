#include <stdio.h>

int n;
int graph[20][20];
int visited[20];

// DFS function
void DFS(int v)
{
    int i;
    visited[v] = 1;

    for (i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    // Initialize visited array
    for (i = 0; i < n; i++)
        visited[i] = 0;

    // Start DFS from vertex 0
    DFS(0);

    // Check if all vertices are visited
    for (i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            printf("Graph is NOT Connected\n");
            return 0;
        }
    }

    printf("Graph is Connected\n");
    return 0;
}
