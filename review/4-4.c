#include <stdio.h>  /* 복습 요망 */

void print(int total, int n)
{
	int i;
	int space = (total-n)/2;
	
	for(i=0; i<space; i++)
		printf(" ");
	for(i=0; i<n; i++)
		printf("*");
	for(i=0; i<space; i++)
		printf(" ");
	printf("\n");
}

int main(void)
{
	int i, n;
	int up, down;
	scanf("%d", &n);
	up = n;
	down = n-1;
	
	for(i=0; i<up; i++)
		print(2*n-1, 2*n-1-2*i);
	for(i=0; i<down; i++)
		print(2*n-1, 3+2*i);
}
