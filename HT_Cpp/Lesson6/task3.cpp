#include "header_file.h"

bool is_super(int number){
    int sum = 0;
    for(int i = 1;i<number;i++){
        if(number%i == 0){
            sum+=i;
        }
    }
    return (number == sum);
}
void find_super_diapason(int from, int to){
    for(int i = from;i<=to;i++){
        if(is_super(i)==1){
            cout<<i<<" ";
        }
    }
}
int main(){
    int from = 0;
    int to = 0;
    cout<<basic<<"enter diapason from to"<<end;
    cin>>from>>to;
    cout<<"perfect numbers in diapason from "<<from<<" to "<<to<<" are: ";
    find_super_diapason(from,to);
}