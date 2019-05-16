#include "4.h"
#include "4-move.h"

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
	savescore* head2 = (savescore*)malloc(sizeof(savescore));
	head2->next = NULL;

        int i, j, k, v;
        char com[10];

	srand(getseed());
/*	init->tile[2][0] = 2;
	init->tile[3][3] = 2;
*/
	init->tile[0][0] = 8;
	init->tile[0][1] = 16;
        init->tile[0][2] = 8;
        init->tile[0][3] = 16;
        init->tile[1][0] = 16;
        init->tile[1][1] = 8;
        init->tile[1][2] = 16;
        init->tile[1][3] = 8;
        init->tile[2][0] = 8;
        init->tile[2][1] = 16;
        init->tile[2][2] = 8;
        init->tile[2][3] = 2;
        init->tile[3][0] = 16;
        init->tile[3][1] = 8;
        init->tile[3][2] = 16;
        init->tile[3][3] = 2;

	curr = init;

        while(1){
                print(curr);
		if(check(curr) == -1){
			printf("score : %d\n", score-5*u);
			return 0;
		}
                next = (board*)calloc(1, sizeof(board));        //      0으로 셋팅
                scanf("%s", com);
                switch(com[0]){
                        case 'w':
                                v=up(curr, next, head, head2);
                                break;
                        case 'a':
                                v=left(curr, next, head, head2);
                                break;
                        case 's':
                                v=down(curr, next, head, head2);
				break;
                        case 'd':
                                v=right(curr, next, head, head2);
                                break;
			case 'u':
				u++;
				curr = undo(init, head);
				score = undo2(head2);
				break;
			case 'q':
				print(curr);
				printf("score : %d\n", score-5*u);
				return 0;
                }
		if(com[0] != 'u'){
			add2(next);
			curr = next;
		}
		if(v == -5){
			printf("score : %d\n", score-5*u);
			return 0;
		}
        }
        print(curr);
}
