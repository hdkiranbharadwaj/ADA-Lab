#include <stdio.h>
#include <stdlib.h>
int String_Matching(char *, char *, int, int);
void analysis(int);
int main()
{
    int i;
    for (i = 0; i < 2; i++)
        analysis(i);
    system("gnuplot>load 'command.txt'");
}

void analysis(int f)
{

    FILE *fp1 = f == 0 ? fopen("best.txt", "w") : fopen("worst.txt", "w");
    int count = 0, i;
    char *T = (char *)malloc(sizeof(char) * 100);
    for (int i = 0; i < 100; i++)
        *(T + i) = 'a';
    for (int m = 10; m <= 100; m = m + 10)
    {
        count = 0;
        char *P = (char *)malloc(sizeof(char) * m);
        for (i = 0; i < m; i++)
            *(P + i) = 'a';//best
        if (f == 1)
            *(P + i - 1) = 'b';//worst

        count = String_Matching(T, P, 100, m);
        fprintf(fp1, "%d\t\t%d\n", m, count);
        free(P);
    }
    fclose(fp1);
}

int String_Matching(char *T, char *P, int n, int m)
{
    int j, count = 0;
    for (int i = 0; i <= n - m; i++)
    {
        j = 0;
        while (j < m && *(P + j) == *(T + i + j))
        {
            count++;
            j++;
        }
        if (j == m)
            return count;
    }
    return count;
}