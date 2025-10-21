#include<iostream>
using namespace std;
float calc(float buf[3]){
    float sum = 0;
    sum = buf[0]+buf[1]+buf[2];
    return sum;
}
float mult(float buf[3]){
    float mult = 0;
    mult = buf[0]*buf[1]*buf[2];
    return mult;
}
int main(){
    float nums[3] = {0,0,0};
    float minus[3] = {0,0,0};
    float neutral[3] = {0,0,0};
    float positive[3] = {0,0,0};
    int flag = 5;
    cout<<"\033[93m Enter 3 nums";
    
    for(int i = 0;i<3;i++){
        cin>>nums[i];
    }
    for(int i = 0;i<3;i++){
        if(nums[i]<=0){
            minus[i] = nums[i];
        }
        if(nums[i] == 0.0){
            neutral[i] = nums[i];
        }
        if(nums[i] >= 0){
            positive[i] = nums[i];
        }
    }
    cout<<"negsum = "<<calc(positive)<<'\n';
    cout<<"possum = "<<calc(minus)<<'\n';
    cout<<"posmult = "<<mult(positive)<<'\n';
    cout<<"negmult = "<<mult(minus)<<'\n';
}