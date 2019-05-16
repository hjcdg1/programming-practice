#include <stdio.h>

int main(void)
{
	int n, i, j, score[10000], cnt[10000];
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d", &score[i]);
	
	for(i=0; i<n; i++){
		cnt[i] = 0;
		for(j=0; j<n; j++){
			if(score[i] < score[j])
				cnt[i]++;
		}
	}

	for(i=0; i<n; i++)
		printf("%d ", cnt[i]+1);
}
