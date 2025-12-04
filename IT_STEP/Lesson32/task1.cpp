#include<iostream>
#include<string.h>

using namespace std;

class Employee{
    private:
        string _name;
    protected:
        Employee(const string &name):_name(name){
            cout<<"created! EP";
        }
    public:
        string getname() const{
            return _name;
        }
        ~Employee(){
            cout<<"fired!";
        }
};
enum Programming_lang{
    Cpp,Cs,Python,C
};
class Programmer:public Employee{
    private:
        Programming_lang _lang;
    public:
        Programmer(const string name,Programming_lang lang):
        Employee(name),_lang(lang){
            cout<<"created! PG";
        }
        Programming_lang getlang(){
            return _lang;
        }
        ~Programmer(){
            cout<<Employee::getname()<<" ";
        }
};

int main(){
    Programmer pg("Bill Gates",C);
    Programmer pt("Gvido Van Rossum",Python);

    cout<<pg.getname()<<" studied "<<pg.getlang()<<endl;
    cout<<pt.getname()<<" studied "<<pt.getlang()<<endl;

    Employee *worker = &pg;
    worker->getname();
    Employee worker2 = pt;
}