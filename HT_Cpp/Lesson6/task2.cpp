#include "header_file.h"
long int sum_in_range(int from,int to){
    long int sum = 0;
    if(from>to){
        int buff = to;
        to = from;
        from = buff;
    }else{
        //ignore
    }
    for(int i = from;i<=to;i++){
        sum+=i;
    }
    return sum;
}
int main(){
    int from,to;
    cout<<basic<<"Enter start point:"<<input;
    cin>>from;
    cout<<basic<<"Enter end point:"<<input;
    cin>>to;
    cout<<out<<"sum "<<from<<" to "<<to<<" = "<<basic<<sum_in_range(from,to);

}