#include<stdio.h>

/*void display(int a[], int n){
	for(int s = 0; s < n; s++){
		printf("%d\t", a[s]);
	}
	printf("\n");
}*/

void selectionSort(int x[], int n)
{
    int i, j, indx, large;
    for(i = n - 1; i > 0; i--){
        large = x[0];
        indx = 0;
        for(j = 1; j <= i; j++){
            if(x[j] > large){
                large = x[j];
                indx = j;
            }
        }
        x[indx] = x[i];
        x[i] = large;
    }
}

int main(){
	int n = 100000;
	//printf("Enter the size of array: ");
	//scanf("%d", &n);

	int a[n];
	for(int i = 0; i < n; i++){
        int e = rand() % 2000;
        a[i] = e;
    }
	//printf("Before Sorting: \n");
	//display(a, n);
	selectionSort(a, n);
	//printf("After Sorting: \n");
	//display(a, n);
	return 0;
}
