#include<stdio.h>
#include<stdlib.h>

void select_sort(int *array,int size){
    int min = 0;
    int buffer =0;
    for(int i = 0;i<size-1;i++){
        min = i;
        for(int j = i+1;j<size;j++){
            if(array[j]<array[min]){
                min = j;
            }
        }
        if(min != i){
            buffer = array[i];
            array[i] = array[min];
            array[min] = buffer;
        }
    }

}

int main(){
    
    int size = 10;
    int *pointer = (int*)malloc(size*sizeof(int));
    srand(pointer[0]);
    for(int i =0;i<size;i++){
        pointer[i] = rand()%10;
        printf("%d ",pointer[i]);
    }
    printf("\n");
    select_sort(pointer,size);
    for(int i = 0;i<size;i++){
        printf("%d ",pointer[i]);
    }
    free(pointer);
    
}