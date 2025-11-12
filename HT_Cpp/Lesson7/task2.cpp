#include "header_file.h"
int recurs(int number1, int number2){
    int ost = number1%number2;
    if(ost == 0){
        return number2;
    }
    return recurs(number2,ost);
}
int main(){
    int number1 = 0;
    int number2 = 0;
    cout<<basic<<"enter two numbers:";
    cin>>number1>>number2;
    cout<<end<<"NSD = "<<recurs(number1,number2);
}