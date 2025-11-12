#ifndef dynamic_arr_H
#define dynamic_arr_H

#include<stdlib.h>
int **init_array(int **pointer,int rows,int cols);
int **add_column(int **pointer,int rows,int *cols);
int **delete_array(int **pointer,int *rows,int *cols);
int **delete_column(int **pointer,int pos,int rows,int *cols);
int **shift_array(int **pointer,int to,char type,int rows,int cols);
#endif