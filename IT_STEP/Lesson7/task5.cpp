#include<iostream>
#include<stdlib.h>
using namespace std;
#define ARR_SIZE 4
template <typename templ> templ average(templ buff[],int size){
    float average;
    for(int i = 0;i<size;i++){
        average+=buff[i];
    }
    return average/=size;
}


int main(){
    float arr[ARR_SIZE] = {12.8,34,12.25,4};
    double arr2[ARR_SIZE] = {14436.543,24.5653,347.5643,63245};
    cout<<average(arr,ARR_SIZE);
}