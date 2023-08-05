#include <stdio.h>
#include <stdlib.h>
#define x 10
#define y 100
float euclid(int m, int n)
{
    float count = 0;
    while (n)
    {
        count++;
        int temp = m % n;
        m = n;
        n = temp;
    }

    printf("\n%d", m);
    // m is ans
    return count;
}
float consec(int m, int n)
{
    float count = 0;
    int min = m;
    if (n < min)
        min = n;
    while (1)
    {
        count++;
        if (m % min == 0)
        {
            count++;
            if (n % min == 0)
                break;
            min--; // VVP
        }
        else
            min--;
    }
    // consec min is ans
    printf("\n%d", min);
    return count;
}
float modified(int m, int n)
{
    int temp;
    float count = 0;
    while (n > 0)
    {
        if (n > m)
        {
            temp = m;
            m = n;
            n = temp;
        }
        m = m - n;
        count++;
    }
    // modified m is ans
    printf("\n%d", m);
    return count;
}
void main()
{
    float p = euclid(99, 33);
    p = consec(99, 33);
    p = modified(99, 33);
}