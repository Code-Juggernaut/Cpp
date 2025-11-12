#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
int* sum(int*A,int*B,int size){
    int *ptr = (int*)malloc(size*sizeof(int));
    for(int i = 0;i<size;i++){
        ptr[i] = A[i]+B[i];
    }
    return ptr;
}
int main(){
    int size = 0;
    int *pointer = NULL;
    int arrayA[10] = {1,2,3,4,5,6,7,8,9,0};
    int arrayB[10] = {1,2,3,4,5,6,7,8,9,0};
    size = 10;
    int* (*ptr)(int*,int*,int);
    ptr = sum;
    pointer = ptr(arrayA,arrayB,sizeof(arrayA)/sizeof(int));
    for(int i = 0;i<size;i++){
        printf("%d ",pointer[i]);
    }
    free(pointer);
}