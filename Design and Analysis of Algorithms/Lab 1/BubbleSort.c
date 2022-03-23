#include <stdio.h>

int main()
{
    int n, c, d, swap;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int array[n];
    for (c = 0; c < n; c++)
        array[c]=(rand()%n*10);
    for (c = 0 ; c < n - 1; c++)
    {
        for (d = 0 ; d < n - c - 1; d++)
        {
            if (array[d] > array[d+1])
            {
                swap       = array[d];
                array[d]   = array[d+1];
                array[d+1] = swap;
            }
        }
    }
    printf("Sorted list in ascending order:\n");
    for (c = 0; c < n; c++)
        printf("%d\n", array[c]);
    return 0;
}