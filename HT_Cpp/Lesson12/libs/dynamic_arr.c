#include"dynamic_arr.h"

int **init_array(int **pointer,int rows,int cols){
    pointer = (int**)malloc(sizeof(int*)*rows);
    for(int i = 0;i<rows;i++){
        pointer[i] = (int*)malloc(sizeof(int)*cols);
    }
    srand(pointer[0][0]);
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pointer[i][j] = rand()%10;
        }
    }
    return pointer;
}


int **add_column(int **pointer,int rows,int *cols){
    (*cols)++;
    for(int i = 0;i<rows;i++){
        pointer[i] = (int*)realloc(pointer[i],sizeof(int*)*(*cols));
    }
    for(int i = 0;i<rows;i++){
        pointer[i][(*cols)-1] = rand() %10;
    }
    return pointer;
}
int **delete_array(int **pointer,int *rows,int *cols){
    for(int i = 0;i<(*rows);i++){
        free(pointer[i]);
        pointer[i] = NULL;
    }
    free(pointer);
    pointer = NULL;
    (*rows) = (*cols) = 0;
    return pointer;
}

int **delete_column(int **pointer,int pos,int rows,int *cols){
    int flag = 0;
    (*cols)--;
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<(*cols);j++){
            if(j == pos){
                flag =1;
            }
            if(flag == 0){
                pointer[i][j] = pointer[i][j];
            }else{
                pointer[i][j] = pointer[i][j+1];
            }
            
        }
        flag = 0;
    }
    for(int i = 0;i<rows;i++){
        pointer[i] = (int*)realloc(pointer[i],(*cols)*sizeof(int));
    }
    return pointer;
}

int **shift_array(int **pointer,int to,char type,int rows,int cols){
    int buffer;
    for (int z = 0; z < to; z++) {
        switch (type) {
            case 'L':
                for (int i = 0; i < rows; i++) {
                    buffer = pointer[i][0];
                    for (int j = 0; j < cols - 1; j++) {
                        pointer[i][j] = pointer[i][j + 1];
                    }
                    pointer[i][cols - 1] = buffer;
                }
            break;

        case 'R':
            for (int i = 0; i < rows; i++) {
                buffer = pointer[i][cols - 1];
                for (int j = cols - 1; j > 0; j--) {
                    pointer[i][j] = pointer[i][j - 1];
                }
                pointer[i][0] = buffer;
            }
            
            break;
        default:break;
        }
    }
    return pointer;
}