#include<iostream>
#include<ctime>
#include<stdlib.h>

#define array_size 4
using namespace std;

void create_array(int *array){
    srand(time(NULL));
    for(int i = 0;i<array_size;i++){
        *(array+i) = rand()%10;
    }
}
void reverse(int *array){
    int *buff = new int[array_size];
    for(int i = array_size-1;i>=0;i--){
        buff[array_size-i-1] = array[i];
    }
    for(int i = 0;i<array_size;i++){
        array[i] = buff[i];
    }
}
void print(int *array){
    for(int i = 0;i<array_size;i++){
        cout<<*(array+i)<<" ";
    }
    cout<<'\n';
}
int main(){
    int *pointer = new int[array_size];
    create_array(pointer);
    print(pointer);
    reverse(pointer);
    print(pointer);
    delete pointer;
}