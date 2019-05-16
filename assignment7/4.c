#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i, j, k, m;
	int count = 0;
	int n;
	scanf("%d", &n);
	char a[n][n];		//	체스판 크기는 n by n

	for(i=0; i<n; i++)
		scanf("%s", a[i]);
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(a[i][j] == 'Q')
			{
				for(k=0;k<n;k++)
				{
					for(m=0;m<n;m++)
					{
						if(a[k][m] == 'Q')
						{
							if(k==i && m!=j)
								count++;
			
							else if(k!=i && m==j)
								count++;
							
							else if(k-i == m-j)
							{
								count++;
								if(k==i && m==j)	count--;
							}
							else if(k-i == j-m)
							{
								count++;
								if(k==i && m==j)	count--;
							}
						}
					}
				}
			}
		}
	}

	printf("%d", count/2);
}
