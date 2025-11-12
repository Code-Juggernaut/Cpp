#include<iostream>
#include<string.h>

using namespace std;

class Airplane{
    private:
        string type;
        int passager;
        int max;
    public:
        Airplane(int pass,string name):passager(pass),type(name){
            max = passager;
        }
        class Airplane operator++(){
            ++passager;
            max = passager;
            return *this;
        }
        class Airplane operator--(){
            --passager;
            return *this;
        }
        bool operator==(class Airplane other){
            if(this->type == other.type){
                return 1;
            }
            return 0;
        }

        bool operator<(class Airplane *other){
            if(this->max<other->max){
                return 1;
            }
            return 0;
        }
        void print(){
            cout<<type<<endl<<"passagers: "<<passager<<endl<<"max pass:"<<max<<endl;
        }
};

int main(){
    class Airplane obj1(100,"Boeing747");
    class Airplane obj2(50,"Airbus A305");
    ++obj1;
    obj1.print();
    --obj2;
    obj2.print();

    cout<<((obj1 < &obj2)?("max obj2"):("max obj1"))<<endl;
    cout<<((obj1 == obj2)?("same name"):("differ name"))<<endl;
}