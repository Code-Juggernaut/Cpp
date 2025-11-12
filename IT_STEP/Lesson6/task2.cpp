#include<iostream>
using namespace std;

void function(int width,int height){
    for(int i = 0 ;i<width;i++){
        for(int j = 0 ;j<height;j++){
            cout<<".";
        }
        cout<<"\n";
    }
}

int main(){
    cout<<"\033[93m";
    function(3,7);
}