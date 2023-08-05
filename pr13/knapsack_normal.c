
#include <stdio.h>
#include <stdlib.h>
struct item
{
    int number;
    int weight;
    int value;
};
typedef struct item itm;
int max, n;

void getdata(itm *Head)
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
void knapsack(itm *Head)
{
    int rc = max, j = 0, c[n];
    int v[n + 1][max + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            if (i == 0 || j == 0)
                v[i][j] = 0;
            else
            {
                if (j < (Head + i)->weight)
                    v[i][j] = v[i - 1][j];
                else
                    v[i][j] = v[i - 1][j] > ((Head + i)->value + v[i - 1][j - (Head + i)->weight]) ? v[i - 1][j] : ((Head + i)->value + v[i - 1][j - (Head + i)->weight]);
            }
        }
    }
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < max + 1; j++)
        {
            printf("%d\t", v[i][j]);
        }
        printf("\n");
    }
    printf("The maximum value is %d\n", v[n][max]);
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
    itm Head[10];
    getdata(Head);
    knapsack(Head);
}