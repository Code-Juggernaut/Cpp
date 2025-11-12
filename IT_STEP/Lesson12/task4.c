#include<stdio.h>
#include<stdlib.h>

int **add_array_to_begin(int **previous_array,int rows,int colums,int *array){
    int **new_array = (int**)malloc((rows+1)*sizeof(int*));


    for(int i = 0;i<rows;i++){
        new_array[i+1] = (int*)malloc(colums*sizeof(int));
        for(int j = 0;j<colums;j++){
            new_array[i+1][j] = previous_array[i][j];
        }
    }
    new_array[0] = (int*)malloc(colums*sizeof(int));
    for(int i =0;i<colums;i++){
        new_array[0][i] = array[i];
    }
    for (int i = 0; i < rows; i++) {
        free(previous_array[i]);
    }
    free(previous_array);

    return new_array;
}
int main() {
    int rows = 2, cols = 3;
    int **array = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            array[i][j] = i + 1;
        }
    }

    int new_row[3] = {0, 0, 0};
    array = add_array_to_begin(array, rows, cols, new_row);
    rows++;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}