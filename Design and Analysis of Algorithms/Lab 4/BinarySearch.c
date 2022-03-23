#include<stdio.h>
#include<math.h>

int binarySearch(int a[], int l, int r, int key)
{   int m;
    if(l > r)
        return -1;
    else{
        m = (l + r) / 2;
        if(key == a[m])
            return m;
        else if(key < a[m])
            return binarySearch(a, l, m - 1, key);
        else if(key > a[m])
            return binarySearch(a, m + 1, r, key);
        else
            return -1;
    }
}

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
      //  swap(arr[i], arr[largest]);`
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i=n-1; i>=0; i--)
    {
        //swap(arr[0], arr[i]);
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

int main()
{
    int i, n = 10;
   // printf("Enter the size of the list(array): ");
    //scanf("%d", &n);
    int a[n];
    for(i = 0; i < n; i++){
        int e = rand() % 50;
        a[i] = e;
    }

    heapSort(a, n);

    printf("\nArray: \n");
    for(i = 0; i < n; i++){
        printf("%d  ", a[i]);
    }
    int key;
    repeat:
    printf("\nEnter a number to be searched(key): ");
    scanf("%d", &key);
    int position = binarySearch(a, 0, n-1, key);
    if(position == -1){
        char decide;
        printf("\nKey not found, Try again(y/n).\n");
        scanf("%s", &decide);
        if(decide == 'Y' || decide == 'y')
            goto repeat;
    }
    else{
        printf("\nKey found at the position %d.", position);
    }
    return 0;
}
