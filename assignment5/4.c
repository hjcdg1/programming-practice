#include <stdio.h>
#include <math.h>

int main(void)
{
	int n;			//	점의 개수
	int i, j, k;		//	점 순서쌍 (i, j, k) 비교할 것
	int mi, mj, mk;
	double area;
	double max=0.0;

	scanf("%d", &n);
	int x[n], y[n];

	for(i=0; i<n; i++)
		scanf("%d %d", &x[i], &y[i]);	//	n개의 점에 대한 정보 입력 받음

	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				 area= ((double)abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i]))/2;
				 if(area>max)
				 {
					 max=area;
					 mi=i;
					 mj=j;
					 mk=k;
				 }
			}
		}
	}

	/* 
	<가장 효율적인 for문> (i, j, k) 순서쌍을 따지는데, 효율성을 높이기 위해 중복되는 순서쌍 없이 반복문을 돌리려면? -> 크기 순서대로 배열한다고 생각하자!

	for(i=0; i<=n-3; i++)
	{
		for(j=i+1; j<=n-2; j++)
		{
			for(k=j+1; k<=n-1; k++)
			{
				area = ((double)abs(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i]))/2;
				if(area > max)
				{
					max=area;
					mi=i;
					mj=j;
					mk=k;
				}
			}
		}
	}
	*/

	printf("%.2f", max);

}
