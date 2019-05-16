#include <stdio.h>
#include <math.h>

double ab(double x)
{
	if(x>0)	return x;
	else	return (-x);
}

double fun(double x)
{
	return (x * pow(2, x));
}

int main(void)
{
	double left, right;
	double middle;
	double y;

	left = 0.0;
	right = 20.0;
	
	scanf("%lf", &y);

	while(ab(left-right)>1e-4)
	{
		middle = (left+right)/2;
		if(fun(middle) > y)
			right = middle;
		else
			left = middle;
	}

	printf("%f", (right+left)/2);

	return 0;
}
