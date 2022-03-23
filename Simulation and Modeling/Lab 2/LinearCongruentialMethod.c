// C Program to generate Pseudo-random numbers
// using Linear Congruential Generator.

#include<stdio.h>

void main()
{
    int xi=27;
    int a=17;
    int c=43;
    int m=100;
    int RandNum[m];

    printf("The random numbers are: \n");

    for (int i=0; i<m; i++)
    {
        RandNum[i]= (a*xi+c)%m;
        xi=RandNum[i];
        printf("%d \n",RandNum[i]);
        if (i==0)
            continue;
        if (RandNum[i]==RandNum[0])
        {
            printf("now the pattern repeats..");
            break;
        }
    }
}