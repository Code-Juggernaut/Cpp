#include<iostream>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
using namespace std;

class Exception:public exception{
    private:
        string  message;
        bool flag = 0;
    public:

    Exception(string num){
        char *buffer;
        double number = strtod(num.c_str(),&buffer);
        for(int i = 0;i<num.size();i++){
            if(buffer[i]<'0'|| buffer[i]>'9'){
                if(buffer[i] != '.'){
                    message = "Contains chars";
                    flag = 1;
                    break; 
                }
                
            }
        }
        if(number<-1 || number>1){
            message = "Out of bounds";
            flag = 1;
        }
        if(flag == 0){
            message = "ALL IS OK";
        }
    }
    const char *what()const noexcept{
        return message.c_str();
    }
};

int main(){
    string num;
    getline(cin,num);
    try{
        
        throw Exception(num);
        
    }
    catch(const Exception &error){
        cout<<error.what();
    }
}