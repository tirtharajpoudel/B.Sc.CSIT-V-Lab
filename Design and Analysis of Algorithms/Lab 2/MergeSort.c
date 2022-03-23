#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void MergeSort(int Arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        MergeSort(Arr, l, mid);
        MergeSort(Arr, mid + 1, h);
        Merge(Arr, l, mid, h);
    }
}

void Merge(int Arr[], int l, int mid, int h)
{
    int i, j, k;
    int m = mid - l + 1;
    int n =  h - mid;

    // create temp arrays
    int A[m], B[n];

    // Copy data to temp arrays A[] and B[]
    for (i = 0; i < m; i++)
        A[i] = Arr[l + i];
    for (j = 0; j < n; j++)
        B[j] = Arr[mid + 1 + j];

    // Merge the temp arrays back into arr[l..h]
    i = 0; // Initial index of first sub-array
    j = 0; // Initial index of second sub-array
    k = l; // Initial index of merged sub-array

    while (i < m && j < n)
    {
        if (A[i] <= B[j])
            Arr[k++] = A[i++];
        else
            Arr[k++] = B[j++];
    }
    
    //Copy the remaining elements of A[] & B[]
    for( ; i<m ; i++)
        Arr[k++]=A[i];
    for ( ; j<n ; j++)
        Arr[k++]=B[j];
}

void main()
{
    int i, n = 10;
    // printf("Enter the size of the list(array): ");
    // scanf("%d", &n);
    int Arr[n];

    srand (time(NULL)); //take current time as seed of rand()
    for(i = 0; i < n; i++)
    {
        Arr[i]= rand() % 1000;
    }
    
    printf("Before sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", Arr[i]);
    }

    MergeSort(Arr, 0, n-1);

    printf("\nAfter sorting: \n");
    for(i = 0; i < n; i++)
    {
        printf("%d  ", Arr[i]);
    }
}