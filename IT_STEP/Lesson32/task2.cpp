#include<iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

class Passport{
    private:
        string _name;
        string _surname;
        char _ID[10];
        string _date;
    protected:
        Passport(const string &date,const string &name
            ,const string &surname):_name(name),_surname(surname),_date(date){
                sscanf(_ID,"%lld",rand());
            }

    public:
        string getname()const{
            return _name;
        }
        string getsurname()const{
            return _surname;
        }
        string getID()const{
            return _ID;
        }
        void print()const{
            cout<<"name: "<<_name<<endl;
            cout<<"surname: "<<_surname<<endl;
            cout<<"date: "<<_date<<endl;

            cout<<"ID: ";
            for(int i = 0;i<sizeof(_ID);i++){
                cout<<(int)_ID[i];
            }
            cout<<endl;
        }

};
class Foregin:public Passport{
    private:
    string _visa;
    char _ID[10];
    public:
    Foregin(const string &date,const string &name,
        const string &surname,const string &visa):
        Passport(date,name,surname),_visa(visa){
        sscanf(_ID,"%lld",rand());
    }
    string getvisa()const {
        return _visa;
    }
    void printID()const{
        cout<<"ID: ";
        for(int i = 0;i<sizeof(_ID);i++){
            cout<<(int)_ID[i];
        }
    }
    void PrintALL()const{
        Passport::print();
        cout<<"visa: "<<_visa<<endl;
        printID();
    }
};
int main(){
    Foregin classic("18.12.1942","Mark","Twen","NAN");
    classic.PrintALL();
}