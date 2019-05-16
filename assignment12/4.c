#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#ifdef ONLINE_JUDGE
int getseed(){
	return 0;
}
#endif

#ifndef ONLINE_JUDGE
#include <time.h>
int getseed(){
	return time(NULL);
}
#endif

typedef struct _board{
	int tile[4][4];
} board;

typedef struct element{
        int d;
        struct element* next;
} node;

typedef struct stack{
        int cnt;
        node* top;
} stack;

void init(stack* s){
	s->cnt = 0;
	s->top = NULL;
}

int pop(stack* s){
        int data;
        node* temp;
        if((s->cnt)>0){
                data = s->top->d;
                temp = s->top;
                (s->cnt)--;
                (s->top) = s->top->next;
                free(temp);
                return data;
        }
        return 0;
}

void push(stack* s, int data){
        node* temp = (node*)malloc(sizeof(node));
        temp->next = s->top;
        temp->d = data;
        s->top = temp;
        (s->cnt)++;
}

int look(stack* s){
	if((s->cnt)>0){
		return (s->top->d);
	}
	return -1;
}

int count(node* head){
	if(head == NULL)
		return 0;
	else{
		if(head->d == -2)	return count(head->next);
		else			return (1+count(head->next));
	}
}

board left(board* before, board* after){
	int i, j, n;
	int p;
	stack s[4];
	board save = *before;
	
	for(i=0; i<4; i++){
		init(&s[i]);
		for(j=0; j<4; j++){
			if(before->tile[i][j] != 0){
				if(before->tile[i][j] == look(&s[i])){
					push(&s[i], (before->tile[i][j]) + pop(&s[i]) );
					push(&s[i], -2);
				}
				else
					push(&s[i], before->tile[i][j]);
			}
		}
	}

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			after->tile[i][j] = 0;

	for(i=0; i<4; i++){
		p = 0;
		n = count(s[i].top);
		while(p<n){
			if(look(&s[i]) == -2){
				pop(&s[i]);
			}
			else{
				after->tile[i][n-1-p] = pop(&s[i]);
				p++;
			}
		}
	}
	return save;
}

board right(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];
	board save = *before;

	for(i=0; i<4; i++){
                init(&s[i]);
                for(j=3; j>=0; j--){
                        if(before->tile[i][j] != 0){
                                if(before->tile[i][j] == look(&s[i])){
                                        push(&s[i], (before->tile[i][j]) + pop(&s[i]) );
					push(&s[i], -2);
				}
                                else
                                        push(&s[i], before->tile[i][j]);
                        }
                }
        }

        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        after->tile[i][j] = 0;

        for(i=0; i<4; i++){
		p=0;
                n = count(s[i].top);
                while(p<n){
			if(look(&s[i]) == -2)
				pop(&s[i]);
			else{
				after->tile[i][4-n+p] = pop(&s[i]);
				p++;
			}
		}
        }
	return save;
}

board up(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];
	board save = *before;

        for(j=0; j<4; j++){
                init(&s[j]);
                for(i=0; i<4; i++){
                        if(before->tile[i][j] != 0){
                                if(before->tile[i][j] == look(&s[j])){
                                        push(&s[j], (before->tile[i][j]) + pop(&s[j]) );
					push(&s[j], -2);
				}
                                else
                                        push(&s[j], before->tile[i][j]);
                        }
                }
        }

        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        after->tile[i][j] = 0;
	
        for(j=0; j<4; j++){
		p = 0;
                n = count(s[j].top);
                while(p<n){
			if(look(&s[j]) == -2)
				pop(&s[j]);
			else{
				after->tile[n-1-p][j] = pop(&s[j]);
				p++;
			}
		}
        }
	return save;
}

board down(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];
	board save = *before;

        for(j=0; j<4; j++){
                init(&s[j]);
                for(i=3; i>=0; i--){
                        if(before->tile[i][j] != 0){
                                if(before->tile[i][j] == look(&s[j])){
                                        push(&s[j], (before->tile[i][j]) + pop(&s[j]) );
					push(&s[j], -2);
				}
                                else
                                        push(&s[j], before->tile[i][j]);
                        }
                }
        }

        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        after->tile[i][j] = 0;

        for(j=0; j<4; j++){
		p = 0;
                n = count(s[j].top);
                while(p<n){
			if(look(&s[j]) == -2)
				pop(&s[j]);
			else{
                        	after->tile[4-n+p][j] = pop(&s[j]);
				p++;
			}
		}
        }
	return save;
}

void print(board *a){
	int i,j;
	printf("-----------------------------\n");
	for(i = 0; i < 4; ++i){
		printf("|      |      |      |      |\n|");
		for(j = 0; j < 4; ++j){
			if(a->tile[i][j] == 0) printf("      |");
			else printf("%6d|", a->tile[i][j]);
		}
		printf("\n|      |      |      |      |\n");
		printf("-----------------------------\n");
	}
	return;
}

/* randomly select a blank and put 2 in it. */
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

int main(){
	board *curr = (board *) calloc(1, sizeof(board));
	board *next;
	board save[100];
	int n;
	int i, j, k;
	int p=-1;
	char com[10];
	
	srand(getseed());
	curr->tile[2][0] = 2;
	curr->tile[3][3] = 2;
	save[0] = *curr;

	while(1){
		print(curr);
		next = (board *) calloc(1, sizeof(board));
		scanf("%s", com);
		switch(com[0]){
		case 'w':
			save[++p] = up(curr, next);
			break;
		case 'a':
			save[++p] = left(curr, next);
			break;
		case 's':
			save[++p] = down(curr, next);
			break;
		case 'd':
			save[++p] = right(curr, next);
			break;
		case 'u':
			if(p>=0)	*next = save[p--];
			else		*next = save[0];
			break;
		case 'q':
			return 0;
		}
		if(com[0] != 'u'){
			add2(next);
		}
		curr = next;
	}
}

