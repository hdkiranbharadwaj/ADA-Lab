#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count = 0;
bool **get_data(int *n)
{
    int i, j;
    // printf("Enter the order of the matrix\n");
    // scanf("%d", n);
    bool **a = (bool **)malloc(*n * sizeof(bool *));
    for (i = 0; i < *n; i++)
        a[i] = (bool *)malloc(*n * sizeof(bool));
    // printf("Enter the elements of the matrix\n");

    for (i = 0; i < *n; i++)
    {

        for (j = 0; j < *n; j++)
        {
            a[i][j] = 1;
            if (i == j)
                a[i][j] = 0;
        }
    }
    return a;
}
void warshall(bool **a, int n)
{
    int i, j, k;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            if (a[i][k])
            {
                for (j = 0; j < n; j++)
                {
                    count++;
                    if (a[k][j])
                    {
                        a[i][j] = 1;
                    }
                    // a[i][j] = a[i][j] || (a[i][k] && a[k][j]);
                }
            }
        }
    }
}
void display(bool **a, int n)
{
    // int i, j;
    // printf("\nThe Transitive Clousure Matrix is:\n");
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         printf("%d", a[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("\nThe count is %d", count);
}
void analysis()
{
    bool **a;
    for (int n = 2; n < 12; n++)
    {
        count = 0;
        a = get_data(&n);
        warshall(a, n);
        display(a, n);
    }
}
void main()
{
    analysis();
}