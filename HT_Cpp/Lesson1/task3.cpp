#include "..\Lesson1\header_file.h"
int main(){
    //------------------------------------------------------task3
    cout<<"\033[91m please use CMD to run this CPP file \n";
    cout<<"\033[93m -------------TASK3---------- \n";
    uint64_t length = 0;
    uint64_t seconds = 0;
    uint64_t minutes = 0;
    float time = 0.00;
    double velocity = 0.00;
    double hours = 0.00;

    cout<<"Enter run distance(meters):";
    cin>>length;
    cout<<"Enter runner time(min.sec):";
    cin>>time;

    minutes = time;
    seconds = (time - minutes)*100+minutes*60;
    hours = (float)seconds/3600; // без (float) не працює
    velocity = (length/1000)/hours;

    cout<<"\033[92m"<<length;
    cout<<"time(sec) = "<<minutes<<"min "<<seconds%60<<"sec = "<<seconds;
    cout<<"\n\033[96mVelocity = "<<velocity<<"km/hour"<<'\n';
    delete &length,&seconds,&minutes,&time,&velocity,&hours;
}