#include<iostream>
#include<stdint.h>
using namespace std;
int main(){
    char password[10];

    uint8_t attempt = 3;

    for(int i = 0;i<10;i++){
        char symbol;
        cin>>symbol;
        if(symbol == '\0'){
            break;
        }else{
            password[i] =symbol;
        }
    }

    cout<<"password saved";

    for(uint8_t i = 0;i<3;i++){
        char buff[10];
        for(int i = 0;i<10;i++){
            char symbol;
            cin>>symbol;
            if(symbol == '\n'){
                break;
            }else{
                buff[i]=symbol;
            }
        }
        bool flag = 0;
        for(int i = 0;i<10;i++){
            if(buff[i] == password[i]){
                flag = 1;
                
            }else{
                flag =0;
                cout<<"wrong";
                break;
            }
        }
        if(flag == 1){
            cout<<"accepted";
            return 0;
        }
            
            
        
    }
}