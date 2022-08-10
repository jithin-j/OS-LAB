#include <stdio.h>
int p[100], ar[100], wt[100], bt[100], tat[100], left[100], tottat, totwt, n, count = 0;
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void sort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(&ar[i], &ar[j]);
                swap(&bt[i], &bt[j]);
                swap(&p[i], &p[j]);
                swap(&left[i], &left[j]);
            }
        }
    }
}