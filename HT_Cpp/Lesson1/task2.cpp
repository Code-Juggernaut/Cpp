#include "..\Lesson1\header_file.h"
int main(){
    //------------------------------------------------------------------------------------task2
    
    float input_number = 0.00;
    char currency[3];
    cout<<"\033[91m please use CMD to run this CPP file \n";
    cout<<"\033[93m -------------TASK2---------- \n";

    cout<<"Enter number(float point):";
    cin>>input_number;

    cout<<"Enter currency name(EX: UAH, USD etc)";
    cin>>currency;

    uint64_t round = 0;
    uint64_t dec = 0;

    round = input_number;

    dec = (input_number-round)*100;
    cout<<"\033[92m\n"<<round<<" "<<currency<<'\n';
    
    cout<<" 1/100 "<<currency<<'='<<dec<<'\n';
    delete &input_number,&currency,&round,&dec;
}