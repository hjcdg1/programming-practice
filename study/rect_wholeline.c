#include <stdio.h>
#include <stdlib.h>
#define OK 1
#define NO 0

typedef struct rect {
    double x1, x2, y1, y2;
} rect;

int one_or_zero(double x1, double x2, double y1, double y2, rect r[], int n)
{
    int i;
    for(i=0; i<n; i++)
        if(r[i].x1<=x1 && r[i].x2>=x2 && r[i].y1<=y1 && r[i].y2>=y2)
            return 1;
    return 0;
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
    int **M;
    double sum = 0.0;
    scanf("%d", &n);

    double s_line[2*n], r_line[2*n];     /* s_line은 세로선, r_line은 가로선 */
    int s_cnt = 0, r_cnt = 0;            /* s_cnt는 세로선 개수, r_cnt는 가로선 개수 */
    rect r[n];                           /* n개의 직사각형 */

    for(i=0; i<n; i++)
        scanf("%lf %lf %lf %lf", &r[i].x1, &r[i].x2, &r[i].y1, &r[i].y2);

    value = OK;
    for(i=0; i<n; i++){      /* x1 넣기 */
        for(j=0; j<s_cnt; j++){
            if(s_line[j] == r[i].x1){
                value = NO;
                break;
            }
            else    value = OK;
        }
        if(value == OK) s_line[s_cnt++] = r[i].x1;
    }

    for(i=0; i<n; i++){      /* x2 넣기 */
        for(j=0; j<s_cnt; j++){
            if(s_line[j] == r[i].x2){
                value = NO;
                break;
            }
            else    value = OK;
        }
        if(value == OK) s_line[s_cnt++] = r[i].x2;
    }

    value = OK;
    for(i=0; i<n; i++){      /* y1 넣기 */
        for(j=0; j<r_cnt; j++){
            if(r_line[j] == r[i].y1){
                value = NO;
                break;
            }
            else    value = OK;
        }
        if(value == OK) r_line[r_cnt++] = r[i].y1;
    }

    for(i=0; i<n; i++){      /* y2 넣기 */
        for(j=0; j<r_cnt; j++){
            if(r_line[j] == r[i].y2){
                value = NO;
                break;
            }
            else    value = OK;
        }
        if(value == OK) r_line[r_cnt++] = r[i].y2;
    }

    sort(s_line, s_cnt);
    sort(r_line, r_cnt);
    
    /* 행렬 할당 */
    M = (int**)malloc((r_cnt-1)*sizeof(int*));
    for(i=0; i<r_cnt-1; i++)
        M[i] = (int*)malloc((s_cnt-1)*sizeof(int));
    for(i=0; i<r_cnt-1; i++)
        for(j=0; j<s_cnt-1; j++)
            M[i][j] = one_or_zero(s_line[j], s_line[j+1], r_line[r_cnt-2-i], r_line[r_cnt-1-i], r, n);

    double M_slen[r_cnt-1], M_rlen[s_cnt-1];
    for(i=0; i<r_cnt-1; i++)
        M_slen[i] = r_line[r_cnt-1-i]-r_line[r_cnt-2-i];

    for(i=0; i<s_cnt-1; i++)
        M_rlen[i] = s_line[i+1]-s_line[i];

    /* 행렬 가로 체크 */
    for(i=0; i<r_cnt-1; i++)
        for(j=0; j<s_cnt-2; j++)
            if(M[i][j] != M[i][j+1])
                sum += M_slen[i];
    /* 행렬 세로 체크 */
    for(j=0; j<s_cnt-1; j++)
        for(i=0; i<r_cnt-2; i++)
            if(M[i][j] != M[i+1][j])
                sum += M_rlen[j];
    /* 가로 모서리 체크 */
    for(j=0; j<s_cnt-1; j++){
        if(M[0][j] == 1)
            sum += M_rlen[j];
        if(M[r_cnt-2][j] == 1)
            sum += M_rlen[j];
    }
    /* 세로 모서리 체크 */
    for(i=0; i<r_cnt-1; i++){
        if(M[i][0] == 1)
            sum += M_slen[i];
        if(M[i][s_cnt-2] == 1)
            sum += M_slen[i];
    }
    printf("전체 둘레: %lf\n", sum);
}
