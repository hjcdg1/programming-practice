#include <stdio.h>

int main(void)
{
	int n;
	int i, j, k;
	
	scanf("%d", &n);
	
	for(i=1; i<=2*n-1; i++)
	{
		if(i==n)
		{
			for(j=1; j<=2*n-1; j++)
			{
				if(j==n)	printf("*");
				else		printf(" ");
			}
		}

		else if(i<n)
		{
			for(k=0; k<i-1; k++)
				printf(" ");
			for(k=0; k<(2*n-1)-(2*i-2); k++)
				printf("*");
		}

		else if(i>n)
		{
			for(k=0; k<2*n-i-1; k++)
				printf(" ");

			for(k=0; k<1+2*(i-n); k++)
				printf("*");
		}

		printf("\n");
	}

	return 0;
}
