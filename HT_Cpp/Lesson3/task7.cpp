#include "header_file.h"
int main(){
    int number1 = 0;
    int number2 = 0;
    int limits = 0;
    cout<<defcolor<<"---TASK7---\n";
    cout<<"Enter numbers";
    cin>>number1>>number2;
    if(number1>number2){
        limits = number1;
    }else{
        limits = number2;
    }
    cout<<"number1%i = 0 and number2%i = 0 if i = "<<outcolor;
    for(int i = 1;i<=fabs(limits);i++){
        if(number1%i == 0 && number2%i == 0){
            cout<<i<<" ";
            cout<<-i<<" ";
        }
    }
}