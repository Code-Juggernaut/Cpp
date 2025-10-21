#include "header_file.h"
int main(){
    string number;
    
    long long int sum = 0;
    cout<<defcolor<<"---TASK5---\n"<<"Enter number:";
    cin>>number;
    int num;
    
    int start = (number[0] == '-') ? 1 : 0;//chatgpt fix
    for(int i = start; i < number.size(); i++){ // chatgpt fix
        sum += number[i] - '0';
    }
    cout<<sum;
    num = stoi(number);
    
    if((sum*sum*sum) == num*num){
        cout<<ok<<"Yes";
    }else{
        cout<<error<<"No";
    }
    
}