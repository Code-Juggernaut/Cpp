#include<iostream>

using namespace std;

class Divider{
    private:
        float divider;
        float dividee;
    public:
        Divider(){
        };
        Divider(float _d,float _e):divider(_d),dividee(_e){
        };
        void init(){  
            cout<<"enter divider:";
            cin>>divider;
            cout<<"enter dividee:";
            cin>>dividee;
        }
        class Divider operator+(class Divider &other){
            return Divider(divider,(dividee+divider*other.divider));
        }
        class Divider operator-(class Divider &other){
            return Divider(dividee- divider*other.dividee,divider*other.divider);
        }
        class Divider operator*(class Divider &other){
            return Divider(dividee*other.dividee,divider);
        }
        class Divider operator/(const Divider& other) const {
            if (other.dividee != 0.0f) {
                return Divider(divider * other.divider, dividee * other.dividee);
            } 
            cout << "DIV ON ZERO!!!" << endl;
            return *this;
        }

        Divider& operator=(const Divider& other) {

        if (this != &other) {
            divider = other.divider;
            dividee = other.dividee;
        }
            return *this;
        }

        void print(){
            cout<<dividee<<"/"<<divider;
        }
    };
int main(){
    class Divider object1(10,20);
    class Divider object2(40,80);
    class Divider result;
    result = object1/object2;
    cout<<"object1/object2 = ";
    object1.print();
    cout<<" / ";
    object2.print();
    cout<<" = ";
    result.print();
    cout<<endl;

    result = object1+object2;
    cout<<"object1+object2 = ";
    object1.print();
    cout<<" + ";
    object2.print();
    cout<<" = ";
    result.print();
    cout<<endl;

    result = object1-object2;
    cout<<"object1-object2 = ";
    object1.print();
    cout<<" - ";
    object2.print();
    cout<<" = ";
    result.print();
    cout<<endl;

    result = object1*object2;
    cout<<"object1*object2 = ";
    object1.print();
    cout<<" * ";
    object2.print();
    cout<<" = ";
    result.print();
    cout<<endl;
}