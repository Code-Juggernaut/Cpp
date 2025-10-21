#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
    int size = 4;
    int array[size];
    int *pointer = array;
    for(int i = 0;i<size;i++){
        *(pointer+i) = rand()%100;
    }
    for(int i = 0;i<size;i++){
        if(i%2 == 0){
            cout<<*(pointer+i)<<" ";
        }
    }
}