#include "header_file.h"
int main(){
    int number = 0;
    
    cout<<defcolor<<"---TASK4---\n"<<"enter number";
    cin>>number;
    cout<<"numbers = "<<outcolor;

    int limits = sqrt(fabs(number))+1;

    for(int i = 1;i<=limits;i++){
        if(number%(i*i) == 0 && number%(i*i*i) != 0){
            cout<<i<<" ";
            cout<<-i<<" ";
        }
    }
}