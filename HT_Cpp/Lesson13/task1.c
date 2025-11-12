#include<stdlib.h>
#include<stdio.h>
#include<string.h>
void stringsort(char **array,int rows,int cols){

    int flag = 0;
    char *buffer = (char*)malloc(cols*sizeof(char));
    while(flag  == 0){
        flag = 1;
        for(int i = 0;i<rows-1;i++){
            if(strcmp(array[i],array[i+1])>0){
                flag = 0;
                strcpy(buffer,array[i]);
                strcpy(array[i],array[i+1]);
                strcpy(array[i+1],buffer);
            }
        }
    }
    free(buffer);
}

char **initarray(char **pointer,int rows,int cols){
    pointer = (char**)malloc(sizeof(char*)*rows);
    for(int i = 0;i<rows;i++){
        pointer[i] = (char*)malloc(sizeof(char)*cols);
    }
    return pointer;
}

char **freearray(char **pointer,int rows,int cols){
    for(int i = 0;i<rows;i++){
        free(pointer[i]);
    }
    free(pointer);
    return NULL;
}

char **addrow(char **pointer,int *rows,int cols){
    (*rows)++;
    pointer = (char**)realloc(pointer,(*rows)*sizeof(char*));
    
    pointer[(*rows)-1]= (char*)malloc(cols*sizeof(char));
    
    return pointer;
}

char **addcolumn(char **pointer,int rows,int *cols){
    (*cols)++;
    for(int i = 0;i<rows;i++){
        pointer[i] = (char*)realloc(pointer[i],(*cols)*sizeof(char));
    }
    return pointer;
}

int main(){
    char **pointer = NULL;
    int rows = 5;
    int cols = 10;
    pointer = initarray(pointer,5,10);
    for(int i =0 ;i<rows;i++){
        scanf("%s",pointer[i]);
    }
    stringsort(pointer,rows,cols);
    printf("\n");
    for(int i =0 ;i<rows;i++){
        printf("%s",pointer[i]);
        printf("\n");
    }
    pointer = freearray(pointer,rows,cols);
}