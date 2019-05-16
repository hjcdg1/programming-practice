int score=0;
int u=0;

int check(board* next)  //  더 이상 움직일 수 없도록 꽉찬 경우를 검사
{
    int i, j, value;

    for(i=0; i<4; i++){
        for(j=0; j<3; j++){
            if(next->tile[i][j] != next->tile[i][j+1]  &&  (next->tile[i][j])*(next->tile[i][j+1]) != 0)
                value = 1;
            else
                return 1;
        }
    }
    for(j=0; j<4; j++){
        for(i=0; i<3; i++){
            if(next->tile[i][j] != next->tile[i+1][j]  &&  (next->tile[i][j])*(next->tile[i+1][j]) != 0)
                value = 1;
            else
                return 1;
        }
    }

    if(value == 1)  return -1;
}

int compare_board (board* a, board* b)
{
    int i, j;
    int value = 1;

    for(i=0; i<4; i++){
        for(j=0; j<4; j++){
            if(a->tile[i][j]  !=  b->tile[i][j]){
                value = 0;
                break;
            }
        }
    }

    return value;
}

int left (board* curr, board* next, savenode* head, savescore* head2)
{
        int i, j, len;
        stack left[4];

        if(compare_board(curr, look_board(head)) == 1){
            insert(head, curr);         //  바꾸기 전에, curr을 저장해둔다.
            insert2(head2, score);      //  바꾸기 전에, score을 저장해둔다.
        }

        for(i=0; i<4; i++){
                left[i].cnt = 0; left[i].top = NULL;
                for(j=0; j<4; j++){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&left[i])){
                                        score += curr->tile[i][j] + look(&left[i]);
                                        if(curr->tile[i][j] + look(&left[i]) == 2048)      return -5;                                        
                                        push(&left[i], curr->tile[i][j] + pop(&left[i]));
                                        push(&left[i], -2);
                                }
                                else
                                        push(&left[i], curr->tile[i][j]);
                        }
                }
        }
        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        next->tile[i][j] = 0;
        for(i=0; i<4; i++){
                len = count(left[i].top);
                for(j=len-1; j>=0; j--)
                        if(look(&left[i]) != -2)
                                next->tile[i][j] = pop(&left[i]);
                        else{
                                j++;
                                pop(&left[i]);
                        }
        }
        return 10;
}

int right (board* curr, board* next, savenode* head, savescore* head2)
{
        int i, j, len;
        stack right[4];
        insert(head, curr);
        insert2(head2, score);

        for(i=0; i<4; i++){
                right[i].cnt = 0; right[i].top = NULL;
                for(j=3; j>=0; j--){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&right[i])){
                                        score += curr->tile[i][j] + look(&right[i]);
                                        if(curr->tile[i][j] + look(&right[i]) == 2048)     return -5;
                                        push(&right[i], curr->tile[i][j] + pop(&right[i]));
                                        push(&right[i], -2);
                                }
                                else
                                        push(&right[i], curr->tile[i][j]);
                        }
                }
        }
        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        next->tile[i][j] = 0;
        for(i=0; i<4; i++){
                len = count(right[i].top);
                for(j=4-len; j<4; j++)
                        if(look(&right[i]) != -2)
                                next->tile[i][j] = pop(&right[i]);
                        else{
                                j--;
                                pop(&right[i]);
                        }
        }
        return 10;
}

int up (board* curr, board* next, savenode* head, savescore* head2)
{
        int i, j, len;
        stack up[4];
        insert(head, curr);
        insert2(head2, score);

        for(j=0; j<4; j++){
                up[j].cnt = 0; up[j].top = NULL;
                for(i=0; i<4; i++){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&up[j])){
                                        score += curr->tile[i][j] + look(&up[j]);
                                        if(curr->tile[i][j] + look(&up[j]) == 2048)        return -5;                                       
                                        push(&up[j], curr->tile[i][j] + pop(&up[j]));
                                        push(&up[j], -2);
                                }
                                else
                                        push(&up[j], curr->tile[i][j]);
                        }
                }
        }
        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        next->tile[i][j] = 0;
        for(j=0; j<4; j++){
                len = count(up[j].top);
                for(i=len-1; i>=0; i--)
                        if(look(&up[j]) != -2)
                                next->tile[i][j] = pop(&up[j]);
                        else{
                                i++;
                                pop(&up[j]);
                        }
        }
        return 10;
}

int down (board* curr, board* next, savenode* head, savescore* head2)
{
        int i, j, len;
        stack down[4];
        insert(head, curr);
        insert2(head2, score);

        for(j=0; j<4; j++){
                down[j].cnt = 0; down[j].top = NULL;
                for(i=3; i>=0; i--){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&down[j])){
                                        score += curr->tile[i][j] + look(&down[j]);
                                        if(curr->tile[i][j] + look(&down[j]) == 2048)      return -5;
                                        push(&down[j], curr->tile[i][j] + pop(&down[j]));
                                        push(&down[j], -2);
                                }
                                else
                                        push(&down[j], curr->tile[i][j]);
                        }
                }
        }
        for(i=0; i<4; i++)
                for(j=0; j<4; j++)
                        next->tile[i][j] = 0;
        for(j=0; j<4; j++){
                len = count(down[j].top);
                for(i=4-len; i<4; i++)
                        if(look(&down[j]) != -2)
                                next->tile[i][j] = pop(&down[j]);
                        else{
                                i--;
                                pop(&down[j]);
                        }
        }
        return 10;
}

board* undo(board* init, savenode* head)
{
        board* temp;
        if(head->next == NULL)  // 아무것도 저장된 상태가 없다면
                return init;
        else{
                if(head->next->next == NULL){
                        temp = head->next->d;
                        free(head->next);
                        head->next = NULL;
                        return temp;
                }
                else{
                        undo(init, head->next);
                }
        }
}

int undo2(savescore* head)
{
        int temp;
        if(head->next == NULL)  // 아무것도 저장된 점수가 없다면
            return 0;
        else{
                if(head->next->next == NULL){
                        temp = head->next->d;
                        free(head->next);
                        head->next = NULL;
                        return temp;
                }
                else{
                        undo2(head->next);
                }
        }
}

void sort (char* result_name[], int result_score[], int result_i)
{
        int result_score_temp;
        char* result_name_temp;
        int i, j;

        for(i=0; i<result_i-1; i++){
            for(j=0; j<result_i-1-i; j++){
                if(result_score[j] < result_score[j+1]){
                    result_score_temp = result_score[j];
                    result_score[j] = result_score[j+1];
                    result_score[j+1] = result_score_temp;

                    strcpy(result_name_temp, result_name[j]);
                    strcpy(result_name[j], result_name[j+1]);
                    strcpy(result_name[j+1], result_name_temp);
                }
            }
        }
}

