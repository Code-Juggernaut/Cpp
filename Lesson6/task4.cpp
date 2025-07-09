#include<iostream>
using namespace std;
bool is_above_zero(float number){
    if(number>0.0){
        return 1;
    }else{
        return 0;
    }
}
int main(){
    float num = 0;
    cout<<"Enter num";
    cin>>num;

    if(is_above_zero(num) == 1){
            cout<<num<<" \033[92mis >0";
    }else{
        cout<<num<<" \033[91mis <0";
    }
}