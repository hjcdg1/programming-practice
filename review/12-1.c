#include <stdio.h>
#include <stdlib.h>

/* 행렬 정보를 주면, 90도 돌린 새 행렬을 만들고 기존 행렬은 갖다 버린다. */
int** rotation (int** arr, int h, int w)
{
	int i, j;
	int** new = (int**)malloc(w*sizeof(int*));
	for(i=0; i<w; i++)
		new[i] = (int*)malloc(h*sizeof(int));
	for(i=0; i<w; i++)
		for(j=0; j<h; j++)
			new[i][j] = arr[h-1-j][i];
	free(arr);
	return new;
}

/* 행렬 정보를 주면 */
void print(int** arr, int h, int w)
{
	int i, j;
	for(i=0; i<h; i++){
		for(j=0; j<w; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}

int main(void)
{
	int n, m, i, j, command;
	int** arr;

    /* 이차원 배열 동적할당 */
	scanf("%d%d", &n, &m);
	arr = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
		arr[i] = (int*)malloc(m*sizeof(int));
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &arr[i][j]);


	scanf("%d", &command);
	switch(command){
		case 1:
			arr = rotation(arr, n, m);
			print(arr, m, n);
			break;
		case 2:
			arr = rotation(arr, n, m);
			arr = rotation(arr, m, n);
			print(arr, n, m);
			break;
		case 3:
			arr = rotation(arr, n, m);
			arr = rotation(arr, m, n);
			arr = rotation(arr, n, m);
			print(arr, m, n);
			break;
		case 0:
			print(arr, n, m);
	}
}
