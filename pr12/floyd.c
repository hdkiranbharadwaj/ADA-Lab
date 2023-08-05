#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int count = 0;
int **get_data(int *n)
{
    int i, j;
    // printf("Enter the order of the matrix\n");
    // scanf("%d", n);
    int **a = (int **)malloc(*n * sizeof(int *));
    for (i = 0; i < *n; i++)
        a[i] = (int *)malloc(*n * sizeof(int));
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
void floyd(int **a, int n)
{
    int i, j, k, t;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            t = a[i][k];
            for (j = 0; j < n; j++)
            {
                count++;
                if (a[i][j] > t)
                    a[i][j] = a[i][j] < (t + a[k][j]) ? a[i][j] : (t + a[k][j]);
            }
        }
    }
}
void display(int **a, int n, FILE *fp)
{
    // int i, j;
    // printf("\nThe Minimum Path Matrix is:\n");
    // for (i = 0; i < n; i++)
    // {
    //     for (j = 0; j < n; j++)
    //     {
    //         printf("%d\t", a[i][j]);
    //     }
    //     printf("\n");
    // }
    fprintf(fp, "%d\t%d\n", n, count);
    printf("\nThe count is %d", count);
}
void analysis()
{
    FILE *fp = fopen("floyd.txt", "w");
    int **a;
    for (int n = 2; n < 12; n++)
    {
        count = 0;
        a = get_data(&n);
        floyd(a, n);
        display(a, n, fp);
    }
    fclose(fp);
}
void main()
{
    analysis();
}