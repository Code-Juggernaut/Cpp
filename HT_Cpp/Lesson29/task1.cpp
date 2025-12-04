#include<iostream>
#include<stack>
#include<string.h>
/**
 * NOTE:
 * using STL stack
 * 
 * P.S It's much easier to do via stl::stack
 * No need to write your own libs &classes and no need
 * to reinvent wheel
 */
using namespace std;

int main(){
    string data;
    getline(cin,data);
    stack<char> fifo;
    stack<int> buffer;
    int counter = 0;
    bool flag = 0;
    for(char i:data){
        if(!fifo.empty() &&(i == ')'&& fifo.top() =='(' ||i == ']'&& fifo.top() =='[' ||
    i == '}'&& fifo.top() =='{')){
            fifo.pop();
            //buffer.pop();
        }else{
            if(i == '(' || i == '[' || i == '{'){
                fifo.push(i);
                buffer.push(counter);
            }
            if(i == ')' || i == ']' || i == '}'){
                flag = 1;
            }
        }
        if(flag == 0){
            ++counter;
        }
        
    }
    if(fifo.empty()){
        cout<<"PASS";
    }else{
        cout<<"FAIL";
        cout<<" problem at :"<<buffer.top();
    }
}