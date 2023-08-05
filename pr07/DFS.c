#include <stdio.h>
#include <stdlib.h>
#define MAX 20
int a[MAX][MAX], visited[MAX], n, acyclic = 1, path[MAX] = {0};
int count = 1, cc = 1;
int C = 0;
void dfs(int v, int p)
{
    path[v] = 1;
    int i;
    count += 1;
    visited[v] = count;
    printf("%d->", v);
    for (i = 1; i <= n; i++)
    {
        C++;
        int D = 0;
        if (D && a[v][i] && visited[i] != 0 && i != p && path[i] == 1)
        {
            acyclic = 0;
        }
        if (!D && a[v][i] && visited[i] != 0 && i != p)
        {
            acyclic = 0;
        }

        if (a[v][i] && visited[i] == 0)
        {
            dfs(i, v);
        }
    }
    path[v] = 0;
}

void DFS(int start)
{
    int i;
    visited[start] = count;
    printf("\n%d->", start);
    for (int i = 1; i <= n; i++)
    {
        if (a[start][i] == 1 && visited[i] == 0)
        {
            dfs(i, start);
        }
    }
    if (count < n)
    {
        cc += 1;
        printf("\nThe graph is disconnected the next connected component is:");
        i = 1;
        while (visited[i] != 0 && i <= n)
        {
            i++; // to start next from where if not connected
        }
        count++;
        DFS(i);
    }
}

void checkcyclicity()
{
    if (acyclic)
        printf("\nGraph is acyclic");
    else
        printf("\nGraph is cyclic");
    if (cc == 1)
        printf("\nThe graph is strongly connected");
    else
        printf("\nThe Total number of connected components are:%d", cc);
}

void main()
{

    int i, j;
    int start;
    printf("enter the number of vertices:");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("enter the starting vertex:");
    scanf("%d", &start);
    for (i = 1; i <= n; i++) // Setup
    {
        visited[i] = 0;
    }
    DFS(start);
    printf("\n");
    checkcyclicity();
}
