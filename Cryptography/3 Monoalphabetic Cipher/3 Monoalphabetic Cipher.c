// C program to implement Monoalphabetic Cipher

#include<stdio.h>
#include<conio.h>
#include<string.h>

void main()
{
    char s[30],k[27],c[30];
    int i, index;
    printf("**Monoalphabetic Cipher**\n\n");
    printf("Enter plain text:");
    gets(s);
    printf("\nEnter the key:");
    char absorb;
    for (i=0;i<26;i++)
    {
        printf("\n%c -> ",i+97);
        scanf("%c",&k[i]);
        scanf("%c",&absorb);
    }
    for (i=0;i<strlen(s);i++)
    {
        index=s[i]-97;
        c[i]=k[index];
    }
    printf("\n\nCipher text:");
    for(i=0;i<strlen(s);i++)
    {
        printf("%c",c[i]);
    }
    getch();
}
