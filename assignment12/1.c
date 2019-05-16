#include <stdio.h>

int main(void)
{
	int n, m, input;
	int i, j;
	scanf("%d %d", &n, &m);
	int arr[n][m];
	
	for(i=0; i<n; i++)
		for(j=0; j<m; j++)
			scanf("%d", &arr[i][j]);
	scanf("%d", &input);

	if(input == 0){
		for(i=0; i<n; i++){
			for(j=0; j<m; j++)
				printf("%d ", arr[i][j]);
			printf("\n");
		}
	}

	else if(input == 1){
		int b[m][n];
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				b[i][j] = arr[n-1-j][i];

		for(i=0; i<m; i++){
			for(j=0; j<n; j++)
				printf("%d ", b[i][j]);
			printf("\n");
		}
	}

	else if(input == 2){
		int b[n][m];
		for(i=0; i<n; i++)
			for(j=0; j<m; j++)
				b[i][j] = arr[n-1-i][m-1-j];
		for(i=0; i<n; i++){
			for(j=0; j<m; j++)
				printf("%d ", b[i][j]);
			printf("\n");
		}
	}

	else if(input == 3){
		int b[m][n];
		for(i=0; i<m; i++)
			for(j=0; j<n; j++)
				b[i][j] = arr[j][m-1-i];
		for(i=0; i<m; i++){
			for(j=0; j<n; j++)
				printf("%d ", b[i][j]);
			printf("\n");
		}
	}
}
