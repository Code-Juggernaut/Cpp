#include<stdio.h>
#include<stdlib.h>
#include"libs/dynamic_arr.h"


int main(){
    int rows = 4;
    int cols = 4;
    int **pointer = NULL;
    pointer = init_array(pointer,rows,cols);
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",pointer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    pointer = delete_column(pointer,1,rows,&cols);

    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",pointer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    delete_array(pointer,rows,cols);
}