#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM 1000

void merge(int arr[], int start, int middle, int end)
{
    int a_index = start, b_index = middle+1, c_index = 0;
    int i;
    static int temp[NUM];

    while(a_index<middle+1  &&  b_index<end+1){
        if(arr[a_index] < arr[b_index])
            temp[c_index++] = arr[b_index++];
        else
            temp[c_index++] = arr[a_index++];
    }

    while(a_index<middle+1)
        temp[c_index++] = arr[a_index++];
    while(b_index<end+1)
        temp[c_index++] = arr[b_index++];

    for(i=0; i<end-start+1; i++)
        arr[start+i] = temp[i];
}

void mergesort(int arr[], int start, int end)
{
    if(start == end)    return;
    else{
        int middle = (start+end)/2;
        mergesort(arr, start, middle);
        mergesort(arr, middle+1, end);
        merge(arr, start, middle, end);
    }
}

int main(void)
{
    int i, arr[NUM];

    for(i=0; i<NUM; i++)
        arr[i] = rand()/1000;
    mergesort(arr, 0, NUM-1);
    
    for(i=0; i<NUM; i++)
        printf("%d\n", arr[i]);
}
