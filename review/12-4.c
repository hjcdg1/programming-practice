#include "12-4.h"
#include "12-4-move.h"
            
void add2(board *a){
	int i, j;
	int n, N = 0;
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0) N++;
		}
	}
	if(N == 0) return;
	n = rand() % N;
	for(i = 0; i < 4; ++i){
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0){
				if(n == 0){
					a->tile[i][j] = 2;
					i = j = 4;
				}
				else n--;
			}
		}
	}
	return;
}

int main(void)
{
        board *curr = (board*)calloc(1, sizeof(board));
        board *next;
	board *init = (board*)calloc(1, sizeof(board));
	savenode* head = (savenode*)malloc(sizeof(savenode));
	head->next = NULL;
        int i, j, k;
        char com[10];

	srand(getseed());
	init->tile[2][0] = 2;
	init->tile[3][3] = 2;
	curr = init;

        while(1){
                print(curr);
                next = (board*)calloc(1, sizeof(board));        //      0으로 셋팅
                scanf("%s", com);
                switch(com[0]){
                        case 'w':
                                up(curr, next, head);
                                break;
                        case 'a':
                                left(curr, next, head);
                                break;
                        case 's':
                                down(curr, next, head);
                                break;
                        case 'd':
                                right(curr, next, head);
                                break;
			case 'u':
				curr = undo(init, head);
				break;
			case 'q':
				return 0;
                }
		if(com[0] != 'u'){
			add2(next);
			curr = next;
		}
        }
        print(curr);
}
