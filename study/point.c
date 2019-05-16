#include <stdio.h>
#include <math.h>

int main(void)
{
	int x[6] = {1, 4, 3, 2, 7, 5};	// 6개의 점 각각의 x좌표들
	int y[6] = {1, 1, 2, 4, 5, 7};	// 6개의 점 각각의 y좌표들
	int i, j;
	double distance;
	double max=0.0;
	int mi;	
	int mj;

	// 행렬의 삼각형 부분만 본다고 생각. 순서쌍의 중복을 피하고 효율적인 코드를 짜기 위해!
	for(i=0;i<5;i++)		//	점이 n개라면, i<n-1
	{
		for(j=i+1; j<6; j++)	//	점이 n개라면, j<n-1-i
		{
			distance = sqrt((double)((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j])));
			if(distance > max)
			{
				max=distance;
				mi=i;
				mj=j;
			}
		}
	}
	
	printf("거리가 가장 먼 점의 쌍 : (%d, %d)와 (%d, %d)\n", x[mi], y[mi], x[mj], y[mj]);
		
}
