#include<stdio.h>
#include<math.h>
 
float encrypt[2][1], decrypt[2][1], a[2][2], b[2][2], mes[2][1], c[2][2];
 
void encryption()
{
	int i, j, k;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 2; k++)
				encrypt[i][j] = encrypt[i][j] + a[i][k] * mes[k][j];
	printf("\nEncrypted string is: ");
	for(i = 0; i < 2; i++)
		printf("%c", (char)(fmod(encrypt[i][0], 26) + 97));
}
 
void decryption()
{
	int i, j, k;
	inverse();
	for(i = 0; i < 2; i++)
		for(j = 0; j < 1; j++)
			for(k = 0; k < 2; k++)
				decrypt[i][j] = decrypt[i][j] + b[i][k] * encrypt[k][j];
	printf("\nDecrypted string is: ");
	for(i = 0; i < 2; i++)
		printf("%c", (char)(fmod(decrypt[i][0], 26) + 97));	
	printf("\n");
}
 
void getKeyMessage()
{
	int i, j;
	char msg[2];
	printf("Enter 2x2 matrix for key (Inversible):\n");
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
		{
			scanf("%f", &a[i][j]);
			c[i][j] = a[i][j];
		}
	printf("\nEnter a 2 letter string: ");
	scanf("%s", msg);
	for(i = 0; i < 2; i++)
		mes[i][0] = msg[i] - 97;
}
 
void inverse() {
	int i, j, k;
	float p, q;
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
		{
			if(i == j)
				b[i][j]=1;
			else
				b[i][j]=0;
		}
	for(k = 0; k < 2; k++)
	{
		for(i = 0; i < 2; i++)
		{
			p = c[i][k];
			q = c[k][k];	
			for(j = 0; j < 2; j++)
			{
				if(i != k)
				{
					c[i][j] = c[i][j]*q - p*c[k][j];
					b[i][j] = b[i][j]*q - p*b[k][j];
				}
			}
		}
	}
	
	for(i = 0; i < 2; i++)
		for(j = 0; j < 2; j++)
			b[i][j] = b[i][j] / c[i][i];
	printf("\n\nInverse Matrix is:\n");
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 2; j++)
			printf("%d ", b[i][j]);
		printf("\n");
	}
}

void main() {
	getKeyMessage();
	encryption();
	decryption();
}