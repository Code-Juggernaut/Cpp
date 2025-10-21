#include"lib.h"

void ticket(int val,char category,int buf[3]){
    if(val>3){
        cout<<error<<"film not found";
        return;
    }
    switch(category){
        case 'a':cout<<ok<<"\nprice on this film = "<<buf[val-1];break;
        case 'b':cout<<ok<<"\nprice on this film = "<<buf[val-1];break;
        case 'c':cout<<ok<<"\nprice on this film = "<<buf[val-1];break;
        default:cout<<error<<"\nfilm category not found";
    }
    cout<<"UAH";
}
int main(){
    start:
    int age = 0;
    int amount = 0;
    cout<<defcolor<<"------cinema counter------\n"<<"enter amount of visitors:";
    cin>>amount;

    for(int i = 0;i<amount;i++){
        
        cout<<message<<"enter guest age:";
        cin>>age;
        if(age>3 && age<=10){
            cout<<ok<<"harry potter(1) "<<"Chip and Dail(2) "<<"Tom and Jerry(3) ";
            int val = 0;
            cin>>val;
            int price[3] = {300,500,100};
            ticket(val,'a',price);
        } else if(age >=11 && age <=17){
            cout<<defcolor<<"Men in black(1) "<<"Deadpool(2) "<<" Strange villgae(3)";
            int val = 0;
            cin>>val;
            int price[3] = {1000,200,100};
            ticket(val,'b',price);
        }else if(age >=18 && age<=100){
            cout<<error<<"Librarian(1) "<<"Houso(2) "<<"Ring(3) ";
            int val = 0;
            cin>>val;
            int price[3] = {1000,600,9000};
            ticket(val,'c',price);
            
        }else{
            cout<<"no films are available for your preage category";
        }
        cout<<'\n';
    }
    goto start;
}