#include <stdio.h> // 순서쌍 효율적으로 검사하는 법! 크기순! //
#define ab(x) (((x)>0)?(x):(-(x)))

int main(void)
{
	int n, i, j, k, x[10000], y[10000];
	double area = 0.0, maxarea = 0.0;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
		scanf("%d%d", &x[i], &y[i]);
	
	for(i=0; i<n-2; i++){
		for(j=i+1; j<n-1; j++){
			for(k=j+1; k<n; k++){
				area = ((double)ab(x[i]*y[j]+x[j]*y[k]+x[k]*y[i]-y[i]*x[j]-y[j]*x[k]-y[k]*x[i]))/2;
				if(area > maxarea)
					maxarea = area;
			}
		}
	}
	printf("%.2f", maxarea);
}
