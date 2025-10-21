#include "header_file.h"

long long int calc_fab(float number,float step){
    long long int fabs = number;
    while(step>1){
        fabs *=number;
        step--;
    }   
    return fabs;
}

int main(){
    float number = 0;
    float step = 0;
    cout<<basic<<"--- fabs calculator ---"<<end;
    cout<<"enter number:"<<input;
    cin>>number;
    cout<<basic<<"enter step:"<<input;
    cin>>step;
    cout<<out<<number<<'^'<<step<<'='<<ok<<calc_fab(number,step);
}