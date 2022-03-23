#include<stdio.h>
#include<math.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp =*a;
    *a=*b;
    *b=temp;
}

void HeapSort(int A[], int n)
{
    BuildHeap(A,n);
    for (int i=n; i>=1; i--)
    {
        swap(&A[0],&A[n]);
        n=n-1;
        Heapify(A,0,n);
    }
}

void BuildHeap(int A[], int n)
{
    for(int i=n/2; i>=0; i--)
    {
        Heapify(A,i,n);
    }
}

void Heapify(int A[], int i, int n)
{
    int l= 2*i+1; // left child of i
    int r= 2*i+2; // right child of i
    int largest = i;
    if (l<=n && A[l]>A[largest])
        largest=l;
    if (r<=n && A[r]>A[largest])
        largest=r;
    if (largest!=i)
    {
        swap(&A[i],&A[largest]);
        Heapify(A,largest,n);
    }
}

void main()
{
    int i, n = 100;
    //printf("Enter the size of the list(array): ");
    //scanf("%d", &n);
    int A[n];
    srand (time(NULL)); //take current time as seed of rand()
    for(i = 0; i < n; i++)
    {
      A[i] = rand() % 1000;
    }

    printf("Before sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }

    HeapSort(A,n-1);

    printf("\nAfter sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    // getch();
}