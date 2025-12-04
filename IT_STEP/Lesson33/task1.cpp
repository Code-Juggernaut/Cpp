#include<iostream>

using namespace std;

class Base{
    private:
            char *base_data;
    public:
        Base(){
            base_data = new char[100];
            cout<<"created!"<<endl;
        }

        virtual ~Base(){
            delete[] base_data;
            cout<<"deleted!"<<endl;
        }
};
class Derive: public Base{
    private:
        char *derive_data;
    public:
        Derive(){
            derive_data = new char[100];
            cout<<"created!"<<endl;
        }

        ~Derive(){
            delete[] derive_data;
            cout<<"deleted!"<<endl;
        }
};
class NEW: public Derive{
    private:
        char *new_data;
    public:
        NEW(){
            new_data = new char[100];
            cout<<"created!"<<endl;
        }

        ~NEW(){
            delete[] new_data;
            cout<<"deleted!"<<endl;
        }
};
int main(){
    {
    Derive obj1;
    };
    cout<<"=========="<<endl;
    Derive *ptr = new Derive();
    delete ptr;
    ptr = NULL;
    cout<<"----------"<<endl;
    Base  *pbase = new Derive;
    delete pbase;
    cout<<"++++++++++"<<endl;
    Base *ptrnew = new NEW;
    delete ptrnew;
    cout<<"===---==="<<endl;
    Derive *ptrnew1 = new NEW;
    delete ptrnew1;
    cout<<"===+++==="<<endl;
    
}