#include"lib.h"
long int function(int froml, int toh){
    long int sum = 0;
    for(int i = froml;i<=toh;i++){
        sum+=i;
    }
    return sum;    
}
int main(){
    int from= 0,to = 0;
    cout<<message<<"enter from and to ";
    cin>>from>>to;
    long int sum = 0;
    if(from>to){
        sum  = function(to,from);
    }else{
        sum = function(from,to);
    }
    cout<<outcolor<<sum<<defcolor;
}