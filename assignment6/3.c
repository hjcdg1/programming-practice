#include <stdio.h>

void merge(int c[], int a[], int b[], int n, int m)
{
	int i=0;	//	a배열의 위치를 가리킬 인덱스
	int j=0;	//	b배열의 위치를 가리킬 인덱스
	int k=0;	//	c배열의 위치를 가리킬 인덱스

	for(k=0; k<n+m; k++)
	{
		if(i == n)		//	a배열은 이미 다 들어간 상태라면, 비교하지 말고 그냥 b를 넣어주면 되지.
			c[k]=b[j++];
		else if(j == m)		//	b배열은 이미 다 들어간 상태라면, 비교하지 말고 그냥 a를 넣어주면 되지.
			c[k]=a[i++];
		else			//	둘 중 하나가 완전히 들어간 상태가 아니라면, 꼭 비교한 후에 어떤 걸 넣어줄 지 결정해야지.
		{
			if(a[i] <= b[j])
				c[k]=a[i++];
			else
				c[k]=b[j++];
		}
	}
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int a[1000000];
int b[1000000];
int c[1000000];

int main(void)
{
	int n, m;
	int i;

	scanf("%d %d", &n, &m);
	
	for(i=0; i<n; i++)
		scanf("%d", &a[i]);

	for(i=0; i<m; i++)
		scanf("%d", &b[i]);

	merge(c, a, b, n, m);

	for(i=0; i<n+m; i++)
		printf("%d ", c[i]);
}
