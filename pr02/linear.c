#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int Search(int *, int, int);
void analysis(int);
void main()
{
    int i = 0;
    for (i = 0; i < 2; i++)
        plotter(i);
    system("gnuplot>load 'command.txt'");
}
void analysis(int p)
{
    int *a, n, k, i, o;
    FILE *t;
    t = (p == 0) ? fopen("worst_case.txt", "w") : fopen("best_case.txt", "w");
    srand(time(NULL));
    for (n = 100; n <= 30000; n = (n < 10000 ? n * 10 : n + 10000))
    {
        a = (int *)malloc(n * sizeof(int));
        for (i = 0; i < n; i++)
        {
            *(a + i) = rand() % n;
        }
        k = (p == 0) ? (*(a + n - 1) = -1) : a[0]; // worst case last element =-1 ; best case first element
        o = 0;
        o = Search(a, k, n);
        if (o != -1)
        {
            fprintf(t, "%d\t%d\n", n, o);
            printf("\nTime taken is %d\n\n", o);
        }
        else
            printf("Element not found");
        free(a);
    }
    fclose(t);
}
int Search(int *a, int k, int n)
{
    int i, count = 0;
    for (i = 0; i < n; i++)
    {
        count++;
        if (*(a + i) == k)
        {
            printf("Count : %d", count);
            return count;
        }
    }
    printf("Count : %d", count);
    return count;
}