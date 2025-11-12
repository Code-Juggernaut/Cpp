#include<stdio.h>
#include<stdint.h>
#include <stdlib.h>
int multiplyer = 0;
void increment(int *pointer,int size){
    for(int i = 0;i<size;i++){
        pointer[i]++;
    }
}
void decrement(int *pointer,int size){
    for(int i = 0;i<size;i++){
        pointer[i]--;
    }
}
void multi(int *pointer,int size){
    for(int i = 0;i<size;i++){
        pointer[i]*=multiplyer;
    }
}
int main(){
    int size = 1;
    char op = ' ';
    char terminator = ' ';
    int *ptr = (int*)malloc(size*sizeof(int));
    
    int pos = 0;
    void (*function[3])(int*, int) = {increment,decrement,multi};
    printf("choose op(-/+/*)");
    scanf(" %c",&op);

    if(op == '*'){
        printf("enter multiplyer");
        scanf(" %d",&multiplyer);
        pos = 2;
    }else if(op == '-'){
        pos = 1;
    }else{
        pos = 0;
    }

    
    function[pos](ptr,size);
    for(int i = 0;i<size;i++){
        printf("Out: %d\n",ptr[i]);
    }

    free(ptr);
}