#include<stdio.h>
#include<math.h>

void QuickSort(int A[], int l, int h)
{
    if(l<h)
    {
        int j = Partition(A,l,h);
        QuickSort(A,l,j);
        QuickSort(A,j+1,h);

    }
}

int Partition(int A[], int l, int h)
{
    int pivot=A[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        do
        {
            i++;
        } while (A[i]<=pivot);
        do
        {
            j--;
        } while (A[j]>pivot);
        if(i<j)
        {
            int temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }  
    }
    int temp = A[l];
    A[l]=A[j];
    A[j]=temp;

    return j;
}

void main()
{
    int i, n=10;
    // printf("Enter the size of the list(array): ");
    // scanf("%d", &n);
    int A[n];

    srand (time(NULL)); //take current time as seed of rand()
    for (i=0;i<n;i++)
    {
        A[i] = rand() % 1000;
    }

    printf("Before sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }

    int l = 0;
    int h = n;
    QuickSort(A, l, h);

    printf("\nAfter sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
}