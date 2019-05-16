#include <stdio.h>
#include <stdlib.h>

typedef struct board{
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

void print(board* a){
	int i, j;
	printf("-----------------------------\n");
	for(i=0; i<4; i++){
		printf("|      |      |      |      |\n|");
		for(j=0; j<4; j++){
			if(a->tile[i][j] == 0)	printf("      |");
			else			printf("%6d|", a->tile[i][j]);
		}
		printf("\n|      |      |      |      |\n");
		printf("-----------------------------\n");
	}
	return;
}

void left(board* before, board* after){
	int i, j, n;
	int p;
	stack s[4];
	
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
}

void right(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];

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
}

void up(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];

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
}

void down(board* before, board* after){
        int i, j, n;
	int p;
        stack s[4];

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
}

int main(void)
{
	board* curr = (board*)malloc(sizeof(board));
	board* next;
	
	int i, j, n;
	char command[10];

	scanf("%d", &n);

	for(i=0; i<4; i++)
		for(j=0; j<4; j++)
			scanf("%d", &curr->tile[i][j]);
	
	for(i=0; i<n; i++){
		print(curr);
		next = (board*)calloc(1, sizeof(board));
		scanf("%s", command);
		switch(command[0]){
			case 'w':
				up(curr, next);	
				break;
			case 'a':
				left(curr, next);
				break;
			case 's':
				down(curr, next);
				break;
			case 'd':
				right(curr, next);
				break;
		}
		free(curr);
		curr = next;
	}
	print(curr);
	return 0;
}
