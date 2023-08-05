#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int bubble_sort(int *, int, int);
void analyser(int);
int main()
{
    int i;
    for (i = 0; i < 2; i++)
        analyser(i);
    system("gnuplot>load 'command.txt' ");
}
void analyser(int p)
{
    int key, size, *search_array, index, o;

    srand(time(NULL));
    FILE *fp2;
    fp2 = (p == 0) ? fopen("Bubble_best.txt", "w") : fopen("Bubble_worst.txt", "w");
    for (size = 100; size <= 30000; size = (size < 10000 ? size * 10 : size + 10000))
    {
        search_array = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
        {
            *(search_array + i) = i + 100;
        }
        o = bubble_sort(search_array, size, p);
        printf("%d\n", o);
        fprintf(fp2, "%d\t%d\n", size, o);
        free(search_array);
    }
    fclose(fp2);
}

int bubble_sort(int *a, int size, int p)
{
    int count = 0, i, j, temp, flag = 0;
    for (i = 0; i < size; i++)
    {
        flag = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            count++;
            if (*(a + j) > *(a + j + 1))
            {
                flag = 1;
                temp = *(a + j);
                *(a + j) = *(a + j + 1);
                *(a + j + 1) = temp;
            }
        }
        if (flag == 0 && p == 0)
        {
            return count;
        }
    }
    printf("SIZE %d\n", size);
    return count;
}
