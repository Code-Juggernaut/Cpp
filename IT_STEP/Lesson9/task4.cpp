#include<iostream>
using namespace std;
void increment(int &val){
    val++;
}
int& max_overload(int *arr,int size){
    
    int max_index = 0;
    for(int i = 0;i<size;i++){
        if(max_index<arr[i]){
            max_index = i;
        }
    }
    return arr[max_index];
}
int main(){
    int arr[5] = {4,5,2,1,5};
    int& maxval = max_overload(arr,5);
    increment(maxval);
    cout<<maxval;

}