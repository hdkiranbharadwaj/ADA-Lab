#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int selection_sort(int *, int);
void analyser();
int main()
{
    analyser();
    system("gnuplot>load 'command.txt'");
}

void analyser()
{
    int key, size, *search_array, index, o;
   
    srand(time(NULL));
    FILE *fp2;

    fp2 = fopen("Selection.txt", "w");

    for (size = 100; size <= 30000; size = (size < 10000 ? size * 10 : size + 10000))
    {
        search_array = (int *)malloc(size * sizeof(int));
        for (int i = 0; i < size; i++)
        {
            *(search_array + i) = rand() % size;
        }
        o = selection_sort(search_array, size);
        printf("%d\n", o);
        fprintf(fp2, "%d\t%d\n", size, o);
        free(search_array);
    }
    /*int sa[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    selection_sort(sa, 10);
    for (int i = 0; i < 10; i++)
    {
        printf("%d\t", sa[i]);
    }*/
    fclose(fp2);
}
int selection_sort(int *a, int size)
{
    int count = 0, i, j, temp, min;
    for (i = 0; i < size - 1; i++)
    {
        min = i;
        for (j = i + 1; j < size; j++)
        {
            count++;
            if (*(a + j) < *(a + min))
            {
                min = j;
            }
        }
        temp = *(a + i);
        *(a + i) = *(a + min);
        *(a + min) = temp;
    }
    return count;
}
