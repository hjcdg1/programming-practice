#include <stdio.h>

void merge(int* c, int* a, int* b, int n, int m)
{
	int a_cnt=0;
	int b_cnt=0;
	int c_cnt=0;

	while(a_cnt<n && b_cnt<m){
		if(a[a_cnt] < b[b_cnt])
			c[c_cnt++] = a[a_cnt++];
		else
			c[c_cnt++] = b[b_cnt++];
	}

	while(a_cnt<n)
		c[c_cnt++] = a[a_cnt++];
	while(b_cnt<m)
		c[c_cnt++] = b[b_cnt++];
}

int main(void)
{
	int i, n, m, A[10000], B[10000], C[20000];
	
	scanf("%d %d", &n, &m);
	for(i=0; i<n; i++)
		scanf("%d", &A[i]);
	for(i=0; i<m; i++)
		scanf("%d", &B[i]);
	merge(C, A, B, n, m);
	for(i=0; i<n+m; i++)
		printf("%d ", C[i]);
}
