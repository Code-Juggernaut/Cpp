#include "..\Lesson1\header_file.h" //мені лінь писати #include кожен раз тому все в header_file
int main(){
    //----------------------------------------------------------------task1
    uint64_t seconds_input = 0;
    uint64_t hours  =0,minutes= 0,seconds  =0;
    cout<<"\033[91m please use CMD to run this CPP file \n \033[93m -------------TASK1---------- \n";
    cout<<"Enter seconds:";
    cin>>seconds_input;
    cout<<'\n';

    hours = seconds_input / 3600;
    minutes = (seconds_input %3600) /60;
    seconds = (seconds_input%3600)%60;
    cout<<"\033[92mHours: "<<hours<<"h"<<'\n'<<"minutes: "<<minutes<<"min"<<'\n'<<"Seconds: "<<" "<< seconds<<"s";
    delete &hours,&minutes,&seconds,&seconds_input; //що значить &?
}