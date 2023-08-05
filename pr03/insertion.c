#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertion(int a[], int n, int *cnt)
{
    for (int i = 1; i < n; i++)
    {
        int v = a[i];
        int j = i - 1;
        while (j >= 0)
        {
            *cnt = *cnt + 1;
            if (a[j] <= v)
            {
                break;
            }
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = v;
    }
}

void analysis(int ch)
{
    FILE *f;
    switch (ch)
    {
    case 1:
        f = fopen("best.txt", "w");
        break;
    case 2:
        f = fopen("worst.txt", "w");
        break;
    case 3:
        f = fopen("avg.txt", "w");
        break;
    }
    for (int i = 100; i <= 30000; i = (i < 10000) ? i * 10 : i + 10000)
    {
        srand(time(NULL));

        int cnt = 0;
        int *a;
        a = (int *)malloc(sizeof(int) * i);
        for (int j = 0; j < i; j++)
        {
            switch (ch)
            {
            case 1:
                a[j] = i + j; // ascending order
                break;
            case 2:
                a[j] = i - j + 10; // reverse order
                break;
            case 3:
                a[j] = rand() % 100;
                break;
            }
        }
        insertion(a, i, &cnt);
        fprintf(f, "%d\t%d\n", i, cnt);
    }
    fclose(f);
}
void main()
{
    int ch;
    for (ch = 1; ch < 4; ch++)
    {
        analysis(ch);
    }
    system("gnuplot>load 'command1.txt'");
    system("gnuplot>load 'command2.txt'");
}