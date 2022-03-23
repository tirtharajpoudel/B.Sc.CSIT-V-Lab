#include<stdio.h>
#include<math.h>

void randomizedQuickSort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = rand_part(a, p, r);
        randomizedQuickSort(a, p, q - 1);
        randomizedQuickSort(a, q + 1, r);
    }

}
int rand_part(int a[], int p, int r)
{
    int i = (rand() % (r - p + 1)) + p;
    int temp = a[r];
    a[r] = a[i];
    a[i] = temp;
    return part(a, p, r);
}

int part(int a[], int p, int r)
{
    int x = a[r];
    int i = p - 1;
    for(int j = p ; j <= r - 1; j++)
    {
        if(a[j] <= x)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i+1;
}

int main()
{
    int i, n = 100;
   // printf("Enter the size of the list(array): ");
    //scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++)
    {
        int e = rand() % 1000;
        a[i] = e;
    }
    printf("Before sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    int p = 0;
    int r = n - 1;
    randomizedQuickSort(a, p, r);
    printf("\nAfter sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", a[i]);
    }
    return 0;
}
