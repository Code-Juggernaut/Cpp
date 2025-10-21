#include "header_file.h"
int main(){
    string number;
    cout<<defcolor<<"---- number 3 and 6 remover ----\n";
    cout<<"enter number :";
    cin>>number;
    for(int i = 0;i<number.size();i++){
        if(number[i] == '3' || number[i] == '6'){
            number[i] = '\0';
        }
    }
    cout<<"formatted number = "<<message<<number;
}