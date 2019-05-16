#include <stdio.h>
#include <stdlib.h>

void line(int** board, int index, int n, int num)
{
	int i, j;
	if(n == 0)
		return;
	else if(n == 1){
		board[index][index] = num;
		return;
	}
	else{
		for(j=index; j<index+n; j++)
			board[index][j] = num++;
		for(i=index+1; i<index+n; i++)
			board[i][index+n-1] = num++;
		for(j=index+n-2; j>=index; j--)
			board[index+n-1][j] = num++;
		for(i=index+n-2; i>index; i--)
			board[i][index] = num++;
		line(board, index+1, n-2, num);
		return;
	}
}

int main(void)
{
	int n, i, j, num=1;
	int** board;

    /* 2차원 배열 동적 할당 */
	scanf("%d", &n);
	board = (int**)malloc(n*sizeof(int*));
	for(i=0; i<n; i++)
		board[i] = (int*)malloc(n*sizeof(int));

	line(board, 0, n, num);
	
    for(i=0; i<n; i++){
		for(j=0; j<n; j++)
			printf("%4d ", board[i][j]);
		printf("\n");
	}
}
