#include <stdio.h>
#define bigger(x,y) (((x)>(y))?(x):(y))
#define smaller(x,y) (((x)<(y))?(x):(y))

/* 사각형  구조체 정의 */
typedef struct rect{
	double x1, y1, x2, y2;   //  x1 <= x2, y1 <= y2
} rect;

rect intersection(rect A, rect B)
{
    rect result = {0.0, 0.0, 0.0, 0.0};

    if(A.x2 <= B.x1  ||  A.x1 >= B.x2  ||  A.y2 <= B.y1  ||  A.y1 >= B.y2)
        return result;
    else{
        result.x1 = bigger(A.x1, B.x1);
        result.x2 = smaller(A.x2, B.x2);
        result.y1 = bigger(A.y1, B.y1);
        result.y2 = smaller(A.y2, B.y2);
        return result;
    }
}

double rect_area(rect A)
{
    return (A.y2-A.y1)*(A.x2-A.x1);
}

int main(void)
{
    int n, i;
    double area = 0.0;

    scanf("%d", &n);
    rect a[n];
    rect temp;

    for(i=0; i<n; i++)
        scanf("%lf %lf %lf %lf", &a[i].x1, &a[i].x2, &a[i].y1, &a[i].y2);

    temp = a[0];
    for(i=1; i<n; i++)
        temp = intersection(temp, a[i]);
    printf("겹치는 사각형 영역의 넓이 : %lf\n", rect_area(temp));
}
