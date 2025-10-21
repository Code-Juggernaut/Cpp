#include<iostream>
using namespace std;
void find_max(float array[],int size){
    int max = 0;
    int pos_max = 0;
    int pos_min = 0;
    int min = array[0];
    for(int i = 0;i<size;i++){
        if(array[i]>max){
            pos_max = i;
            max = array[i];
        }
        if(array[i]<min){
            pos_min = i;
            min = array[i];
        }
    }
    cout<<"Maximum = "<<max<<" position: "<<pos_max<<"\n";
    cout<<"Minimum = "<<min<<" position: "<<pos_min<<"\n";
}
int main(){
    float array_num[6] = {0,324,-43861,45,252,2453};
    find_max(array_num,6);
}