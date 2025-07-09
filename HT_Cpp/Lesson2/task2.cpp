#include<iostream>
using namespace std;
const int basic_salary = 200;
double salary(double sale_precent,float sale,bool is_best){

    if(is_best){
        return basic_salary+(sale*(sale_precent/100.0))+basic_salary;
    }else{
        return basic_salary+(sale*(sale_precent/100.0));
    }
}
int main(){
    float managers[3] = {0,0,0};
    float sales[3] = {0,0,0};
    float max = 0;
    for(int i = 0;i<3;i++){
        cin>>sales[i];
        if(sales[i]>max){
            max = sales[i];
        }
    }
    for(int i = 0;i<3;i++){
        if(sales[i]<500){
            if(sales[i] == max){
                managers[i] = salary(3.0,sales[i],1);
            }else{
                managers[i] = salary(3.0,sales[i],0);
            }
        }else if(sales[i]>=500 && sales[i]<1000){
            if(sales[i] == max){
                managers[i] = salary(5.0,sales[i],1);
            }else{
                managers[i] = salary(5.0,sales[i],0);
            }
        }else{
            if(sales[i] == max){
                managers[i] = salary(8.0,sales[i],1);
            }else{
                managers[i] = salary(8.0,sales[i],0);
            }
        }
    }

    for(int i = 0;i<3;i++){
        cout<<managers[i]<<'\n';
    }
}