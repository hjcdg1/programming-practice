#include <stdio.h>
#define OK 1
#define NO 0

typedef struct rect {
    double x1, x2, y1, y2;
} rect;

double area(double x1, double x2, double y1, double y2, rect r[], int n)
{
    int i;
    for(i=0; i<n; i++)
        if(r[i].x1<=x1 && r[i].x2>=x2 && r[i].y1<=y1 && r[i].y2>=y2)    return (x2-x1)*(y2-y1);
    return 0.0;
}

void sort(double arr[], int n)
{
    int i, j;
    double temp;
    for(i=0; i<n-1; i++)
        for(j=0; j<n-1-i; j++)
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main(void)
{
    int n, i, j, value;
    double sum = 0.0;
    scanf("%d", &n);

    double s_line[2*n], r_line[2*n];    /* s_line은 세로선, r_line은 가로선 */
    int s_cnt = 0, r_cnt = 0;           /* s_cnt는 세로선 개수, r_cnt는 가로선 개수 */
    rect r[n];                          /* n개의 직사각형 */

    for(i=0; i<n; i++)
        scanf("%lf %lf %lf %lf", &r[i].x1, &r[i].x2, &r[i].y1, &r[i].y2);


    /* s_line에 모든 x좌표들(중복x), r_line에 모든 y좌표들(중복x)을 넣어주기 */
    value = OK;
    for(i=0; i<n; i++){      /* x1 넣기 */
        for(j=0; j<s_cnt; j++){
            if(s_line[j] == r[i].x1)    value = NO; break;
            else                        value = OK;
        }
        if(value == OK) s_line[s_cnt++] = r[i].x1;
    }

    for(i=0; i<n; i++){      /* x2 넣기 */
        for(j=0; j<s_cnt; j++){
            if(s_line[j] == r[i].x2)    value = NO; break;
            else                        value = OK;
        }
        if(value == OK) s_line[s_cnt++] = r[i].x2;
    }

    value = OK;
    for(i=0; i<n; i++){      /* y1 넣기 */
        for(j=0; j<r_cnt; j++){
            if(r_line[j] == r[i].y1)   value = NO; break;
            else                       value = OK;
        }
        if(value == OK) r_line[r_cnt++] = r[i].y1;
    }

    for(i=0; i<n; i++){      /* y2 넣기 */
        for(j=0; j<r_cnt; j++){
            if(r_line[j] == r[i].y2)    value = NO; break;
            else    value = OK;
        }
        if(value == OK) r_line[r_cnt++] = r[i].y2;
    }

    sort(s_line, s_cnt);
    sort(r_line, r_cnt);

    for(i=0; i<s_cnt-1; i++)
        for(j=0; j<r_cnt-1; j++)
            sum += area(s_line[i], s_line[i+1], r_line[j], r_line[j+1], r, n);

    printf("전체 면적: %lf\n", sum);
}
