#include<iostream>
using namespace std;
void newline(){
    for(int i = 0;i<9;i++){
        cout<<'\n';
    }
}
int main(){
    cout<<"\033[93m\"Hello world!\"\n";
    cout<<"\033[90m/Bjane Straustrup/";
    newline();
    cout<<"\033[90m Hello world!\n \\\\Denis Richi\\\\";
}