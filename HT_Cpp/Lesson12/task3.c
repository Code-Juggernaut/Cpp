#include<stdio.h>
#include"libs/dynamic_arr.h"

int main(){
    int rows = 4;
    int cols = 4;
    int **pointer = init_array(pointer,rows,cols);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",pointer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    pointer = shift_array(pointer,1,'L',rows,cols);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",pointer[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    pointer = delete_array(pointer,&rows,&cols);

}