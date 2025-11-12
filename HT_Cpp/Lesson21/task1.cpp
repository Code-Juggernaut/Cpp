#include<iostream>
using namespace std;

class Divider{
    private:
        float divider;
        float dividee;
    public:
        void init(){
            
            cout<<"enter divider:";
            cin>>divider;
            cout<<"enter dividee:";
            cin>>dividee;
        }

        void print(){
            cout<<dividee <<"/"<<divider<<endl;
        }
        void plus(){
            float number;
            cout<<"add:"<<endl;
            cout<<"enter number:";
            cin>>number;
            dividee+= divider*number;
        }
        void minus(){
            float number;
            cout<<"Subtract:"<<endl;
            cout<<"enter number:";
            cin>>number;
            dividee-= divider*number;
        }
        void multiply(){
            float number;
            cout<<"Multiply:"<<endl;
            cout<<"enter number:";
            cin>>number;
            dividee*=number;
        }
        void divide(){
            float number;
            cout<<"Divide:"<<endl;
            cout<<"enter number:";
            cin>>number;
            if(number !=0.0){
                dividee/= number;
            }else{
                cout<<"DIV ON ZERO!!!"<<endl;
            }
        }
};
int main(){
    Divider div;
    div.init();
    div.plus();
    div.print();
    div.minus();
    div.print();
    div.multiply();
    div.print();
    div.divide();
    div.print();
}