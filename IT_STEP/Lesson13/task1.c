#include<stdlib.h>
#include<stdio.h>

void* paste_element(int pos,int value,void *array,int *size){
    array = realloc(array,((*size)+1)*sizeof(int));

    for(int i = (*size)-1;i>=pos;i--){
        ((int*)array)[i] = ((int*)array)[i-1];
    }
    ((int*)array)[pos] = value;
    (*size)++;
    return array;
}

void* delete_element(int pos,void *array,int *size){
    

    for(int i = pos;i<(*size)-1;i++){
        ((int*)array)[i] = ((int*)array)[i+1];
    }

    array = realloc(array,((*size)-1)*sizeof(int));

    (*size)--;
    return array;
}


int main(){
    int size = 10;
    void *pointer = (int*)malloc(sizeof(int)*10);
    for(int i= 0;i<size;i++){
        ((int*)pointer)[i] = rand()%10;
    }
    for(int i = 0;i<size;i++){
        printf("%d ",((int*)pointer)[i]);
    }
    printf("\n");

    pointer = paste_element(4,10,pointer,&size);

    for(int i = 0;i<size;i++){
        printf("%d ",((int*)pointer)[i]);
    }
    printf("\n");


    pointer = delete_element(3,pointer,&size);

    for(int i = 0;i<size;i++){
        printf("%d ",((int*)pointer)[i]);
    }
}