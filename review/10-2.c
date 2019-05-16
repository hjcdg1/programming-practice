#include <stdio.h>
#include <math.h>
#define ab(x) (((x)>0)?(x):(-(x)))

double function(double x)
{
	return x*pow(2, x);
}

double search(double y, double left, double right)
{
	double middle = (right+left)/2;
	
	if(ab(right-left)<1e-4) // ab(function(middle)-y) < 1e-4 도 가능
		return middle;
	
	else if(function(middle) > y)
		search(y, left, middle);
	
	else if(function(middle) < y)
		search(y, middle, right);
}

int main(void)
{
	double y;
	scanf("%lf", &y);
	printf("%f", search(y, 0.0, 20.0));
}
