#include<iostream>
#include<stdlib.h>
using namespace std;
void random(int *array,int size){
    for(int i = 0;i<size;i++){
        array[i] = rand()%10+10;
    }
    
}
void concat(int* arr1, int* arr2, int* arr_out, int size1, int size2) {
    for (int i = 0; i < size1;i++) {
        arr_out[i] = arr1[i];
    }
    for (int i = 0; i < size2; i++) {
        arr_out[size1 + i] = arr2[i];
    }
}

int main(){
    int m;
    int n;
    cin>>m>>n;
    int *pointer = new int[m];
    int *second_pointer = new int[n];
    random(pointer,m);
    random(second_pointer,n);
    int *third_pointer = new int[m+n];
    concat(pointer,second_pointer,third_pointer,m,n);
    for(int i = 0;i<m+n;i++){
        cout<<*(third_pointer+i)<<" ";
    }
    delete []pointer;
    delete []second_pointer ;
    delete []third_pointer;
}