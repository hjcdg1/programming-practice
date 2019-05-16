#include <stdio.h>

int main(void)
{
	int n;
	int i, j;
	int score[1000];
	int rank[1000];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &score[i]);
	
	for(i=0; i<n; i++)
		rank[i]=0;
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n ;j++)
			if(score[j]>score[i])
				rank[i]++;
	}
	
	for(i=0; i<n; i++)
		printf("%d ", rank[i]+1);
}
