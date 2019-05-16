#include <stdio.h>

int main(void)
{
	int n;
	int len = 0;
	int j = 0;
	int k = 0;
	int l = 0;
	scanf("%d", &n);
	
	len = 2*n-1;
	
	for(j=1;j<n+1;j++)
	{
		for(k=0;k<j-1;k++)
		{
			printf(" ");
		}
		
		for(l=0;l<len-2*(j-1);l++)
		{
			printf("*");
		}
		printf("\n");
	}
	j=0;
	k=0;
	l=0;

	for(j=1;j<n;j++)
	{
		for(k=0;k<n-j-1;k++)
		{
			printf(" ");
		}
		for(l=0;l<2*j+1;l++)
		{
			printf("*");
		}
		printf("\n");

	}
}
