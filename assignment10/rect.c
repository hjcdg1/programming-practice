#include <stdio.h>
#define N 3

typedef struct rect
{
	double x1;
	double x2;
	double y1;
	double y2;
} rect;

double bigger(double a, double b)
{
	if(a>=b)	return a;
	else		return b;
}

double smaller(double a, double b)
{
	if(a<=b)	return a;
	else		return b;
}

rect func(rect r1, rect r2)
{
	rect result;

	if((r1.x1 <= r2.x1) && (r2.x1 <= r1.x2) && (r1.x2 <= r2.x2))
	{
		result.x1 = r2.x1;
		result.x2 = r1.x2;
		result.y1 = smaller(r1.y1, r2.y1);
		result.y2 = bigger(r1.y2, r2.y2);
		return result;
	}
	else if((r1.x1 <= r2.x1) && (r2.x1 <= r2.x2) && (r2.x2 <= r1.x2))
	{
		result.x1 = r2.x1;
		result.x2 = r2.x2;
		result.y1 = smaller(r1.y1, r2.y1);
		result.y2 = bigger(r1.y2, r2.y2);
		return result;
	}
	else if((r2.x1 <= r1.x1) && (r1.x1 <= r1.x2) && (r1.x2 <= r2.x2))
	{
		result.x1 = r1.x1;
		result.x2 = r1.x2;
		result.y1 = smaller(r2.y1, r1.y1);
		result.y2 = bigger(r2.y2, r1.y2);
		return result;
	}
	else if((r2.x1 <= r1.x1) && (r1.x1 <= r2.x2) && (r2.x2 <= r1.x2))
	{
		result.x1 = r1.x1;
		result.x2 = r2.x2;
		result.y1 = smaller(r2.y1, r1.y1);
		result.y2 = bigger(r2.y2, r1.y2);
		return result;
	}
	else
	{
		result.x1 = 0.0;
		result.x2 = 0.0;
		result.y1 = 0.0;
		result.y2 = 0.0;
		return result;
	}
}

int main(void)
{
	int i;
	double area;
	rect r[3] = {{0.0, 4.0, 3.0, 0.0}, {2.0, 4.0, 2.0, 0.0}, {3.0, 5.0, 1.0, 0.0}};
	rect temp;
	
	temp = r[0];
	for(i=1; i<N; i++)
	{
		temp = func(temp, r[i]);
	}
	area = (temp.x2-temp.x1)*(temp.y1-temp.y2);
	
	printf("%f", area);
	return 0;
}
