#include <stdio.h>

int n;
int graph[20][20];
int visited[20];
int queue[20];
int front = -1, rear = -1;

// Insert into queue
void enqueue(int v)
{
    if (rear == n - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = v;
}

// Remove from queue
int dequeue()
{
    return queue[front++];
}

// BFS function
void BFS(int start)
{
    int i, v;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        v = dequeue();
        printf("%d ", v);

        for (i = 0; i < n; i++)
        {
            if (graph[v][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

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

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    BFS(start);

    return 0;
}
