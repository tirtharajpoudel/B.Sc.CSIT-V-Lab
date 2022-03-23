#include <stdio.h>

#define nV 4
#define INF 999

void printMatrix(int A[][nV]);

void floydWarshall(int graph[][nV])
{
    int A[nV][nV], i, j, k;

    for (i = 0; i < nV; i++)
    for (j = 0; j < nV; j++)
        A[i][j] = graph[i][j];

    for (k = 0; k < nV; k++)
    {
        for (i = 0; i < nV; i++)
        {
            for (j = 0; j < nV; j++)
            {
                if (A[i][k] + A[k][j] < A[i][j])
                 A[i][j] = A[i][k] + A[k][j];
            }
        }
    }
    printMatrix(A);
}

void printMatrix(int A[][nV])
{
printf("The shortest path matrix:\n");
    for (int i = 0; i < nV; i++)
    {
        for (int j = 0; j < nV; j++)
        {
            if (A[i][j] == INF)
                printf("%4s", "INF");
            else
                printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int graph[nV][nV] = {{0, 6, INF, 11},
                        {2, 0, INF, 4},
                        {INF, 4, 0, INF},
                        {INF, INF, 5, 0}};
    floydWarshall(graph);
}
