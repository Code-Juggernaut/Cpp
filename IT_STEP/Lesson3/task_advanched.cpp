#include"lib.h"
int main(){
    int weight = 10000;
    int prod = 5;
    int counter = 0;
    for(int i = weight;i>0;i-=prod){
        counter++;
    }
    cout<<message<<"amount = "<<outcolor<<counter<<defcolor;
}