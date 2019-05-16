#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    char d;
    struct node* next;
} node;

typedef struct stack{
    int cnt;
    node* top;
} stack;

char pop (stack* s)
{
    char data;
    node* temp;
    if(s->cnt > 0){
        temp = s->top->next;
        data = s->top->d;
        free(s->top);
        s->top = temp;
        (s->cnt)--;
        return data;
    }
    else
        return -1;
}

void push (stack*s, char item)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->d = item;
    temp->next = s->top;
    s->top = temp;
    (s->cnt)++;
}

char look (stack* s)
{
    if(s->cnt >0)
        return s->top->d;
    else
        return -1;
}

int main(void)
{
    int i, left, right, value=0;
    char input[10000];
    scanf("%s", input);
    stack s = {0, NULL};

    for(i=0; input[i]!='\0'; i++){
        if(input[i] == '(' || input[i] == '[' || input[i] == '{')
            push(&s, input[i]);
        else{
            left = look(&s);
            right = input[i];
            if((left=='('&&right==')') || (left=='['&&right==']') || (left=='{'&&right=='}')){
                value = 1;
                pop(&s);
            }
            else{
                value = 0;
                break;
            }
        }
    }
    if(value==1 && s.cnt==0)
        printf("TRUE\n");
    else
        printf("FALSE\n");
    
    return 0;
}
