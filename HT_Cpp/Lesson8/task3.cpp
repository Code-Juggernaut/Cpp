#include<iostream>
#include<stdlib.h>
#include<ctime>
#define array_size 4
using namespace std;
void create_array(int *array){
    srand(time(NULL));
    for(int i = 0;i<array_size;i++){
        *(array+i) = rand()%10;
    }
}
void copy_reverse(int *array_from,int *array_to){
    for(int i  = 0;i<array_size;i++){
        *(array_to +(array_size-i-1)) = *(array_from+i);
    }
}
void print(int *array){
    for(int i = 0;i<array_size;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<'\n';
}
int main(){
    int *pointer_to_arr1 = new int[array_size];
    int *pointer_to_arr2 = new int[array_size];
    create_array(pointer_to_arr1);
    copy_reverse(pointer_to_arr1,pointer_to_arr2);
    cout<<"array from copy: ";
    print(pointer_to_arr1);
    cout<<"array to copy:   ";
    print(pointer_to_arr2);
}