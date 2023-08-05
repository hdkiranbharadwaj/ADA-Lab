
#include <stdio.h>
#include <stdlib.h>
struct item
{
    int number;
    int weight;
    int value;
} Head[10];
typedef struct item itm;
int max, n;
int v[10][10];
int Max(int a, int b)
{
    if (a > b)
        return a;
    return b;
}

void getdata()
{
    printf("Enter the number of items and the max capacity of the knapsack: \n");
    scanf("%d", &n);
    scanf("%d", &max);
    for (int i = 1; i <= n; i++)
    {
        printf("Enter the weight and value of the %d item\n", i);
        scanf("%d%d", &((Head + i)->weight), &((Head + i)->value));
    }
}

int memory_function(i, j)
{
    int val;
    if (v[i][j] < 0)
    {
        if (j < Head[i].weight)
        {
            val = memory_function(i - 1, j);
        }
        else
        {
            val = Max(memory_function(i - 1, j), Head[i].value + memory_function(i - 1, j - Head[i].weight));
        }
        v[i][j] = val;
    }
    return v[i][j];
}
void knapsack()
{
    int rc = max, c[n], j = 0;
    for (int i = 0; i < n + 1; i++)
    {
        for (j = 0; j < max + 1; j++)
        {

            v[i][j] = -1;
            if (i == 0 || j == 0)
            {
                v[i][j] = 0;
            }
        }
    }
    memory_function(n, max);

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    printf("The maximum value is %d\n", v[n][max]);
    j = 0;
    for (int i = n; i > 0 && rc > 0 && j != n - 1; i--)
    {
        if (v[i][rc] != v[i - 1][rc])
        {
            c[j++] = i;
            rc = rc - (Head + i)->weight;
        }
    }
    printf("The composition is:\n");
    for (int i = 0; i < j; i++)
    {
        printf("%d\n", c[i]);
    }
}
void main()
{
    getdata();
    knapsack();
}