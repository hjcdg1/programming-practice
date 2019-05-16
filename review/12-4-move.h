void left (board* curr, board* next, savenode* head)
{
        int i, j, len;
        stack left[4];
        insert(head, curr);
        for(i=0; i<4; i++){
                left[i].cnt = 0; left[i].top = NULL;
                for(j=0; j<4; j++){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&left[i])){
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
}

void right (board* curr, board* next, savenode* head)
{
        int i, j, len;
        stack right[4];
        insert(head, curr);
        for(i=0; i<4; i++){
                right[i].cnt = 0; right[i].top = NULL;
                for(j=3; j>=0; j--){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&right[i])){
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
}

void up (board* curr, board* next, savenode* head)
{
        int i, j, len;
        stack up[4];
        insert(head, curr);
        for(j=0; j<4; j++){
                up[j].cnt = 0; up[j].top = NULL;
                for(i=0; i<4; i++){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&up[j])){
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
}

void down (board* curr, board* next, savenode* head)
{
        int i, j, len;
        stack down[4];
        insert(head, curr);
        for(j=0; j<4; j++){
                down[j].cnt = 0; down[j].top = NULL;
                for(i=3; i>=0; i--){
                        if(curr->tile[i][j] != 0){
                                if(curr->tile[i][j] == look(&down[j])){
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

