#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *array,int size){
    int flag = 0;
    int buffer = 0;
    while(flag == 0){
        flag =1;
        for(int i = 1;i<size;i++){
            if(array[i]<array[i-1]){
                
                flag = 0;
                buffer = array[i-1];
                array[i-1] = array[i];
                array[i] = buffer;
                
            }
        }
    }
}

int main(){
    int size = 12;
    int *pointer = (int*)malloc(size*sizeof(int));
    for(int i= 0;i<size;i++){
        pointer[i] = rand()%10;
    }
    for(int i =0;i<size;i++){
        printf("%d ",pointer[i]);
    }
    printf("\n");
    bubble_sort(pointer,size);

    for(int i =0;i<size;i++){
        printf("%d ",pointer[i]);
    }
}