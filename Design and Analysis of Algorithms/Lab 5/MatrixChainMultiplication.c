// C[i,j] = min{ C[i, k] + C[k + 1, j] + d[i-1] * d[k] * d[j]
#include<stdio.h>

void print_optimal_parens(int n, int K[][n], int i, int j)
{
    if(i == j){
        printf("A%d", i);
    }
    else{
        printf("(");
        print_optimal_parens(n, K, i, K[i][j]);
        print_optimal_parens(n, K, K[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int numOfMatrices;
    printf("Enter no. of matrices for matrix chain multiplication: ");
    scanf("%d", &numOfMatrices);
    int d[numOfMatrices + 1];
    printf("\nEnter the dimensions for these matrices: \n");
    for(int i = 0; i <= numOfMatrices; i++){
        scanf("%d", &d[i]);
    }
    int C[numOfMatrices + 1][numOfMatrices + 1];
    int K[numOfMatrices + 1][numOfMatrices + 1];
    int inc = 0, i = 1, j = 1;
    while(inc < numOfMatrices){
        i = 1;
        j = i + inc;
        while(j <= numOfMatrices){
            if(i == j)
                C[i][j] = 0;
            else{
                int newC[j];
                for(int k = i; k < j; k++){
                    newC[k]= C[i][k] + C[k + 1][j] + (d[i - 1] * d[k] * d[j]);
                   // printf("\nnewC[%d]: %d\n", k, newC[k]);
                }
                C[i][j] = newC[i];
                for(int k = i + 1; k < j; k++){
                    if(C[i][j] > newC[k])
                        C[i][j] = newC[k];
                }
                printf("\nC[i][j]: %d\n", C[i][j]);
                for(int k = i; k < j; k++){
                    if(C[i][j] == newC[k])
                        K[i][j] = k;
                }
                printf("\nK[i][j]: %d\n", K[i][j]);
            }
            i++;
            j = i + inc;
        }
        inc++;
    }
    printf("\nOptimal parenthesization is: \n");
    print_optimal_parens(numOfMatrices + 1, K, 1, 6);
    return 0;
}
