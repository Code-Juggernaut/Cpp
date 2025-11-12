#include "..\Lesson1\header_file.h"
int main(){
     //------------------------------------------------------------------task4
    cout<<"\033[91m please use CMD to run this CPP file \n";
    cout<<"\033[93m -------------TASK4---------- \n";
    uint64_t days = 0;
    uint64_t weeks = 0;
    char word[10];
    cout<<"Enter type of calc(vacation, trip, etc.)";
    cin>>word;
    cout<<"Enter amount of days: ";
    cin>>days;
    weeks = days/7;
    days = days%7;
    cout<<"to the end of your "<<word<<" you have"<<"\033[94m weeks:"<<weeks<<"\033[92m days:"<<days;
}