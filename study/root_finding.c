#include <stdio.h>
#define EPS 0.0001

float func1(float t)
{
	return (t*t-3.0);
}

float func2(float t)
{
	return (t*t*t-1.0);
}

float root_finding( float (*f)(float), float start, float end)
{
	printf("%f %f\n", start, end);

	float middle = (end+start)/2.0;

	if(end-start < EPS)
	{
		return (end+start)/2.0;
	}
	else
	{
		if((*f)(middle) > 0.0)
			root_finding(f, start, middle);
		else
			root_finding(f, middle, end);
	}
}

int main(void)
{
	float result1 = root_finding(func1, 0.0, 10.0);
	float result2 = root_finding(func2, 0.0, 10.0);
}
