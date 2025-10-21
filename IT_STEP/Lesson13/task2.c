#include<stdio.h>
#include<stdlib.h>

void **paste_array(void **array,int *rows,int *cols,int value,int posx,int posy){

    for(int i = 0;i<(*rows);i++){
        array[i] = realloc(array[i],((*cols)+1)*sizeof(int*));
    }


    
    for(int j = (*cols);j>=posy;j--){
        ((int**)array)[posx][j] = ((int**)array)[posx][j-1];
    }
    
    (*cols)++;
    ((int**)array)[posx][posy] = value;
    return array;
}

int main(){
    int rows = 3;
    int cols = 3;
    void **pointer_to_pointer = (void**)malloc(rows*sizeof(int*));

    for(int i = 0;i<rows;i++){
        pointer_to_pointer[i] = malloc(cols*sizeof(int*));
    }

    for(int i =0 ;i<rows;i++){
        for(int j = 0;j<cols;j++){
            ((int**)pointer_to_pointer)[i][j] = rand()%10;
        }
    }


    for(int i =0 ;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",((int**)pointer_to_pointer)[i][j]);
        }
        printf("\n");
    }
    pointer_to_pointer = paste_array(pointer_to_pointer,&rows,&cols,10,2,2);

    for(int i =0 ;i<rows;i++){
        for(int j = 0;j<cols;j++){
            printf("%d ",((int**)pointer_to_pointer)[i][j]);
        }
        printf("\n");
    }

}